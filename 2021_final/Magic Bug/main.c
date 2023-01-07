#include <stdio.h>

void printbinary(unsigned long address,int stb){
    int time = 0;
    int l,r;
    unsigned int bit[64] = {0};

    r = stb;
    l = r + 8;

    while(address>=1){
        bit[time++] =(unsigned)address%2;
        address/=2;
    }

    for(int j=63;j>=l;j--){
        printf("0");
        if(j % 8 == 0 && j>0){
            printf(" ");
        }
    }

    for(int j=l-1;j>=r;j--){
        printf("%u",bit[j]);
        if(j % 8 == 0 && j>0){
            printf(" ");
        }
    }

    for(int j=r-1;j>=0;j--){
        printf("0");
        if(j % 8 == 0 && j>0){
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int N,stb;
    unsigned long address;
    scanf("%d",&N);
    while(N--){
        scanf("%d-0x%lx",&stb,&address);
        printbinary(address,stb);
    }
    return 0;
}
