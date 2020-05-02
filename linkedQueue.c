#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int count;
} Queue;

void push(Queue *queue, int data);
void pop(Queue *queue);
void show(Queue *queue);

void main(){
    Queue queue;
    queue.front = queue.rear = NULL; //initialization link to NULL
    queue.count = 0; //not yet input data in NODE

    pop(&queue);
    push(&queue, 1);
    show(&queue);
    push(&queue, 2);
    show(&queue);
    pop(&queue);
    show(&queue);
}

void push(Queue *queue, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL; //if not link to NULL, infinity loop because don`t know next of new node pointing.
    if(queue->count == 0){//first node
        queue->front = node;
    }
    else{
        queue->rear->next = node; //next of last node link to new node
    }
    queue->rear = node;
    queue->count++;
}

void pop(Queue *queue){
    if(queue->count == 0){//none data in queue
        printf("stack underflow\n");
        return;
    }
    Node *node = queue->front;//node link to first node
    queue->front = node->next;
    free(node);
    queue->count--;
}

void show(Queue *queue){
    Node *node = queue->front;
    printf("Start\n");
    while(node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("End\n");
}

