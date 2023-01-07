# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]){
    int i=0,j=0;
    for(;pwd1[i]!='\0';i++){}

    for(;pwd2[j]!='\0';j++){}

    if(i>=6&&i<=16 && j>=6&&j<=16){
        return 0;
    }else{
        return 1;
    }
}

int compare(char pwd1[], char pwd2[]){
    if(strcmp(pwd1,pwd2) == 0){
        return 0;
    }else{
        return 1;
    }
}

int content(char pwd1[]){
    int capital=0,lower=0,num=0;
    for(int i=0;pwd1[i]!='\0';i++){
        if(pwd1[i]>=48&&pwd1[i]<=57){
            num++;
        }else if(pwd1[i]>=65&&pwd1[i]<=90){
            capital++;
        }else if(pwd1[i]>=97&pwd1[i]<=122){
            lower++;
        }
    }
    if(capital>0&&lower>0&&num>0){
        return 0;
    }else{
        return 1;
    }
}

int main()
{
    char password1[SIZE];
    char password2[SIZE];

    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);

    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}