#include <stdio.h>

int main() {
    int k;
    char a_or_d,count;
    char message[20000];

    scanf("%d\n",&k);
    k %= 26;
    scanf("%c\n",&a_or_d);
    scanf("%[^\n]",message);

    if(a_or_d == 'a'){
        count=1;
    }else{
        count=-1;
    }

    for(int i=0;message[i]!='\0';i++){
            if(message[i] >= 'A'&& message[i] <= 'Z'){//capital letter
                message[i] += k;
                if(message[i] > 'Z'){
                   message[i] = 'A' + (message[i] - 'Z' - 1);
                }
                if(message[i] < 'A'){
                    message[i] = 'Z' - ('A' - message[i] - 1);
                }
            }else if(message[i] >= 'a'&&message[i] <= 'z'){//lower case
                if((int)message[i] + k > 127){ //overflow
                    int x = 'z' - message[i] + 1;
                    int t = k - x;
                    message[i] = 'a' + t;
                    k+=count;
                    k%=26;
                    continue;
                }
                message[i]+=k;
                if(message[i] > 'z'){
                    message[i] = 'a' + (message[i] - 'z' - 1);
                }
                if(message[i] < 'a'){
                    message[i] = 'z' - ('a' - message[i] - 1);
                }
            }else{
                continue;
        }
        k+=count;
        k%=26;
    }
    printf("%s",message);
    return 0;
}
