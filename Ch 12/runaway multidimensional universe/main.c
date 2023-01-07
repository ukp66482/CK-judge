#include<stdio.h>
#include<stdlib.h>
/*void init(int**** ptr){
    for(int i=0;i<2;i++){
        ptr[i] = malloc(sizeof (int**));
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ptr[i][j] = malloc(sizeof (int*));
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++) {
                ptr[i][j][k] = malloc(sizeof(int));
            }
        }
    }

}*/

void init(int**** ptr){
    for(int i=0;i<2;i++){
        ptr[i] = malloc(sizeof (int**));
        for(int j=0;j<2;j++){
            ptr[i][j] = malloc(sizeof (int*));
            for(int k=0;k<2;k++){
                ptr[i][j][k] = malloc(sizeof (int));
            }
        }
    }
}

int main(){
    int ****ptr = malloc(sizeof(int***)*2);
    init(ptr);

    int magic_number;
    long long magic_sum = 0;

    scanf("%d", &magic_number);
    for(int _ = 0; _<2; _++)
        for(int __ = 0; __<2; __++)
            for(int ___ = 0; ___<2; ___++)
                for(int ____ = 0; ____<2; ____++) {
                    //printf("ptr[%d][%d][%d][%d]\n", _, __, ___, ____);
                    ptr[_][__][___][____] = magic_number, magic_sum += ptr[_][__][___][____];
                }
    printf("%lld", magic_sum);
}