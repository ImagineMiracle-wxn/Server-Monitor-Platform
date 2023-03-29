#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <error.h>
#include <errno.h>

#define TCP_IP4     ("10.1.3.120")
#define TCP_PORT    (21031)
#define DATA_LENGTH (1024)
#define TEMP_LENGTH (15)

#define GETTEMP_CMD	("sensors")
#define GETCORENUM_CMD	("grep 'core id' /proc/cpuinfo | sort -u | wc -l")
#define GETMEM_TOTAL_CMD	     ("cat /proc/meminfo | grep MemTotal")
#define GETMEM_AVAILABLE_CMD         ("cat /proc/meminfo | grep MemAvailable")

#define CORE_STR	("Core")

#define INITDATA_CMD	("initdata")
#define ACKDATA_CMD	("ackdata")

long unsigned int get_memsize(char * cmd)
{
        long unsigned int mem = 0;
        FILE * fp = NULL;
        char cmdout[DATA_LENGTH] = {0};

        printf("Get Mem Size.\n");

        fp = popen(cmd, "r");
        if (fp == NULL) {
                perror("popen error.\n");

                return -1;
        }

        while (fgets(cmdout, sizeof(cmdout), fp) != NULL) {
                printf("%s", cmdout);
        }
        pclose(fp);

        int m_s = 0, m_e = 0;

        for (int i = 8; i < strlen(cmdout); i++) {
                if (cmdout[i] == ' ' && (cmdout[i + 1] >= '0' && cmdout[i + 1] <= '9')) {
                        m_s = i + 1;
                        continue;
                }
                if (cmdout[i] == ' ' && (cmdout[i - 1] >= '0' && cmdout[i - 1] <= '9') && m_s > 0) {
                        m_e = i;
                        break;
                }
        }

        int i = 0;
        printf("%d:%d\n", m_s, m_e);
        for ( ; m_s < m_e; m_s++) {
                cmdout[i++] = cmdout[m_s];
        }
        cmdout[i] = '\0';

        printf("> %s\n", cmdout);

        for (i = 0; i < strlen(cmdout); i++) {
                mem *= 10;
                mem += (cmdout[i] - '0');
        }

        return mem;
}

int get_corenumber(void)
{
	int core_num = 0;
	FILE * fp = NULL;
	char cmdout[DATA_LENGTH] = {0};

	printf("Get CPU Core number.\n");

	fp = popen(GETCORENUM_CMD, "r");
	if (fp == NULL) {
		perror("popen error.\n");

		return -1;
	}

	while (fgets(cmdout, sizeof(cmdout), fp) != NULL) {
		printf("%s", cmdout);
	}
	pclose(fp);

	core_num = atoi(cmdout);

	printf("num:%d\n", core_num);

	return core_num;
}

char ** get_coretemp_fromcmdout(char * cmdout, char ** core_list, int core_num)
{
	int i = 0, t_s = 0, t_e = 0, list_num = 0;

	if (0 == strncmp(CORE_STR, cmdout, strlen(CORE_STR))) {
		for (i = 0; i < strlen(cmdout); i++) {
			if (cmdout[i] == ':') {
				i += 1;
				for ( ; i < strlen(cmdout); i++) {
					if (0 == t_s && cmdout[i] != ' ') {
						t_s = i + 1;
					}
					if (t_s && cmdout[i] == ' ') {
						t_e = i - 3;
						break;
					}
				}
				break;

			}
			continue;
		}

		// find the first null char*
		for (i = 0; i < core_num; i++) {
			if (0 == strlen(core_list[i])) {
				list_num = i;
				break;
			}
		}

		for (i = 0; t_s < t_e; i++) {
			core_list[list_num][i] = cmdout[t_s++];
		}
		core_list[list_num][i] = '\0';
	}

	return core_list;
}

char ** get_coretemp(char ** core_list, int num)
{
	char cmdout[DATA_LENGTH] = {0};
	FILE * fp = NULL;
	int core_num = num;
	printf("Core number: %d\n", core_num);

	printf("Get Temperature.\n");

	fp = popen(GETTEMP_CMD, "r");
	if (fp == NULL) {
		perror("popen error.\n");

		return NULL;
	}


	printf("core_list size: %d\n", sizeof(core_list[0]));
	int i = 0;

	while (fgets(cmdout, sizeof(cmdout), fp) != NULL) {
		printf("[%d]>%s", i++, cmdout);
		get_coretemp_fromcmdout(cmdout, core_list, core_num);
	}

	pclose(fp);

	printf("-----------------------------------\n");

	return core_list;
}

void clear_corelist_data(char ** core_list, int core_num)
{
	for (int i = 0; i < core_num; i++) {
		core_list[i][0] = '\0';
	}
}

void free_corelist(char ** core_list, int core_num)
{

	for (int i = 0; i < core_num; i++) {
		if (core_list[i] != NULL) {
			free(core_list[i]);
			core_list[i] = NULL;
		}
	}

	if (core_list != NULL) {
		free(core_list);
	}


	return ;
}

