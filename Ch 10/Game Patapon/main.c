#include <stdio.h>
#include <string.h>
char ch;
int readline(char str[]){
    int i = 0;
    while((ch = getchar()) != ',' && ch !='\n' && ch!='.'){
        str[i++] = ch;
    }
    str[i] = '\0';
}

int main() {
    const char *go_ahead = "PATA PATA PATA PON";
    const char *attack = "PON PON PATA PON";
    const char *defense = "CHAKA CHAKA PATA PON";

    char str[50];
    int health,distance,rule = 0,fail,victory;

    scanf("%d %d",&distance,&health);
    getchar();

    for(int i=1;i<=30;i++){
       // printf("%d %d\n",distance,health);

        readline(str);
       // puts(str);

        if(strcmp(str,go_ahead)==0){
            if(--distance == 0){
                fail = 1;
                rule++;
                break;
            }
            rule++;
        }

        if(strcmp(str,attack)==0){
            if(distance<=3) {
                if (--health == 0) {
                    victory = 1;
                    rule++;
                    break;
                }
            }
            rule++;
        }

        if(strcmp(str,defense)==0){
            distance++;
            rule++;
        }

        if(i%10==0){
            if(strcmp(str,defense)!=0){
                fail = 1;
                break;
            }
        }

        if(ch == '\n')
            break;

        for(int j=0;j<50;j++){
            str[j] = '\0';
        }
    }
    if(fail == 1){
        printf("NO %d",health);
    }else if(victory ==1){
        printf("YES %d",rule);
    }else{
        printf("NO %d",health);
    }

    return 0;
}
