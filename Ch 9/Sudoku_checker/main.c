#include <stdio.h>
#define NUM 9
int check_matrix[NUM][NUM];

void print_matrix(void){
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            printf("%d ",check_matrix[i][j]);
        }
        printf("\n");
    }
}

void check_sudoku(int (*grid_p)[NUM]) {
    //check_matrix initial

    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            check_matrix[i][j] = 0;
        }
    }

    int temp[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
    int tempc[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};

    //row check

    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            for(int k=0;k<=NUM;k++){
                if(grid_p[i][j] == k && temp[k] == -1){
                    temp[k] = j;
                }else if(grid_p[i][j] == k && temp[k] >= 0){
                    check_matrix[i][temp[k]] = 1;
                    check_matrix[i][j] = 1;
                }
            }
        }
        for(int k=0;k<10;k++){
            temp[k]=-1;
        }
    }
    //printf("After row\n");
    //print_matrix();
    //column check

    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            for(int k=0;k<=NUM;k++){
                if(grid_p[j][i] == k && temp[k] == -1){
                    temp[k] = j;
                }else if(grid_p[j][i] == k && temp[k] >= 0){
                    check_matrix[temp[k]][i] = 1;
                    check_matrix[j][i] = 1;
                }
            }
        }
        for(int k=0;k<10;k++){
            temp[k]=-1;
        }
    }

    //printf("After column\n");
    //print_matrix();

    //subcase check

    for(int i=1;i<NUM;i+=3){
        for(int j=1;j<NUM;j+=3){
            //subcase center move                  // 123
            for(int g=i-1;g<=i+1;g++){         // 456
                for(int l=j-1;l<=j+1;l++){     // 789
                    for(int k=0;k<=NUM;k++){
                        if(grid_p[g][l] == k && temp[k] == -1 && tempc[k] == -1){
                            temp[k] = g;
                            tempc[k] = l;
                        }else if(grid_p[g][l] == k && temp[k] >= 0 && tempc[k] >= 0){
                            check_matrix[temp[k]][tempc[k]] = 1;
                            check_matrix[g][l] = 1;
                        }
                    }

                }
            }
            for(int k=0;k<10;k++){
                temp[k]=-1;
                tempc[k]=-1;
            }
        }
    }
    //printf("After subcase\n");
    //print_matrix();

    //print
    for(int i=0;i<NUM;i++) {
        for (int j = 0; j < NUM; j++) {
            if(check_matrix[i][j]==1){
                printf("(%d,%d)\n",i,j);
            }
        }
    }
}

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}