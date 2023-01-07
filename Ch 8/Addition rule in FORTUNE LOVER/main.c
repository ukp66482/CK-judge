#include <stdio.h>
#include <stdlib.h>

void decimal_to_binay(int temp,unsigned *exponent){

    if(temp==1) {
        *exponent = 1;
        return ;
    }else if(temp==0){
        *exponent = 0;
        return ;
    }
    decimal_to_binay(temp/2,exponent);
    *exponent = *exponent<<1|temp%2;
}

unsigned IEEE_converter(int a){

    unsigned sign_bit = 0;
    unsigned *mantissa = calloc(1,sizeof(unsigned));
    unsigned exponent = 0;
    unsigned IEEE754a = 0;

    // make signed bit
    if(a<0){
        sign_bit = 0x80000000; //signed bit completed
    }

    //make exponent and mantissa
    a = abs(a);
    int power = 0;

    decimal_to_binay(a,mantissa);

    for(;a != 1 ;power++){
        if(a == 0){
            power = -127;
            break;
        }
        a /= 2;
    }

    exponent = power + 127;  //exponent completed

    if(a != 0){
        *mantissa=*mantissa<<(23-power);
        *mantissa = *mantissa & 0x7FFFFF; //mantissa completed
    }

    IEEE754a = IEEE754a | exponent;
    IEEE754a = IEEE754a << 23;
    IEEE754a = IEEE754a | *mantissa;
    IEEE754a = IEEE754a | sign_bit;

    return IEEE754a;
}

void unsigned_to_binary(unsigned a,int binary_a[]){
    for(int i=0;i<32;i++){
        if(a==1){
            binary_a[i] = 1;
        }
        if(a==0){
            binary_a[i] = 0;
        }
        binary_a[i] = a % 2;
        a /= 2;
    }
}

void print_ans(int binary_a[],int binary_b[],int binary_ans[],int a,int b,unsigned IEEE754_ans){
    printf("   ");
    for(int i=31;i>=0;i--){
        printf("%d",binary_a[i]);
        if(i%8==0){
            printf(" ");
        }
    }

    printf("\n");
    printf("+) ");
    for(int i=31;i>=0;i--){
        printf("%d",binary_b[i]);
        if(i%8==0){
            printf(" ");
        }
    }

    printf("\n");
    printf("---------------------------------------\n   ");

    for(int i=31;i>=0;i--){
        printf("%d",binary_ans[i]);
        if(i%8==0){
            printf(" ");
        }
    }

    printf("\n");
    printf("%d + %d = %d",a,b,IEEE754_ans);

}

int main(void){
    int a,b,binary_a[32]={0},binary_b[32]={0},binary_ans[32]={0};
    unsigned IEEE754a,IEEE754b,IEEE754_ans;

    scanf("%d %d",&a,&b);

    IEEE754a = IEEE_converter(a);
    IEEE754b = IEEE_converter(b);
    IEEE754_ans = IEEE754a + IEEE754b;

    unsigned_to_binary(IEEE754a,binary_a);
    unsigned_to_binary(IEEE754b,binary_b);
    unsigned_to_binary(IEEE754_ans,binary_ans);

    print_ans(binary_a,binary_b,binary_ans,a,b,IEEE754_ans);

    return 0;
}