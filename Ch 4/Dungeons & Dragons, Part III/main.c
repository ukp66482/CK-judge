#include <stdio.h>


int main() {
    int d1,d2,d3;

    long long unsigned int NUMBER_1 = 0x38E38E38E38E3800;
    long long unsigned int NUMBER_2 = 0x2AAAAAAAAAAAAAAA;
    long long unsigned int NUMBER_3 = 0x1C71C71C71C71C71;
    long long unsigned int NUMBER_4 = 0x7CE66C50E2840000;

    scanf("%d %d %d",&d1,&d2,&d3);
    long long unsigned int result = (((d1*NUMBER_1)%NUMBER_4+(d2*NUMBER_2)%NUMBER_4)%NUMBER_4+(d3*NUMBER_3)%NUMBER_4)% NUMBER_4;

    printf("%llu\n",result);
    // printf("%llu,%llu,%llu",NUMBER_1*4,NUMBER_2*6,NUMBER_3*8);
    return 0;
}
