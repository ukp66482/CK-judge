#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_MAX 2048
#define KEY_MAX 100

typedef struct search_s {
    char *key;
    char *value;
} search_t;

search_t *get_param_by_key(char *url, char *key){
    char *temp2;
    static char test[2048];
    search_t *param = malloc(sizeof (search_t));
    temp2 = strtok(url,"?");
    temp2 = strtok(NULL,"#");
    //printf("%s\n",temp2);

    for (temp2 = strtok(temp2, "#&"); temp2 != NULL;){
       // printf("%s\n",temp2);
        strcpy(test,temp2);
        int i=0;

        for(;test[i]!='=';i++){}
        test[i] = '\0';

        if(strcmp(key,test) == 0){
            param->key = key;
            param->value = &test[i] + 1;
            return param;
        }
        memset(test,'\0',2048);
        temp2 = strtok(NULL,"#&");
    }
    return NULL;
}

int main ()
{
    char url[URL_MAX + 1], key[KEY_MAX + 1];

    fgets(url, URL_MAX, stdin);
    scanf("%s", key );

    search_t  *param = get_param_by_key (url, key);

    if (param)
        printf("key: %s, value: %s", param->key, param->value);
    else
        printf("404 Not Found");
}