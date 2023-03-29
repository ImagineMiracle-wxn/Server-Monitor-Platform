#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork error.\n");

		return -1;
	} else if (pid > 0) {
		exit(0);
	} else {
		printf("Start Monitor_IM Service...\n");
		system("monitor_server");
		printf("Stop Monitor_IM Service...\n");
	}

	return 0;
}
