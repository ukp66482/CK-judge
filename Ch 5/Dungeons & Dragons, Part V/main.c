#include <stdio.h>
#include <stdlib.h>


int main() {

    int *d1 = (int*) malloc(sizeof (int)*75);
    int *d2 = (int*) malloc(sizeof (int)*75);
    int *pass = (int*)calloc(6,sizeof (int));

    for(int i=0;i<75;i++){
        scanf("%d %d",&d1[i],&d2[i]);
    }
    for(int i=0;i<75;i++){
        if(d2[i]%2){// odd num

            pass[d1[i]-1]++;
            if(pass[d1[i]-1] == 10) {
                pass[d1[i]-1] = 0;
            }
        }else{
            pass[d1[i]-1]--;
            if(pass[d1[i]-1] == -1) {
                pass[d1[i]-1] = 9;
            }
        }
    }

    for(int i=0;i<6;i++){
        printf("%d ",pass[i]);
    }
    return 0;
}
