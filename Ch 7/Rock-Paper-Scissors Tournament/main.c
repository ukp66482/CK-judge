#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int j=0;
typedef struct {
    char shape;
    int player_num;
}Player;

void game(Player *player,char judge[],int turn,int num){
    int k=0;
    if(j==turn){
        printf("%d",player[0].player_num+1);
        return;
    }
    int i=0;
    for(int v=0;v<(num/2);v++){
        if(player[i].shape=='p'&&player[i+1].shape=='s'){
            Player temp = player[i+1];
            player[k] = temp;
        }else if(player[i].shape=='s'&&player[i+1].shape=='p'){
            Player temp = player[i];
            player[k] = temp;
        }else if(player[i].shape=='r'&&player[i+1].shape=='s'){
            Player temp = player[i];
            player[k] = temp;
        }else if(player[i].shape=='s'&&player[i+1].shape=='r'){
            Player temp = player[i+1];
            player[k] = temp;
        }else if(player[i].shape=='p'&&player[i+1].shape=='r'){
            Player temp = player[i];
            player[k] = temp;
        }else if(player[i].shape=='r'&&player[i+1].shape=='p'){
            Player temp = player[i+1];
            player[k] = temp;
        }else if(player[i].shape=='r'&&player[i+1].shape=='r'){
            if(judge[j]=='s'){
                Player temp = player[i];
                player[k] = temp;
            }else{
                Player temp = player[i+1];
                player[k] = temp;
            }
        }else if(player[i].shape=='p'&&player[i+1].shape=='p'){
            if(judge[j]=='s'){
                Player temp = player[i];
                player[k] = temp;
            }else{
                Player temp = player[i+1];
                player[k] = temp;
            }
        }else if(player[i].shape=='s'&&player[i+1].shape=='s'){
            if(judge[j]=='s'){
                Player temp = player[i];
                player[k] = temp;
            }else{
                Player temp = player[i+1];
                player[k] = temp;
            }
        }
        i+=2;
        k++;
    }
    j++;
    num/=2;
    game(player,judge,turn,num);
}

int main() {
    int num;

    scanf("%d", &num);
    char string[num+1];
    Player *player = (Player*) malloc(sizeof(Player) * num);
    scanf("%s",string);
    for(int i=0;i<num;i++){
        player[i].player_num = i;
        player[i].shape = string[i];
    }

    int  turn = log2(num);

    char judge[turn+1];
    scanf("%s", judge);
    game(player,judge,turn,num);

    return 0;
}
