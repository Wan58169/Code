#include <stdio.h>  
#include <signal.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  
  
sigset_t newset, zeroset;  
static int sigFlag = 0;  

//确认信号 改变状态
void sig_handler(int signo)  
{  
    if (signo==SIGUSR1 || signo==SIGUSR2)  
    {  
        sigFlag = 1;  
    }  
}  
 
//初始化数据
void tell_wait()  
{  
    sigemptyset(&newset);  
    sigemptyset(&zeroset);  
    sigaddset(&newset, SIGUSR1);  
    sigaddset(&newset, SIGUSR2);  
      
    struct sigaction action;  
    action.sa_handler = sig_handler;  
    sigemptyset(&action.sa_mask);  
    action.sa_flags = 0;  
    
	/*
	 *	//设置信号为signum的信号处理函数
	 *	int sigaction(int signum,const struct sigaction *act,struct signaction *oldact);
	 *	
	 *  struct sigaction {
	 *		void (*sa_handler)(int);	//指定信号处理函数
	 *      sigset_t sa_mask;			//信号屏蔽字
	 *      int sa_flags;
	 *	}
	*/
	//设置SIGUSR1信号失败
    if (sigaction(SIGUSR1, &action, NULL) < 0)  
    {  
        printf("sigaction error\n");  
        exit(-1);  
    }  
    //设置SIGUSR2信号失败
    if (sigaction(SIGUSR2, &action, NULL) < 0)  
    {  
        printf("sigaction error\n");  
        exit(-1);  
    }  
	//把信号集添加到当前进程的阻塞集合中失败
    if (sigprocmask(SIG_BLOCK, &newset, NULL) < 0)  
    {  
        printf("sigprocmask error\n");  
        exit(-1);  
    }  
}  
  
void tell_parent(pid_t pid)  
{  
	/*
	 *	kill(pid_t pid,int SIG_);
	 *	向编号为pid的进程发送SIG_信号
	 */
    kill(pid, SIGUSR2);  
}  
  
void wait_parent()  
{ 
	/*
	 *	//先把该信号的信号屏蔽字设置为mask的信号屏蔽字，然后去睡眠
	 *	int sigsuspend(const sigset_t *mask);
	 *
	 */
    while(sigFlag == 0)  
    {  
        sigsuspend(&zeroset);  
    }  
      
    sigFlag = 0;  
    /*  
    if (sigprocmask(SIG_BLOCK, &newset, NULL) < 0)  
    {  
        printf("set sigprocmask error\n");  
        exit(-1);  
    } 
	*/
}  
  
void tell_child(pid_t pid)  
{  
    kill(pid, SIGUSR1);  
}  
  
void wait_child()  
{  
    while(sigFlag == 0)  
    {  
        sigsuspend(&zeroset);  
    }  
      
    sigFlag = 0;  
    /*
    if (sigprocmask(SIG_BLOCK, &newset, NULL) < 0)  
    {  
        printf("set sigprocmask error\n");  
        exit(-1);  
    } 
	*/
}  
  
int main(int argc, char **argv)  
{  
    pid_t pid;  
      
    tell_wait(); //初始化信号 
    if ((pid = fork()) < 0) //创建进程失败 
    {  
        perror("fork");  
        return -1;  
    }  
    else if(pid == 0) //子进程	SIGUSR1 
    {  
        while(1)  
        {  
            wait_parent();  
            char line[11];
			memset(line,'B',10);
            write(STDOUT_FILENO, line, strlen(line)-1);   
			sleep(2);
		   	tell_parent(getppid()); 
        }  
    }  
    else  //父进程	SIGUSR2
    {  
        while(1)  
        {  
            char line[11];   
			memset(line,'A',10);
            write(STDOUT_FILENO, line, strlen(line)-1);   
			sleep(2);
		   	tell_child(pid);  
            wait_child();  
        }  
    }  
  
    return 0;  
}  
