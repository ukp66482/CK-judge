#include <stdio.h>
#include <stdlib.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main() {
    char* arr;
    arr = malloc(sizeof (char)*100);
    int skill=0;
    for(int i=0;;i++){
        scanf("%c",&arr[i]);
        if(arr[i]=='\n'){
            break;
        }
    }

    Strength INIS = INIT_STRENGTH;
    Obedience INIO = INIT_OBEDIENCE;


    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]=='e'){

            INIS+=STRENGTH_EAT;
            INIO-=OBEDIENCE_EAT;

        }else if(arr[i]=='t'){

            INIS-=STRENGTH_TRAIN;
            INIO+=OBEDIENCE_TRAIN;

        }
        if(INIO >= LEARN_OBEDIENCE && INIS <= LEARN_STRENGTH){
            skill++;
            INIO = INIT_OBEDIENCE;
        }
        //printf("%d ,%c\n",skill,arr[i]);
    }

    if(skill >= 5){
        printf("Yes");
    }else{
        printf("No");
    }


    return 0;
}
