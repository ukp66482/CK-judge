#include <stdio.h>
void RNN(float x){
    float h=0;
    for(int i=0;i<5;i++) {
        h = 0.9 * x + 0.1 * h - 51;
        x = -0.98 * h + 153;
        printf("%.1f ", x);
    }
}
int main() {
    float x;
    scanf("%f",&x);
    RNN(x);
    return 0;
}
