#include <stdio.h>

int main() {
    char stu[10]={0};
    int x=1;
    int valid=0,first_letter=0,a;
    while(1){
        stu[0] = getchar();
        if(stu[0]=='\n'){
            break;
        }
        for(int i=1;i<10;i++) {
            scanf("%c", &stu[i]);
        }

      //  printf("%d %d\n",stu[0],stu[9]);

        switch (stu[0]) {
            case 'A':
            case 'a':
                first_letter = 0;
                break;
            case 'B':
            case 'b':
                first_letter = 1;
                break;
            case 'C':
            case 'c':
                first_letter = 2;
                break;
            case 'D':
            case 'd':
                first_letter = 3;
                break;
            case 'E':
            case 'e':
                first_letter = 4;
                break;
            case 'F':
            case 'f':
                first_letter =4;
                break;
            case 'H':
            case 'h':
                first_letter = 6;
                break;
            case 'I':
            case 'i':
                first_letter = 7;
                break;
            case 'J':
            case 'j':
                first_letter = 8;
                break;
            case 'K':
            case 'k':
                first_letter = 9;
                break;
            case 'L':
            case 'l':
                first_letter = 0;
                break;
            case 'N':
            case 'n':
                first_letter = 2;
                break;
            case 'P':
            case 'p':
                first_letter = 3;
                break;
            case 'Q':
            case 'q':
                first_letter = 4;
                break;
            case 'R':
            case 'r':
                first_letter = 5;
                break;
            case 'S':
            case 's':
                first_letter = 6;
                break;
            case 'T':
            case 't':
                first_letter = 7;
                break;
            case 'U':
            case 'u':
                first_letter = 8;
                break;
            case 'V':
            case 'v':
                first_letter = 9;
                break;
            case 'Z':
            case 'z':
                first_letter = 2;
                break;
            default:;
        }

        valid = first_letter * 9;

        for(int i=1;i<=8;i++){
            valid = valid + (stu[i]-'0')*(9-i);
        }

        //printf("%d",first_letter*9+3*8+5*7 +1*6 +2*5+1*4+5*3+6*2+2*1);
        if(valid%10!=0){
            for(int i=0;i<9;i++){
                printf("%c",stu[i]);
            }
            printf(" is the imposter!!!\n");
        }
       for(int i=0;i<9;i++){
           stu[i] = 0;
       }
        valid =0;
       first_letter = 0;
    }

    return 0;
}
