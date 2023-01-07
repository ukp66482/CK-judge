#include <stdio.h>

int matrix[101][101]={0};
int visited[101]={0};
int paper;
int temp[101]={0};
int k=0;

void dfs(int need){
    temp[k++] = need;
    visited[need] = 1;
    for(int i=1;i<=paper;i++){
        if(matrix[need][i]>0 && visited[i] == 0){
            dfs(i);
        }
    }
}
void bubblesort(){
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-1;j++){
            if(temp[j]>temp[j+1]){
                int x = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = x;
            }
        }
    }
    for(int i=0;i<k;i++){
        printf("%d ",temp[i]);
        temp[i] = 0;
    }
    k=0;
}

int main() {
    int idx;

    scanf("%d",&paper);
    getchar();//'\n'

    while(scanf("%d",&idx)){

        if(idx==0) break;
        char u;
        int num=0;
        getchar();//' '

        while(1){

            u = getchar();

            if(u=='\n'){
                matrix[idx][num] = num;
                break;
            }
            else if( u == ' '){
                matrix[idx][num] = num;
                num = 0;
            }else{
                num *=10;
                num += u-'0';
            }
        }
    }

    for(int i=1;i<=paper;i++){
        printf("%d -> ",i);
        dfs(i);
        for(int i=0;i<101;i++){
            visited[i] = 0;
        }
        bubblesort();
        printf("\n");
    }
    return 0;
}
