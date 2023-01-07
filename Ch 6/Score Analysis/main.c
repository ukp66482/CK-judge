#include <stdio.h>
#include <stdlib.h>

void func(int B,int A,int* score,int student){
    int type1=0,type2=0,type3=0;
    for(int i=0;i<student;i++){
        if(score[i]<B){
            type1++;
        }else if(score[i]>=B && score[i]<A){
            type2++;
        }else if(score[i]>=A){
            type3++;
        }
    }
    printf("%d %d %d\n",type1,type2,type3);
}


int main() {
    int student,interval_num,A,B;

    scanf("%d",&student);

    int *score = malloc(sizeof (int)*student);

    for(int i=0;i<student;i++){
        scanf("%d",&score[i]);
    }

    scanf("%d",&interval_num);

    for(int i=0;i<interval_num;i++){
        scanf("%d %d",&B,&A);
        func(B,A,score,student);
    }
    return 0;
}
