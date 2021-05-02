#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int a;
char names[10];

void inputnamE(){
	printf("Child process no. %d\nPID=%d\nEnter the process name: ", a, getpid());
	scanf("%s", names);
}

void outputnamE(){
	printf("\nChild process %d: %s\n", a, names);
}

int main(void){
	for(a = 1; a <= 4; a++){
		pid_t pid = fork();

		if(pid == 0){
			inputnamE();
			outputnamE();
			exit(0);
		}
		else{
			printf("\nIn progress...\n");
			wait(NULL);
		}
	}
	printf("\nJOB IS DONE\n");
	return EXIT_SUCCESS;
}
