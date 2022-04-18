#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "queue.h"


int P;

static void catch_end(int signo){
	wait(NULL);
	time_t now = time(&now);
	struct tm *ptm = gmtime(&now);
	strcpy(Q[check].end, asctime(ptm));
	Q[check].status=0;
	check++;
	P++;
}

int main(int argc, char* argv[]){
	if(argc<2){
		printf("Usage: %s <P>\n", argv[0]);
		exit(1);
	}
	P = atoi(argv[1]);
	Q = malloc(sizeof(Queue)*40);
	front = 0;
	back = -1;
	check = 0;
	char* buff = malloc(sizeof(char)*100);
	while(1){
		printf("Enter command> ");
		fgets(buff, 100, stdin);
		char* token = strtok(buff, " \n");
		if(!strcmp(token, "submit")){
			int i;
			for(i=0;i<5;i++){
				Q[front].comm[i]=NULL;
			}
			i=0;
			token = strtok(NULL, " \n");
			char* file=malloc(sizeof(char)*50);
			strcpy(file,"./");
			strcat(file, token);
			Q[front].comm[i++]=file;
			while((token = strtok(NULL, " \n"))){
				Q[front].comm[i++]=token;
			}
			Q[front].size=i;
			Q[front].status=0;
			front++;
		}
		else if(!strcmp(token, "showjobs")){
			printf("jobid\tcommand\t\t\tstatus\n");
			int i;
			int id = 1;
			for(i=check;i<front;i++){
				printf("%d\t", id++);
				int j;
				for(j=0;j<Q[i].size;j++){
					printf("%s ", Q[i].comm[j]);
				}
				if(Q[i].status==1){
					printf("\t\tRunning\n");
				}
				else if(Q[i].status==0){
					printf("\t\tWaiting\n");
				}
			}
		}
		else if(!strcmp(token, "submithistory")){
			printf("jobid\tcommand\t\tstarttime\t\tendtime\t\tstatus\n");
			int i;
			for(i=0;i<check;i++){
				printf("%d\t", i+1);
				int j;
				for(j=0;j<Q[i].size;j++){
					printf("%s ", Q[i].comm[j]);
				}
				printf("\t\t%s", Q[i].start);
				printf("\t\t%s\t\tSuccess\n", Q[i].end);
			}
		}
		if(P>0&&(back+1)<front){
			P--;
			back++;
			Q[back].status=1;
			time_t now = time(&now);
			struct tm *ptm = gmtime(&now);
			strcpy(Q[back].start, asctime(ptm));
			pid_t pid = fork();
			if(pid==0){
				if(execvp(Q[back].comm[0], Q[back].comm)==-1){
					P++;
					printf("Error\n");
					exit(1);
				}
			}
			else{
				signal(SIGCHLD, catch_end);
			}
		}
	}
	return 0;
}








