#include<stdio.h>

int full_adder_c(int a, int b ,int c){
    switch (a+b+c) {
        case 0:
        case 1:
            return 0;
        case 2:
        case 3:
            return 1;

    }
}
int full_adder_x(int a, int b, int c){
    switch (a+b+c) {
        case 0:
        case 2:
            return 0;
        case 1:
        case 3:
            return 1;
    }
}

# define LEN 5

int main() {
    int a[LEN], b[LEN], ans[LEN], c = 0;
    for(int i = 0 ; i < LEN; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < LEN; ++i) {
        scanf("%d", &b[i]);
    }

    for(int i = 0 ; i < LEN ; ++i) {
        ans[i] = full_adder_x(a[i], b[i], c);
        c = full_adder_c(a[i], b[i], c);
    }
    for(int i = 0 ; i < LEN; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d", c);
}