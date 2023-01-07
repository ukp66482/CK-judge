#include<stdio.h>
#include<ctype.h>

int main () {
    int num,temp=1;
    scanf("%d", &num);
   // ch = getchar(); //read and dump previous enter key
    char prev = ' ';
    char now;
    while(1){
        now = getchar();
        if(temp == num) break;
        if(prev==' '||prev==','||prev=='.'||prev==';'){ //toupper
            now = toupper(now);
            putchar(now);
            prev = now;
        }
        else if(now==','||now=='.'||now==';'){ //new line
            printf("\n");
            prev = now;
            temp++;
        }
        else{  // tolower
            now = tolower(now);
            putchar(now);
            prev = now;
        }
    }
    return 0;
}