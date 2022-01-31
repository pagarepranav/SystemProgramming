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

