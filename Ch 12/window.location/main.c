#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;

} Location;

    char *slash = "";
Location *parse_url(char *url){
    Location *location = malloc(sizeof (Location));
    location->protocol = "";
    location->host = "";
    location->pathname = "";
    location->search = "";
    location->hash = "";
    char *temp;
    char *temp2;
    int temp_num = 0,number_sign = 0,question_mark = 0;

    for(int i=0;url[i]!='\n';i++){
        switch (url[i]) {
            case '?':
                question_mark = 1;
                break;
            case '#':
                number_sign = 1;
                break;
            default:;
        }
    }

    url = strtok(url,"\n"); //url last character is \n

    location->protocol = strtok(url,"://");
    location->host = strtok(NULL,"/?#"); //host + port
    temp2 = strtok(NULL,"\0"); //behind host + port

    //find port
    temp = strtok(location->host,":");//host
    temp = strtok(NULL,"\0");//port

    if(temp!=NULL) {
        for (int i = 0; temp[i] != '\0'; i++) {
            temp_num = temp_num*10 + (temp[i]-'0');
        }
    }
    location->port = temp_num;

     //printf("%s\n",temp2);

    if(question_mark == 0 && number_sign == 0){ //behind post there is only pathname
        location->pathname = temp2;
    }else if(strchr(temp2,'#') == temp2 || strchr(temp2,'?') == temp2){
        location->pathname = slash;
        if(question_mark == 0 && number_sign == 1){
            location->hash = strtok(temp2,"#");
        }else if(question_mark == 1 && number_sign == 0){
            location->search = strtok(temp2,"?");
        }else if(question_mark == 1 && number_sign == 1){
            temp2 = temp2 + 1;
            location->search = strtok(temp2,"#");
            location->hash = strtok(NULL,"\0");
        }
    }else if(question_mark == 0 && number_sign == 1){ //behind host there are path and hash
        if(!strchr(temp2,'#')) { //no path only hash
            location->hash = temp2;
        }else{
            location->pathname = strtok(temp2,"#"); //pathname
            location->hash = strtok(NULL,"\0"); //hash
        }
    }else if(question_mark == 1 && number_sign == 0){ //behind host there are path and search
        if(!strchr(temp2,'?')) { //no path only search
            location->search = temp2;
        }else{
            location->pathname = strtok(temp2,"?"); //path
            location->search = strtok(NULL,"\0"); //search
        }
    }else if(question_mark == 1 && number_sign == 1 ){ //path search hash
        int check = 0;
        for(int i=0;temp2[i]!='\0';i++){
            if(temp2[i]=='?'){
                check=1;
            }
        }
        if(check) {
            location->pathname = strtok(temp2, "?");
            location->search = strtok(NULL, "#");
            location->hash = strtok(NULL, "\0");
        }else{
            location->search = strtok(temp2, "#");
            location->hash = strtok(NULL, " ");
        }
    }

    if(location->pathname==NULL){
        location->pathname = "";
    }
    if(location->search==NULL){
        location->search = "";
    }
    if(location->hash==NULL){
        location->hash = "";
    }

    return location;
}

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
