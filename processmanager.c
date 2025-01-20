#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	pid_t pid = fork();
	if (pid < 0){                                                                          //Fork failure//
		printf("Fork failed");
		return 0;
	}
	else if (pid == 0){                                                                   //Child Process//
		printf("Child process(PID:%d) is executing the command", getpid());
		execlp("ls","ls","NULL");
	}
	else{                                                                                 //Parent process// 
		printf("Parent process is executing(PID:%d)", getpid());
		int status;
		wait(&status);
		printf("Child Process is executed\n");
	}
	return 0;
}
