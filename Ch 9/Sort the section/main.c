#include <stdio.h>
#define ARR_MAX 1000
int arr[ARR_MAX] = {0};
void sort_section(int *ptr,int *qtr){
    //printf("ptr = %d qtr = %d\narr[9] = %d arr[2] %d\n",*ptr,*qtr,arr[9],arr[2]);
    if(ptr>qtr){ //change location
        int *temp = ptr;
        ptr = qtr;
        qtr = temp;
    }
    //printf("ptr = %d qtr = %d\narr[9] = %d arr[2] %d\n",*ptr,*qtr,arr[9],arr[2]);
    for(int *i=ptr;i<qtr;i++){
        for(int *j=ptr;j<qtr;j++){
            if(*j>*(j+1)){
                int temp = *(j+1);
                *(j+1) = *j;
                *j = temp;
                }
            }
        for(int *k=ptr;k<=qtr;k++){
            printf("%d ",*k);
        }
        printf("\n");
    }
}

int main() {
    int N, a, b;
    scanf("%d%d%d", &N, &a, &b);
    //int arr[ARR_MAX] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }
    sort_section(&arr[a], &arr[b]);
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
}