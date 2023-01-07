#include <stdio.h>
#include <stdlib.h>


int main() {
    int *list = (int*) malloc(sizeof (int)*30);
    int i=0;
    for(i;list[(i-1)]!=-1;i++){
        scanf("%d",&list[i]);
    }
    i=i-2;
    int n = i;
    for(int a=0;a<i;a++){
        for(int b=0;b<(i-a);b++){
            if(list[b]>list[b+1]){
                int temp;
                temp = list[b];
                list[b] = list[b+1];
                list[b+1] = temp;
            }
        }
    }
    printf("%d",list[n]-list[0]);

    return 0;
}
