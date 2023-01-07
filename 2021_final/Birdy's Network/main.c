#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    struct node *next;
};

struct node *read_data(int *size){
    *size = 0;
    int temp_num;
    int first = 1;
    char a,b,c,d;
    struct node *adj = malloc(sizeof(struct node)*1000);

    while (scanf("%d",&temp_num)!=EOF){
        if(temp_num == 0){
            first = 1;
            *size= *size + 1;
            scanf("%c",&a);
            continue;
        }
        if(first){
            adj[*size].id = temp_num;
            adj[*size].next = NULL;
            first = 0;
            scanf("%c%c%c%c",&a,&b,&c,&d);
        }else{
            struct node *newNode = malloc(sizeof (struct node));
            newNode->id = temp_num;
            newNode->next = NULL;
            struct node *now = &adj[*size];
            for(;now->next != NULL;now = now->next);
            now->next = newNode;
        }
    }
    //sort
    for(int i=0;i<(*size)-1;i++) {
        for (int j = 0; j < (*size) - 1; j++) {
            if (adj[j].id > adj[j + 1].id) {
                struct node temp = adj[j];
                adj[j] = adj[j + 1];
                adj[j + 1] = temp;
            }
        }
    }
    return adj;
}

void print_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d -> ", adj[i].id);
        for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next) {
            printf("%d ", ptr->id);
        }
        putchar('\n');
    }
    return;
}

void free_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        struct node *ptr = adj[i].next;
        while (ptr) {
            adj[i].next = ptr->next;
            free(ptr);
            ptr = adj[i].next;
        }
    }
    free(adj);
    return;
}

int main() {
    int size;
    struct node *adj = read_data(&size);
    if (!adj) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }
    print_data(adj, size);
    free_data(adj, size);
    return 0;
}