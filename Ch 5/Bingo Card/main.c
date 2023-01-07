#include <stdio.h>
#include <stdlib.h>

 struct bingo_card{

    int *row;
    int *column;
    int **card;
    int line;
    int ldiag;
    int rdiag;

};


}
int** matrix(){
    int **matrix = (int**)malloc(sizeof(int*)*8);
    for(int i=0;i<8;i++){
        matrix[i] = (int*)calloc(8,sizeof(int));
    }
    return matrix;
}



int main() {

    struct bingo_card *bingoCard = malloc(sizeof (struct bingo_card));

    int pick[64];
    bingoCard->ldiag=0,bingoCard->rdiag=0;

    bingoCard->card = matrix();
    bingoCard->row = malloc(sizeof (int)*8);
    bingoCard->column = malloc(sizeof (int)*8);
    bingoCard->line = 0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%d",&bingoCard->card[i][j]);
        }
    }
    for(int i=0;i<64;i++){
        scanf("%d",&pick[i]);
    }
    for(int i=0;i<64;i++){
        for(int j=0;j<8;j++){
            for (int k=0;k<8;k++){
                if(pick[i]==bingoCard->card[j][k]){
                    bingoCard->row[j]++;
                    bingoCard->column[k]++;
                }
            }
        }
        for(int l=0;l<8;l++){
            if(pick[i]==bingoCard->card[l][l]){
                bingoCard->ldiag++;
            }
            if(pick[i]==bingoCard->card[7-l][l]){
                bingoCard->rdiag++;
            }
        }
    }

    for (int i=0;i<8;i++){
            if(bingoCard->row[i]==8){
                bingoCard->line++;
            }
            if(bingoCard->column[i]==8){
                bingoCard->line++;
            }
    }
    if(bingoCard->ldiag==8)
        bingoCard->line++;
    if(bingoCard->rdiag==8)
        bingoCard->line++;

    printf("%d",bingoCard->line);

    return 0;
}
