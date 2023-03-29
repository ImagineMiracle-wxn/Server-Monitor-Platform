#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH	(1024)
#define GETTEMP_CMD	("sensors")
#define GETCORENUM_CMD	("grep 'core id' /proc/cpuinfo | sort -u | wc -l")

#define CORE_STR	("Core")

int get_corenumber(void)
{
	int number = 0;
	FILE * fp = NULL;
	char cmdlog[MAX_LENGTH] = {0};

	printf("Get CPU Core number.\n");
	
	fp = popen(GETCORENUM_CMD, "r");
	if (fp == NULL) {
		perror("popen error.\n");

		return -1;
	}

	while (fgets(cmdlog, sizeof(cmdlog), fp) != NULL) {
		printf("%s", cmdlog);
	}
	
	pclose(fp);

	number = atoi(cmdlog);

	return number;
}

char** get_coretemp(char * str, char ** core_list, int core_num)
{
	int i = 0, t_s = 0, t_e = 0, list_num = 0;
	if (0 == strncmp(CORE_STR, str, strlen(CORE_STR))) {
		for (i = 0; i < strlen(str); i++) {
			if (str[i] == ':') {
				i += 1;
				for( ; i < strlen(str); i++) {
					if (0 == t_s && str[i] != ' ') {
						t_s = i;
					}
					if (t_s && str[i] == ' ') {
						t_e = i;
						break;
					}
				}
				break;
			}
			continue;
		}

		for(i = 0; i < core_num; i++) {
			if (0 == strlen(core_list[i])) {
				list_num = i;
				break;
			}
		}


		for(i = 0; t_s < t_e; i++) {
			//str[i] = str[t_s++];
			core_list[list_num][i] = str[t_s++];
		}
		core_list[list_num][i] = '\0';
		printf("%s\n", core_list[list_num]);
	}


	return core_list;
}

int main(int argc, const char *argv[])
{
	char cmdlog[1024] = {0};
	FILE * fp = NULL;
	int core_num = get_corenumber();

	printf("Core number: %d\n", core_num);

	printf("Get Temperature.\n");

	fp = popen(GETTEMP_CMD, "r");
	if (fp == NULL) {
		perror("popen error.\n");

		return -1;
	}

	char **core_list = (char **)malloc(core_num * sizeof(char *));
	memset(core_list, 0, core_num * sizeof(char *));

	for(int i = 0; i < core_num; i++) {
		core_list[i] = (char *)malloc(sizeof(char) * 15);
	}

	int i = 0;
	while (fgets(cmdlog, sizeof(cmdlog), fp) != NULL) {
		printf("[%d]>%s", i++, cmdlog);
		get_coretemp(cmdlog, core_list, core_num);
	}

	pclose(fp);

	printf("---------------------------------\n");
	for (int i = 0; i < core_num; i++) {
		printf("[%d]: %s\n", i, core_list[i]);
	}

	for (int i = 0; i < core_num; i++) {
		if (core_list[i] != NULL) {
			free(core_list[i]);
			core_list[i] = NULL;
		}
	}

	if (core_list != NULL) {
		free(core_list);
	}

	//system("sensors");

	return 0;
}
