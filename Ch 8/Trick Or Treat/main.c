#include<stdio.h>
#include<stdlib.h>

int array[1500];
int max_till[42]={0};

int maxChandy(int size){//dynamic programming
    /*if (size==0){
        max_till[0] = 0;
        return 0;
    }
    if(size==1){
        max_till[1] = array[0];
        return array[0];
    }*/
    max_till[0] = 0;
    max_till[1] = array[0];
    max_till[2] = (array[0]>array[1]) ? array[0] : array[1];

    for(int i=2;i<=size;i++){
        max_till[i] = (max_till[i-2] + array[i-1] > max_till[i-1]) ? max_till[i-2] + array[i-1] : max_till[i-1];
    }
    return max_till[size];
}

int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy(size));
    return 0;
}