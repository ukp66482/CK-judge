#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int coffee(int j);

int main() {
    int i,j;
    scanf("%d %d",&i,&j);
    if(i<=4){
        printf("The total price is %d dollars!",(coffee(i)*j));
    }else {
        printf("Wait, what?");
    }
    return 0;
}

int coffee(int j){
    switch (j) {
        case 1:
            return AMERICANO;
        case 2:
            return LATTE;
        case 3:
            return CAPPUCCINO;
        case 4:
            return MOCHA;
        default:
            return 0;
    }
}