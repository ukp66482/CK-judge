#include <stdio.h>
#include <string.h>

#define MAX_CAND_CNT 20
#define MAX_NAME_LEN 32

struct ballot_counter_s {
    int count;
    char name[MAX_NAME_LEN];
} counter[MAX_CAND_CNT];
int cand_cnt;

void count(const char *name){
    for(int i=0;i<MAX_CAND_CNT;i++){
        if(strcmp(name,counter[i].name) == 0){
            counter[i].count++;
        }
    }
}
const char *winner(){
    int max_index = 0;
    struct ballot_counter_s max = counter[0];
    for(int i = 0;i < MAX_CAND_CNT;i++){
        if(counter[i].count>max.count){
            max = counter[i];
            max_index = i;
        }
    }
    //printf("%s\n",max.name);
    return counter[max_index].name;
}



int main()
{
    scanf("%d", &cand_cnt);
    for (int i = 0; i < cand_cnt; i++) {
        scanf("%s", counter[i].name);
        counter[i].count = 0;
    }

    char name[MAX_NAME_LEN];
    while (scanf("%s", name) != EOF)
        count(name);

    for (int i = 0; i < cand_cnt; i++)
        printf("%s %d\n", counter[i].name, counter[i].count);

    printf("%s\n", winner());

    return 0;
}