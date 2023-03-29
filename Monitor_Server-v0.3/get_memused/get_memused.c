#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH	(1024)
#define GETMEM_TOTAL_CMD	("cat /proc/meminfo | grep MemTotal")
#define GETMEM_FREE_CMD		("cat /proc/meminfo | grep MemAvailable")

long unsigned int get_memsize(char * cmd)
{
	long unsigned int mem = 0;
	FILE * fp = NULL;
	char cmdout[MAX_LENGTH] = {0};

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

int main (int argc, char * argv[])
{
	long unsigned int memtotal = get_memsize(GETMEM_TOTAL_CMD);
	long unsigned int memfree = get_memsize(GETMEM_FREE_CMD);
	printf(">> %ld\n", memtotal);
	printf(">> %ld\n", memfree);
	long unsigned int memused = memtotal - memfree;
	double used_rate = memused * 1000 / memtotal;
	used_rate /= 10;
	printf("mem used: %.2lf %\n", used_rate);
	return 0;
}
