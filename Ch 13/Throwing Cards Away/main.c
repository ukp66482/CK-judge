#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node* insert(int data,node* head){

    node *newnode = malloc(sizeof (node));
    newnode->data = data;
    newnode->prev = NULL;

    if(head==NULL){
        newnode->next = NULL;
        head = newnode;
        return head;
    }else{
        head->prev = newnode;
        newnode->next = head;
        return newnode;
    }
}

int x;

node* delete_tail(node* tail){
    if(tail!=NULL) {
        node *temp = tail;
        x = tail->data;
        if (tail->prev == NULL) {
            free(temp);
            return NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
            return tail;
        }
    }else{
        return NULL;
    }
}

int main() {

    int num,draw;
    node *head = NULL;
    node *tail = NULL;
    scanf("%d %d",&num,&draw);

    for(int i=1;i<=num;i++){
        head = insert(i,head);
    }

    for(tail = head ; tail->next != NULL ; tail = tail->next){}

    for(int i=0;i<draw;i++) {
        tail = delete_tail(tail);
        printf("%d ", x);
        tail = delete_tail(tail);
        head = insert(x, head);
    }

   // printf("\n %d %p %p",x,head->prev,tail->next);
    return 0;
}
