#include <stdio.h>

void player_attack(int d4,int d5,int d6);
void dragon_attack(int d4,int d5,int d6);
int main() {
    int d1,d2,d3,d4,d5,d6;
    scanf("%d %d %d %d %d %d",&d1,&d2,&d3,&d4,&d5,&d6);

    if(d1+d2+d3<=10){
        player_attack(d4,d5,d6);
    }else{
        dragon_attack(d4,d5,d6);
    }
    return 0;
}

void player_attack(int d4,int d5,int d6){
    if(d4 == d5 && d5== d6){
        printf("Player attacks: Critical Hit");
    }else if(d4 + d5 >= d6){
        printf("Player attacks: Normal Hit");
    }else{
        printf("Player attacks: Miss");
    }
}

void dragon_attack(int d4,int d5,int d6){
    if(d4 == d5 || d5 == d6 || d4 == d6){
        printf("Dragon attacks: Miss");
    }else if(d4 + d5 != d6){
        printf("Dragon attacks: Normal Hit");
    }else{
        printf("Dragon attacks: Critical Hit");
    }
}