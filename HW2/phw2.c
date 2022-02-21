/*
Name:Pranav Pagare
BlazerId:p130198
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char** argv) {
	int i;
	char* size=NULL;
	char* dir=NULL;
	char* sub=NULL;
	int show = 0;
	int limit = 0;
	int path = 0;
	int str = 0;
	for(i=0;i<argc;i++){
		if(!strcmp(argv[i], "-S")){
			show=1;
		}
		else if(!strcmp(argv[i], "-s")){
			limit=1;
			size=malloc(sizeof(char)*100);
			strcpy(size, "+");
			strcat(size, argv[i+1]);
		}
		else if(!strcmp(argv[i], "-f")){
			str=1;
			sub=malloc(sizeof(char)*100);
			strcpy(sub, "*");
			strcat(sub, argv[i+1]);
			strcat(sub, "*");
		}
		else if(i!=0 && (argv[i][0]=='.'||argv[i][0]=='/')){
			path=1;
			dir=malloc(sizeof(char)*100);
			strcpy(dir, argv[i]);
		}
	}
	
	if(show==0&&limit==0&&path==0&&str==0){
		char* ar[]={"find", NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==0&&path==0&&str==1){
		char* ar[]={"find", "-name", sub, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==0&&path==1&&str==0){
		char* ar[]={"find", dir, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==0&&path==1&&str==1){
		char* ar[]={"find", dir, "-name", sub, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==1&&path==0&&str==0){
		char* ar[]={"find", "-size", size, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==1&&path==0&&str==1){
		char* ar[]={"find", "-name", sub, "-size", size, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==1&&path==1&&str==0){
		char* ar[]={"find", dir, "-size", size, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==1&&path==1&&str==1){
		char* ar[]={"find", dir, "-name", sub, "-size", size, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==1&&limit==0&&path==0&&str==0){
		char* ar[]={"du", "-h", NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==1&&limit==0&&path==1&&str==0){
		char* ar[]={"du", "-h", dir, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	else if(show==0&&limit==1&&path==0&&str==0){
		char* ar[]={"find", "-size", size, NULL};
		pid_t p = fork();
		if (p == 0){
			if(execvp(*ar, ar)==-1){
				exit(1);
			}
		}
		else{
			wait(NULL);
		}
	}
	
	return 0;
}




