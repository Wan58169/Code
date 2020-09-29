#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	pid_t pid;
	int i;
	int *sem;

	sem = shmat(shmget(1024,99,IPC_CREAT|0777),0,0);
	*sem = 1;
	pid = fork();
	if(pid < 0) {	// 创建失败 
		perror("fork fail");
	} else if(pid == 0) {	// 子进程 
		for(i=0; i<10; i++) {
			printf("A");
		}
	} else if(pid > 0) {	// 父进程 
		//while(1) {
			for(i=0; i<10; i++) {
				printf("B");
			}
		//}
	}

	return 0;
}
