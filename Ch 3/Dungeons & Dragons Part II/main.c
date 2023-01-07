#include <stdio.h>
#include <stdlib.h>

int who(int *dice){
    return ((dice[0]+dice[1]+dice[2])%2);
}

int main() {
    int player=100,dragon=100;
    int dice[6]={0};
    int t;

    do{
        for(int i=0;i<6;i++){
            scanf("%d",&dice[i]);
        }
            t=who(dice);
            if(t==1) {
                if (dice[3] < dice[4] && dice[4] < dice[5]) {
                    dragon = dragon - 25;
                } else if (dice[3] % 2 == dice[4] % 2 || dice[4] % 2 == dice[5] % 2) {
                    dragon = dragon - 5;
                }
            }
            if(t==0){
                if(abs(dice[3]-dice[4])>dice[5]){
                    player = player - 15;
                }else if((dice[3]+dice[4])!=dice[5]){
                    player = player - 5;
                }

            }
    } while (player>0 && dragon>0);

    if (player<=0){
        printf("Dragon wins");
    }else{
        printf("Player wins");
    }
    return 0;
}
