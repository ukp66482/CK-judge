#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int need = 0,l=0;
int fundament[20]={0};

typedef struct item{
    int num;
    int *craft;
}Item;

void crafting(int craft,Item *item){
     bool o=false;
    for(int i=0;i<l;i++){
        if(fundament[i]==craft){
            o=true;
            break;
        }
    }
    if(o){
        need++;
        return;
    }else{
    for(int k=0;k<item[craft].num;k++) {
        crafting(item[craft].craft[k], item);
    }
}
}

int main() {

    int num_item,k=1;

    scanf("%d", &num_item);
    Item *item =malloc(sizeof(Item)*(num_item+1));

    while(k<=num_item) {
        scanf("%d", &item[k].num);
        if (item[k].num == 0) {
            item[k].num = 1;
            item[k].craft = malloc(sizeof(int));
            item[k].craft[0] = k;
            fundament[l++] = k;
            k++;
            continue;

        } else if (item[k].num != 0) {
            item[k].craft = malloc(sizeof(int) * item[k].num);
            for (int i = 0; i < item[k].num; i++) {
                scanf("%d", &item[k].craft[i]);
            }
            k++;
        }
    }

    for(int i=1;i<=num_item;i++){
        for(int j=0;j<item[i].num;j++){
            crafting(item[i].craft[j],item);
        }
    }
    printf("%d",need);
    return 0;
}
