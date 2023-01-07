#include <stdio.h>


int main() {
    unsigned int temp,N,left,right,not,temp2,temp3;
    unsigned int byte1,byte2,byte3,byte4,d1,d2,d3,d4,total;

    scanf("%d",&N);
    scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
    total = d1+d2+d3+d4;
//divide N into 4 byte

    byte4 =N & ~0xffffff00;

    byte3 =N & ~0xffff00ff;
    byte3>>=8;

    byte2 =N & ~0xff00ffff;
    byte2>>=16;

    byte1 =N & ~0x00ffffff;
    byte1>>=24;

//----------------------------------------------------

    switch (d1) {
        case 1:
            d1 = byte1;
            break;
        case 2:
            d1 = byte2;
            break;
        case 3:
            d1 = byte3;
            break;
        case 4:
            d1 = byte4;
            break;
    }
    switch (d2) {
        case 1:
            d2 = byte1;
            break;
        case 2:
            d2 = byte2;
            break;
        case 3:
            d2 = byte3;
            break;
        case 4:
            d2 = byte4;
            break;
    }
    switch (d3) {
        case 1:
            d3 = byte1;
            break;
        case 2:
            d3 = byte2;
            break;
        case 3:
            d3 = byte3;
            break;
        case 4:
            d3 = byte4;
            break;
    }
    switch (d4) {
        case 1:
            d4 = byte1;
            break;
        case 2:
            d4 = byte2;
            break;
        case 3:
            d4 = byte3;
            break;
        case 4:
            d4 = byte4;
            break;
    }

//----------------------------------------------------
    temp = d1^d2;
    temp<<=8;

    temp |= d3&d2;
    temp<<=8;

    temp |= d1|d3;
    temp<<=8;

    not = ~d4;
    not &= 0x000000ff;
    temp |= not;
    printf("%x\n",temp);
//-------------------------------------------

//     right rotate (circular shift)

    left = temp >> total;
    right = temp << (32-total);
    temp = left | right;
    printf("%x\n",temp);
//--------------------------------------------

    temp2 = temp>>16;
    temp3 = temp<<16;
    temp3 = temp3>>16;
    printf("%x\n",temp2 ^ temp3);
    printf("%d",temp2 ^ temp3);

    return 0;
}
