#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *order, char **result);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
        "aluminum", "ammunition", "orange", "aspirin", "ax",
        "basketball", "zipper", "bell", "blanket", "drum",
        "canvas", "flute", "eraser", "mirror", "comb",
        "eggplant", "diamond", "zucchini", "door", "butter",
        "egg", "dart", "chair", "encyclopedia", "china",
        "fan", "glue", "elevator", "flower", "hat",
        "garlic", "strawberry", "glove", "flour", "ice",
        "ship", "hammer", "fur", "key", "honey",
        "grape", "icecream", "lock", "iron", "ivory",
        "jacket", "oil", "uniform", "kiwi", "pan",
        "helmet", "keyboard", "yoyo", "jet", "knife",
        "tie", "lemon", "xerox", "ink", "mutton",
        "newspaper", "melon", "coconut", "motorcycle", "longan",
        "nail", "rice", "magnet", "peanut", "ointment",
        "oar", "jeans", "nut", "arrow", "oven",
        "jewel", "wool", "noodle", "pencil", "lamp",
        "refrigerator", "needle", "roast", "vest", "yarn",
        "saw", "hamburger", "soap", "glass", "wine",
        "tangerine", "pillow", "umbrella", "zinc", "train",
        "uglifruit", "toast", "underwear", "vanilla", "jeep",
        "unicycle", "vase", "rope", "violin", "warship",
        "volleyball", "water", "yogurt", "submarine", "passionfruit",
        "yacht", "rose", "window", "yolk", "kite",
        "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

void recovering_order(char *order, char **result){
    int goods_num = 0;
    char *temp = strtok(order,":");
    char **sep = malloc(sizeof (char*)*30);
    *result = malloc(sizeof (char )*500);

    while(temp){
        sep[goods_num] = temp;
        temp = strtok(NULL,":");
        goods_num++;
    }

    for(int i=0;i<goods_num;i++){
        char *correct_product = NULL;
        int which_char;
        for(int j=0;j<GOODS_SIZE;j++){
            temp = strstr(names[j],sep[i]);
            if(temp){
                if(correct_product == NULL){
                    correct_product = names[j];
                    which_char = temp - names[j];
                }else{
                    if(which_char > temp - names[j]){
                        correct_product = names[j];
                        which_char = temp - names[j];
                    }else if (which_char == temp - names[j]){
                        if(strlen(correct_product) > strlen(names[j])){
                            correct_product = names[j];
                            which_char = temp - names[j];
                        }else if(strlen(correct_product) == strlen(names[j])){
                            if(strcmp(correct_product,names[j]) > 0){
                                correct_product = names[j];
                                which_char = temp - names[j];
                            }else{
                                continue;
                            }
                        }
                    }
                }
            }else{
                continue;
            }
        }
        if(i==0){
            strcpy(*result,correct_product);
        }else{
            strcat(*result,"+");
            strcat(*result,correct_product);
        }
    }
}