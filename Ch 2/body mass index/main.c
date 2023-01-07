#include <stdio.h>
#include <math.h>
int main() {
    int m,h;
    float H;
    scanf("%d %d",&h,&m);
    H = h/100.;
    printf("%f",(float)m/(H*H));
    return 0;
}
