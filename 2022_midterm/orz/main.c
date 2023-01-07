#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 200000

int N;
int n;
char str[MAX_LEN];

void find_orz(int orz_position[], int *orz_num){
    int k=0;
    for(int i=0;i<N;i++){
        if(str[i]=='o'&&str[i+1]=='r'&&str[i+2]=='z'&&(i+2)<=N){
            orz_position[k++] = i;
            *orz_num = *orz_num +1;
        }
    }
}
void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position){
    int range = right_orz_position - left_orz_position - 3;
    int l=0,type=0,temp[200000];
    for(int i=left_orz_position+3;i<right_orz_position;i++){
        temp[l++] = str[i];
    }
    if(temp)
    worship_amount[n++] = type * range;
}

int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position){
    *range_L = left_orz_position+1;
    *range_R = right_orz_position+1;
    return value;
}

int main()
{
    scanf("%d", &N);
    scanf("%s", str);

    int orz_position[MAX_LEN] = {0}, worship_amount[MAX_LEN] = {0}, orz_num = 0;
    find_orz(orz_position, &orz_num);

    for (int i = 1; i < orz_num; i++)
    {
        calculate_worship(worship_amount, i - 1, orz_position[i - 1], orz_position[i]);
    }

    int max_worship, range_L, range_R;
    for (int i = 0; i < orz_num - 1; i++)
    {
        max_worship = find_max_worship_range(worship_amount[i], &range_L, &range_R, orz_position[i], orz_position[i + 1]);
    }
    printf("%d %d %d\n", max_worship, range_L, range_R);
}
