#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b){
    struct ESPer *a1 = (struct ESper*) a;
    struct ESPer *b1 = (struct ESper*) b;

    if(a1->level>=b1->level){ //>= ascending or <= descending according to level to sort
        return 1;
    }else{
        return -1;
    }
}
void sort_level(struct ESPer *arr, int length){
    qsort((void*)arr,length,sizeof (arr[0]),cmp); //qsort( (void*)array , length of array , sizeof(array[0]) , cmp)
}

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}