int main(int argc, const char * argv[])
{
    int ret = 0;
    int connect_fd = 0;
    long unsigned int memtotal = 0, memavailable = 0, memused = 0;
    double memused_rate = 0;
    int core_num = get_corenumber();
    char **core_list = (char **)malloc(core_num * sizeof(char *));
    memset(core_list, 0, core_num * sizeof(char *));

    for (int i = 0; i < core_num; i++) {
	    core_list[i] = (char *)malloc(sizeof(char) * TEMP_LENGTH);
    }
    core_list = get_coretemp(core_list, core_num);

    for (int i = 0; i < core_num; i++) {
	    printf("[%d]:%s\n", i, core_list[i]);
    }

    int socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("create socket error!");
        return -1;
    }

    printf ("Create socket successful!\n");

    // Bind
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = PF_INET;   // set protocol: Internet
    server_addr.sin_port = htons(TCP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(TCP_IP4);

    ret = bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (ret < 0) {
        perror("bind error!\n");
        close(socket_fd);

        return -1;
    }

    printf("Bind successful!\n");

    ret = listen(socket_fd, 1);
    if (ret < 0) {
        perror("listen error!\n");
        close(socket_fd);

        return -1;
    }

accept:
    while (1) {
	    printf("Linstening: \n");

	    // Accept
	    connect_fd = accept(socket_fd, NULL, NULL);
	    if (connect_fd < 0) {
		    perror("accept error!\n");
		    close(socket_fd);

		    return -1;
	    }

	    printf("Accept successful!\n");

	    // Recv
	    char buf[DATA_LENGTH] = {0};
	    /*
	       printf("Send: ");
	       scanf("%s", buf);
	       send(connect_fd, buf, strlen(buf), 0);
	       */

	    while (1) {

		    memtotal = get_memsize(GETMEM_TOTAL_CMD);
		    memavailable = get_memsize(GETMEM_AVAILABLE_CMD);
		    memused = memtotal - memavailable;
		    memused_rate = memused * 1000 / memtotal;
		    memused_rate /= 10;

		    ret = recv(connect_fd, buf, sizeof(buf), 0);
		    if (ret <= 0) {
			    perror("recv error!\n");

			    goto accept;
			    continue;
		    }

		    buf[ret] = '\0';
		    if (ret) {
			    printf("[%d]Recv: %s\n", ret, buf);
		    }

		    if (strcmp(buf, INITDATA_CMD) == 0) {
			    memset(buf, 0, sizeof(buf));
			    sprintf(buf, "%d\n%d\n", core_num, memtotal / 1024 / 1000);
			    ret = send(connect_fd, buf, strlen(buf), 0);
			    if (ret == -1) {
				    goto accept;
			    }
			    //sleep(1);
			    int t = 0;
			    // set core temp data
			    memset(buf, 0, sizeof(buf));
			    for (int i = 0; i < core_num; i++) {
				    for (int z = 0; z < strlen(core_list[i]); z++) {
					    buf[t++] = core_list[i][z];
				    }
				    buf[t++] = '\n';
				    //sprintf(buf, "%s\n", core_list[i]);
			    }
			    sprintf(buf, "%s%.2lf\n", buf, memused_rate);
			    send(connect_fd, buf, strlen(buf), MSG_NOSIGNAL);
			    if (ret == -1 && errno == EPIPE) {
				    goto accept;
			    }
			    continue;
		    }
		    if (strcmp(buf, "quit") == 0) {
			    break;
		    }
		    if (strcmp(buf, ACKDATA_CMD) == 0) {
			    printf("get new temp\n");
			    clear_corelist_data(core_list, core_num);
			    get_coretemp(core_list, core_num);
			    for (int i = 0; i < core_num; i++) {
				    printf("%s\n", core_list[i]);
			    }

			    int t = 0;
			    // 将每个核心温度值添加入 buf 中
			    memset(buf, 0, sizeof(buf));
			    for (int i = 0; i < core_num; i++) {
				    for (int z = 0; z < strlen(core_list[i]); z++) {
					    buf[t++] = core_list[i][z];
				    }
				    buf[t++] = '\n';
				    //sprintf(buf, "%s\n", core_list[i]);
			    }
			    // 在 buf 后添加内存使用率，单位 %
			    sprintf(buf, "%s%.2lf\n", buf, memused_rate);
			    // 通过 socket 发送
			    send(connect_fd, buf, strlen(buf), MSG_NOSIGNAL);
			    if (ret == -1 && errno == EPIPE) {
				    goto accept;
			    }

		    }
		    memset(buf, 0, sizeof(buf));

		    sleep(2);
		    continue;
	    }
    }

    close(connect_fd);
    close(socket_fd);

    free_corelist(core_list, core_num);

    return 0;

}
