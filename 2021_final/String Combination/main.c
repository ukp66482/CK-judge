#include <stdio.h>
#include <stdlib.h>

void swap(char **address1,char **address2){
    char * temp = *address1;
    *address1 = *address2;
    *address2 = temp;
}

void Perm(char **list, int i, int n){
    int j;
    if(i == n){
        for (j = 1; j <= n; j++){
            printf("%s ", list[j]);
        }
        printf("\n");
    }
    else{
        for(j = i; j <= n; j++){
            swap(&list[i], &list[j]);
            Perm(list, i+1, n);
            swap(&list[i], &list[j]);
        }
    }
}

int main() {
    int n,k;
    char **names = malloc(sizeof (char *)*20);
    for(int i=0;i<20;i++){
        names[i] = malloc(sizeof (char )*10);
    }

    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++){
        scanf("%s",names[i]);
    }

    for(int i=0;i<n;i++){
        printf("%s",names[i]);
    }


    return 0;
}
