#include <stdio.h>
#include <stdlib.h>

int main() {
    float credit;
    float total_credit = 0;
    float sum = 0,grade = 0;

    char array[50] = {0};
    scanf("%s",&array);

    for(int i=0;array[i]!='\0';){

        credit = (int)array[i] - 48;
        total_credit += credit;

                switch (array[i+1]) {
                    case 'A':
                    grade = 4;
                        break;

                    case 'B':
                    grade = 3;
                        break;

                    case 'C':
                    grade = 2;
                        break;

                    case 'F':
                    grade = 0;
                }
            if(array[i+2] == '+' || array[i+2] == '-'){
                switch (array[i+2]) {
                    case '+':
                    grade+=0.3;
                        break;

                    case '-':
                    grade-=0.3;
                        break;
                }
            }

            sum = sum + grade*credit;

            if(array[i+2] == '+' || array[i+2] == '-'){
                i+=3;
            }else{
                i+=2;
            }
        }
    printf("%.2f\n",(float)sum/total_credit);
    return 0;
}
