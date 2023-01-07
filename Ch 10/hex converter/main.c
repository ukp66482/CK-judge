#include <stdio.h>

char converter(int digit){
    return "0123456789ABCDEF"[digit];
}


int main() {
    int number = 0;
    scanf("%d", &number);
    printf("%c", converter(number));
    return 0;
}
