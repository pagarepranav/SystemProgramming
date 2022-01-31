
# Homework 1

Program which takes the keywords as input and checks in given input and outputs the numbers of times it appears.

## Deployment

The process for creating directories, files and running them
as we have already created a CS532 directory we change to it and craete a new directory Lab2 and create a file using touch command.

```bash
Change the directory to CS532
cd 532
Change the directory to hw1
cd hw1
We check the current directory by pwd command 
pwd 
/home/UAB/p130198/cs532/hw1
To edit the file we use 
nano p130198_hw1.c
Save changes by 
clt+X then save by Y
we can list the files by using “ls” command
we compile using the gcc command 
gcc filename.c 
using ./a.out run the file
```


## Code
```bash
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct distab {
    char *text;
    int total;
};

int main(int argc, char *argv[]) {

    int num = argc - 1;
    struct distab infotab[num];
    int j = 0;
    
    // for the struct tab
    for (j = 1; j < argc; j++){
        infotab[j - 1].text = argv[j];
        infotab[j - 1].total = 0;
    }

    char *sen = NULL;
    size_t l = 0;
    ssize_t lineLen = 0;

    // getting the line
    lineLen = getline(&sen, &l, stdin);

    // keep the text
    char *text=malloc(1000 * sizeof(char));

    while(lineLen >= 1) {
        int i = 0;

        while (i < lineLen){

            char presentC = sen[i];
            
            // to see for the text
            if (presentC == ' ' || presentC == '\n' || presentC == '.') {
                
                // to check for the matching 
                for (j = 0; j < num; j++){

                    if (strcmp(infotab[j].text, text) == 0) {
                        int oldInfo = infotab[j].total;
                        int presentInfo = oldInfo + 1;
                        infotab[j].total = presentInfo;
                    }
                }
                text[0] = '\0';
            }
            else {
                // putting together
                strncat(text, &presentC, 1);
            }
            
            i++;
        }

        // checking for the line until there
        lineLen = getline(&sen, &l, stdin);
    }

    // to display table
    void list_disp(struct distab infotab[], int num) {
    int j = 0;
    for (j = 0; j < num; j++) {
        printf("%s:\t%d\n", infotab[j].text, infotab[j].total);
    }
}
    // to display the infotab
    list_disp(infotab, num);

    // freeing the space
    free(text);

    return 0;
}

```
We use stlib,string & stdio headers we input output and standard memory functions.
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
