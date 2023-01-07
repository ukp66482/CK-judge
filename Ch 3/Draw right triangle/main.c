#include <stdio.h>

void triangle1(int j){
    for(int i=0;i<j;i++){
        for(int k=1;k<=j-i;k++){
            printf("*");
        }
        printf("\n");
    }
}

void triangle2(int j){
    for(int i=0;i<j;i++){
        for(int k=0;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }
}

void triangle3(int j){
    for(int i=0;i<j;i++){
        for(int h=0;h<i;h++){
            printf(" ");
        }
        for(int k=1;k<=j-i;k++){
            printf("*");
        }
        printf("\n");
    }
}


void triangle4(int j){
    for(int i=0;i<j;i++){
        for(int h=j-i-1;h>0;h--){
            printf(" ");
        }
        for(int k=0;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }
}


int main() {
    int t,j;
    scanf("%d %d",&t,&j);
    switch (t) {
        case 1:
            triangle1(j);
            break;
        case 2:
            triangle2(j);
            break;
        case 3:
            triangle3(j);
            break;
        case 4:
            triangle4(j);
            break;
    }

    return 0;
}
