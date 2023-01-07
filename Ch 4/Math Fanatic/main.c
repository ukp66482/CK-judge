#include <stdio.h>
#include <stdlib.h>

int main() {
    long int length;
    scanf("%ld",&length);
    long int *array = (long int*) malloc(sizeof(long int)*length);
    long int *sum = (long int*) malloc(sizeof (long int)*length);

    for(int i=0;i<length;i++){
        scanf("%ld",&array[i]);
    }

    for(int i=0;i<length;i++){
        if(i==0){
            sum[i] = array[i];
        }else{
            sum[i] = sum[i-1] + array[i];
        }
    }

    for(int i=0;i<length;i++){
        if(sum[i]%array[i]==0){
            printf("%ld %ld\n",sum[i],array[i]);
        }
    }

    return 0;
}
