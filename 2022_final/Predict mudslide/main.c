#include <stdio.h>

int num = 0;
int map[5][5] = {0};

void mud(int x,int y){
    if(x == 5 || y == 5 || x == -1 || y == -1 || map[x][y] == 1){
        return;
    }

    if(map[x][y]==2){
        num++;
        map[x][y] = -1;
        mud(x-1,y);
        mud(x+1,y);
        mud(x,y+1);
        mud(x,y-1);
    }
    if(map[x][y] == 0) {
        map[x][y] = -1;
        mud(x - 1, y);
        mud(x + 1, y);
        mud(x, y + 1);
        mud(x, y - 1);
    }
}

int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&map[i][j]);
        }
    }

    mud(x,y);

    printf("%d",num);

    return 0;
}
