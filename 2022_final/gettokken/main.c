#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strtok(char *s, const char *sep) {
    printf("strtok banned\n");
    exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts) {
    printf("strtok_r banned\n");
    exit(1);
}

char *strsep(char **stringp, const char *delim) {
    printf("strsep banned\n");
    exit(1);
}
char line[4096];
char *head;
char *back;
int j=0;
char *check =NULL;
char *gettoken(char *str, const char *sep){
    if(str){
        for(int i=0;i<4096;i++){
            line[i] = '\0';
        }
        j=0;
        check = malloc(sizeof (char));
        strcpy(line,str);
        head = line;
        back = line;
    }
    if(check==NULL){
        return NULL;
    }
    back = head;
    for(;line[j]!=' '&&line[j]!='\n';j++){}
    if(line[j]=='\n'){
        line[j] = '\0';
        line[j-1] = '\0';
        check = NULL;
        return back;
    }
    line[j] = '\0';
    head = &line[j]+1;
    int i=0;
    for(;back[i]!='?'&&back[i]!='!'&&back[i]!='.'&&back[i]!=';'&&back[i]!='\0'&&back[i]!=',';i++){}
    back[i] = '\0';

    return back;
}
int main() {
    char buffer[4096];
    char *sep = " \t\n;,.?!";
    char *word;
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(buffer, 4095, stdin);
        for (word = gettoken(buffer, sep); word != NULL;
             word = gettoken(NULL, sep)) {
            printf("%s\n", word);
        }
    }
}
