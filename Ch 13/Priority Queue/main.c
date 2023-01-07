#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight){
    node_t *newnode = malloc(sizeof (node_t));
    newnode->value = value;
    newnode->weight = weight;

    if(!(queue->head)){ //queue is empty
        newnode->next = NULL;
        queue->head = newnode;
    }else{ //there's something in queue
        node_t *curr = queue->head;
        node_t *prev = NULL;
        for(;curr && weight>=curr->weight;prev = curr, curr = curr->next);
        if(!prev){ //insert in front
            newnode->next = curr;
            queue->head = newnode;
        }else{ //insert in middle or tail
            prev->next = newnode;
        }
        if(!curr){ // insert in tail
            curr = newnode;
            newnode->next = NULL;
        }else{ //insert in middle
            newnode->next = curr;
        }
    }
}

node_t *dequeue(prio_queue_t * const queue){
    if(!queue->head){ //queue is empty
        return NULL;
    }else{ //remove front
        node_t *temp = queue->head;
        queue->head = queue->head->next;
        return temp;
    }
}

void print_nodes(const prio_queue_t * const queue){
    if (!queue->head) {
        printf("EMPTY\n");
        return;
    }
    for (node_t *node = queue->head; node; node = node->next) {
        printf(" -> %d", node->value);
    }
    printf("\n");
    return;
}

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}
