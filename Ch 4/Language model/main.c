#include <stdio.h>

int main() {
    double possibility[5]={0};
    double final = 0;
    for(int i=0;i<5;i++){
        scanf("%lf",&possibility[i]);
    }
    final = possibility[0];
    for(int i=1;i<5;i++){
        final = final*possibility[i];
    }
    printf("%.15lf",final);
    return 0;
}
