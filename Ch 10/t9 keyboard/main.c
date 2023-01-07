#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count){
    int j;
    char temp[LINE_LEN][BUFFER_LEN];

    for(int i = 0;i < count; i++){
        for(j = 0;arr[i][j] != '\n'; j++) {
            if (arr[i][j] == ' ') {
                strcat(temp[i]," ");
                continue;
            } else {
                switch (arr[i][j]) {
                    case 'a':
                        strcat(temp[i],"(2)1");
                        break;
                    case 'b':
                        strcat(temp[i],"(2)2");
                        break;
                    case 'c':
                        strcat(temp[i],"(2)3");
                        break;
                    case 'd':
                        strcat(temp[i],"(3)1");
                        break;
                    case 'e':
                        strcat(temp[i],"(3)2");
                        break;
                    case 'f':
                        strcat(temp[i],"(3)3");
                        break;
                    case 'g':
                        strcat(temp[i],"(4)1");
                        break;
                    case 'h':
                        strcat(temp[i],"(4)2");
                        break;
                    case 'i':
                        strcat(temp[i],"(4)3");
                        break;
                    case 'j':
                        strcat(temp[i],"(5)1");
                        break;
                    case 'k':
                        strcat(temp[i],"(5)2");
                        break;
                    case 'l':
                        strcat(temp[i],"(5)3");
                        break;
                    case 'm':
                        strcat(temp[i],"(6)1");
                        break;
                    case 'n':
                        strcat(temp[i],"(6)2");
                        break;
                    case 'o':
                        strcat(temp[i],"(6)3");
                        break;
                    case 'p':
                        strcat(temp[i],"(7)1");
                        break;
                    case 'q':
                        strcat(temp[i],"(7)2");
                        break;
                    case 'r':
                        strcat(temp[i],"(7)3");
                        break;
                    case 's':
                        strcat(temp[i],"(7)4");
                        break;
                    case 't':
                        strcat(temp[i],"(8)1");
                        break;
                    case 'u':
                        strcat(temp[i],"(8)2");
                        break;
                    case 'v':
                        strcat(temp[i],"(8)3");
                        break;
                    case 'w':
                        strcat(temp[i],"(9)1");
                        break;
                    case 'x':
                        strcat(temp[i],"(9)2");
                        break;
                    case 'y':
                        strcat(temp[i],"(9)3");
                        break;
                    case 'z':
                        strcat(temp[i],"(9)4");
                        break;
                }
            }
        }
        strcat(temp[i],"\n");
    }
    for(int i=0;i<count;i++){
        strcpy(arr[i],temp[i]);
    }
}
int main() {
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    int count = 0;
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);
    for (int i = 0; i < count; i++) {
        printf("%s", arr[i]);
    }
}