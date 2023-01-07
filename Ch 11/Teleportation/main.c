#include <stdio.h>

union hx{
    unsigned char parts[16];
    struct {
       unsigned long ul1;
       unsigned long ul2;
    }ul;
    unsigned long long ull;
};

unsigned long construct(unsigned char parts[16]){
    union hx hx;
    for(int i=0;i<16;i++) {
        hx.parts[i] = parts[i];
    }
    hx.ull = hx.ul.ul1 ^ hx.ul.ul2;
    return hx.ull;
}

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}