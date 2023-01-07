#include <stdio.h>

int main() {
    int drinks[4][11] = {0,0,0,0,0,0,0,0,0,0,0,
                         10,10,10,10,10,10,10,10,10,10,10,
                        10,10,10,10,10,10,10,10,10,10,10,
                        10,10,10,10,10,10,10,10,10,10,10};
    int num_cus,num_drinks,index,total;
    scanf("%d",&num_cus);
    for(int i=0;i<num_cus;i++){
        scanf("%d %d",&index,&num_drinks);
        if(index<11){
            index =index%10;
            if(index == 0) index+=10;
            if(drinks[1][index]<num_drinks){
                total = total + drinks[1][index] * 10;
                drinks[1][index] = 0;
            }else {
                drinks[1][index] = drinks[1][index] - num_drinks;
                total = total + num_drinks * 10;
                //printf("[1][%d] = %d\n",index,drinks[1][index]);
            }
        }else if(index>=11&&index<=20){
            index =index%10;
            if(index == 0) index+=10;
            if(drinks[2][index]<num_drinks){
                total = total + drinks[2][index] * 20;
                drinks[2][index] = 0;
            }else {
                drinks[2][index] = drinks[2][index] - num_drinks;
                total = total +num_drinks * 20;
                //printf("[2][%d] = %d\n",index,drinks[2][index]);
            }
        }else if(index>=21&&index<=30){
            index =index%10;
            if(index == 0) index+=10;
            if(drinks[3][index]<num_drinks){
                total = total + drinks[3][index] * 30;
                drinks[3][index] = 0;
            }else {
                drinks[3][index] = drinks[3][index] - num_drinks;
                total = total +num_drinks*30;
                //printf("[3][%d] = %d\n",index,drinks[3][index]);
            }
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=10;j++){
            printf("%d ",drinks[i][j]);
        }
        printf("\n");
    }
    printf("Earned: $%d",total);




    return 0;
}
