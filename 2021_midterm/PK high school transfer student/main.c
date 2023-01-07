#include <stdio.h>

int main() {
    int student_num;
    int transfer_len;
    int ans= 0;
    char transfer_name[18]={0};
    char student_name[18]={0};
    scanf("%d",&student_num);
    scanf("%d ",&transfer_len);

    for(int i=0;i<transfer_len;i++){
        scanf("%c",&transfer_name[i]);
        if(transfer_name[i]>='A'&&transfer_name[i]<='Z'){
            transfer_name[i] += 32;
        }
    }

    for(int i=0;i<student_num;i++){
        int student_len;
        int min_len;
        scanf("%d ",&student_len);
        for(int j=0;j<student_len;j++){
            scanf("%c",&student_name[j]);
            if(student_name[j]>='A'&&student_name[j]<='Z'){
                student_name[j] += 32;
            }
        }

        if(student_len<transfer_len){
            min_len = student_len;
        }else{
            min_len = transfer_len;
        }

        int temp_len = 0;

        for(int j=0;j<min_len;j++){
            if(student_name[j]>transfer_name[j]){
                break;
            }
            if(student_name[j]<transfer_name[j]){
                ans++;
                break;
            }
            temp_len++;
            if(temp_len == min_len){
                if(min_len==student_len){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans+1);
    return 0;
}
