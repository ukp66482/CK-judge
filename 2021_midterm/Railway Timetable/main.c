#include <stdio.h>

int main() {
    int hh,mm,n,after_train=0,min_i;
    int time[50][50]={0};
    scanf("%d:%d",&hh,&mm);
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d:%d %d",&time[i][0],&time[i][1],&time[i][2],&time[i][3]);
    }

    for(int i=0;i<n;i++){
        if(time[i][1] > hh){
            after_train = i;
            break;
        }
        if(time[i][1]==hh && time[i][2]>=mm){
            after_train = i;
            break;
        }
    }

    for(int i=after_train;i<n;i++){
        int hour = time[i][3]/60;
        int min = time[i][3]%60;
        time[i][1] += hour;
        time[i][2] += min;
        if(time[i][2]>=60){
            time[i][2] = time[i][2] - 60;
            time[i][1] ++;
        }
    }

    min_i = after_train;

    for(int i=after_train;i<n;i++){
        if(time[min_i][1] > time[i][1]){
            min_i = i;
        }else{
            if(time[min_i][2] >= time[i][2] && time[min_i][1] == time[i][1]){
                min_i = i;
            }
        }
    }

    printf("%d",time[min_i][0]);

    return 0;
}
