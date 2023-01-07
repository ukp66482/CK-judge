#include <stdio.h>
#include <stdlib.h>
int main() {
    int a,b,x,y,z;
    char *num = malloc(sizeof (char )*13);
    int *expr = malloc(sizeof (int)*13);

    scanf("%s",num);

    for(int i=0;i<12;i++){
        expr[i] = (int)num[i]-48;
    }
    free(num);

    a = expr[1]+expr[3]+expr[5]+expr[7]+expr[9]+expr[11];
    b = expr[0]+expr[2]+expr[4]+expr[6]+expr[8]+expr[10];

    x = 3*a+b;
    y = x-1;
    z = y%10;
    z = 9-z;

    free(expr);

    printf("%d",z);
    return 0;
}
