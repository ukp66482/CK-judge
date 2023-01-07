#include <stdio.h>
#include <stdlib.h>

int need = 0;
int fundament[20] = {0};

typedef struct{

    int num;
    int craft[20];

}Item;

void crafting(int craft,Item *item,int num_item){
    int o=0;
    for(int i=0;i<num_item;i++){
        if(fundament[i]==craft){
            o=1;
            break;
        }
    }

    if(o){
        need++;
        return;
    }else{
        for(int k=0;k<item[craft].num;k++) {
            crafting(item[craft].craft[k], item,num_item);
        }
    }
}

int main() {

    int num_item, k = 1,h=0;

    scanf("%d", &num_item);
    Item item[20];

    for (; k <= num_item; k++) {
        scanf("%d", &item[k].num);
        if (item[k].num == 0){ //fundamental item
            item[k].num = 1;
            item[k].craft[0] = k;
            fundament[h++] = k;
            continue;

        } else if (item[k].num != 0) {
            for (int i = 0; i < item[k].num; i++) {
                scanf("%d", &item[k].craft[i]);
            }
        }
    }

    for(int i=1;i<=num_item;i++){
        for(int j=0;j<item[i].num;j++){
            crafting(item[i].craft[j],item,num_item);
        }
    }

    printf("%d\n",need);
    return 0;

}