#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 15

void convert (char *last, char *first){
    int length_last,length_first;
    length_first = strlen(last);
    length_last = strlen(first);
    if(length_first > 15 || length_last > 15){
        printf("illegal");
        return;
    }
    for(int i=0;last[i]!='\0';i++){
        if(last[i]==' '){
            printf(" ");
        }else if(last[i]>=97 && last[i]<=122){
            last[i]= last[i]-32;
            printf("%c", last[i]);
        }else{
            printf("%c",last[i]);
        }
    }
    printf(", ");
    for(int i=0;first[i]!='\0';i++){
        if(first[i]==' '){
            printf("-");
        }else if(first[i]>=97 && first[i]<=122){
            first[i]= first[i]-32;
            printf("%c", first[i]);
        }else{
            printf("%c",first[i]);
        }
    }
}

int main()
{
    char last_name[MAX_LEN + 2];
    char first_name[MAX_LEN + 2];

    // Enter last name
    fgets(last_name, MAX_LEN*2 , stdin);
    if(last_name[strlen(last_name) - 1] == '\n')
        last_name[strlen(last_name) - 1] = '\0';

    // Enter first name
    fgets(first_name, MAX_LEN*2, stdin);
    if(first_name[strlen(first_name) - 1] == '\n')
        first_name[strlen(first_name) - 1] = '\0';

    // Convert and print the name by using the function convert
    convert(last_name, first_name);

    return 0;
}