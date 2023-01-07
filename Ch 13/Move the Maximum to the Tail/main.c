#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void MoveToTail(){
    struct node* max = head;
    struct node* p = head;
    struct node* prev = NULL;
    if(head!=tail) {
        for (; p != NULL; p = p->next) {
            if (max->val < p->val) {
                max = p;
            }
        }
        for (p = head; p->val != max->val; prev = p, p = p->next) {
        }
        if(prev!=NULL) {
            prev->next = p->next;
        }else{
            head = p->next;
        }
        for (p = head; p != NULL; prev = p, p = p->next) {
        }
        prev->next = max;
        max->next = NULL;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}