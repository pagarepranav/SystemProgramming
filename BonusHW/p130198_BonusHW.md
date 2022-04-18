# Bonus HW

Make UAB shell with fibonacci, help,hello world and quit to exit shell.
## Deployment

The process for creating directories, files and running them
as we have already created a CS532 directory we change to it and craete a new directory Lab10 and create a file using touch command.

```bash
Change the directory to CS532
cd 532
Change the directory to Bonushw
cd Bonushw
We check the current directory by pwd command 
pwd 
/home/UAB/p130198/cs532/Bonushw
To edit the file we use 
nano shell.c
fib.c
hello.c
Save changes by 
clt+X then save by Y
we can list the files by using “ls” command
we compile using the gcc command 
gcc filename.c 
using ./a.out to run run the file
```


## Code
```bash
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char** argv) {
	setenv("hello", "./hello", 1);
	setenv("fibonacci", "./fibonacci", 1);
	FILE* file = fopen("uab_sh.log", "w+");
	int check_stop = 1;
	while (check_stop == 1) {
		char in_line[200], in_comm[50], par_one[50];
		in_line[0] = '\0';
		printf("uab_sh > ");
		fgets(in_line, 300, stdin);
		fprintf(file, "%s", in_line);
		in_line[strlen(in_line)-1] = '\0';
		int a = 0, b = 0, c = 0;
		in_comm[0] = '\0';
		par_one[0] = '\0';
		for (a = 0; in_line[a] != ' '; a++) {
			if (in_line[a] == '\0')
				break;
			in_comm[b++] = in_line[a];
		}
		in_comm[b] = '\0';
		if (in_line[a] != '\0') {
			a++;
			for (; in_line[a] != ' '; a++) {
				if (in_line[a] == '\0')
					break;
				par_one[c++] = in_line[a];
			}//parameter 1
			par_one[c] = '\0';
		}
		if (!strcmp(in_comm, "history")) {//history
			fclose(file);
			char* ar[] = { "cat", "uab_sh.log", NULL };
			pid_t p = fork();
			if (p == 0)
				execvp(*ar, ar);
			else{
				wait(NULL);
				file = fopen("uab_sh.log", "a+");
			}
		}
		else if (!strcmp(in_comm, "cd")) {
			if (par_one[0] != '\0')
				chdir(par_one);
			else {
				printf("No directory specified\n");
			}
		}
		else if (!strcmp(in_comm, "list")) {
			char* ar[] = { "ls", NULL };
			pid_t p = fork();
			if (p == 0)
				execvp(*ar, ar);
			else
				wait(NULL);
		}
		else if (!strcmp(in_comm, "help")) {
			printf("Simple shell program\n");
			printf("Commands: \n");
			printf("list - show current directory files\n");
			printf("cd <directory> - switch to specified directory\n");
			printf("help - show commands and functioning\n");
			printf("quit - exit shell program\n");
			printf("history - show executed commands history\n");
		}
		else if (!strcmp(in_comm, "quit")) {//exit shell
			check_stop = 0;
		}
		else{
			char* var = getenv(in_comm);
			if(par_one[0] != '\0'){
				char* ar[] = { var, par_one, NULL };
				pid_t p = fork();
				if (p == 0)
					execvp(*ar, ar);
				else
					wait(NULL);
			}
			else{
				char* ar[] = { var, NULL };
				pid_t p = fork();
				if (p == 0)
					execvp(*ar, ar);
				else
					wait(NULL);
			}
		}
	}
	fclose(file);
	//exit program
	return 0;
}

```
We use stlib,string,unistd,dirent,stdio  and other headers as input output and standard memory functions.
## Running Tests

To run tests, run the following command

```bash
  We run it on Vulcan 
  gcc 
  then 
  using ./a.out

```


## Authors

- Pranav Pagare


## Credits

I would like thank Dr. Unan and the TA's.
