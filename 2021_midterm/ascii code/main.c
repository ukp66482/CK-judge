#include <stdio.h>

int main() {
    for(int i=33;i<128;i++){
        printf("%3d %3c  ",i ,i);
        if(i%8==0){
            printf("\n");
        }
    }
    return 0;
}
