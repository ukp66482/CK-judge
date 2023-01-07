#include <stdio.h>

void solve(char s[100001])
{
    //printf("%s\n",s);
    int len = strlen(s);

    if( len == 1 )
    {
        ans[answer_idx++] = s[0];
        return;
    }

    long long total1 = 0,total2 = 0;

    for(int i=0;i<len;i++)
    {
        if( i % 2 == 0 )
        {
            if( s[i] >= 'a' && s[i] <= 'z' ) total1 += 10 + ( s[i] - 'a' );
            else total1 += s[i] - '0';
        }
        else
        {
            if( s[i] >= 'a' && s[i] <= 'z' ) total2 += 10 + ( s[i] - 'a' );
            else total2 += s[i] - '0';
        }
    }

    long long len1 = 0,len2 = 0,total3 = total1,total4 = total2;
    while( total3 != 0 ) total3 /= 16,len1++;
    while( total4 != 0 ) total4 /= 16,len2++;

    char odd[100001] = {},even[100001] = {};
    odd[0] = even[0] = '0';

    while( total1 != 0 )
    {
        char u;
        if( total1 % 16 >= 10 ) u = (char)( total1 % 16 - 10 + 'a' );
        else u = total1 % 16 + '0';

        even[--len1]= u;
        total1 /= 16;
    }

    while( total2 != 0 )
    {
        char u;
        if( total2 % 16 >= 10 ) u = (char)( total2 % 16 - 10 +'a' );
        else u = total2 % 16 + '0';

        odd[--len2]= u;
        total2 /= 16;
    }

    solve(even);
    solve(odd);

    return;
}

int main()
{
    char s[100001];
    scanf("%s",s);
    int len = strlen(s);
    for(int i=0;i<len;i++) if( s[i] >= 'A' && s[i] <= 'Z' ) s[i] += ( 'a' - 'A' );
    solve(s);

    for(int i=0;i<answer_idx;i++)
    {
        printf("%c",ans[i]);
    }
}
