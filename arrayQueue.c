#include <stdio.h>

#define SIZE 4

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data);
void pop();
void show();

void main(){
    pop();
    push(1);
    push(2);
    pop();
    push(3);
    show();
    push(4);
    show();
    push(5);
    show();
    push(6);

}

void push(int data){
    if(rear >= SIZE){
        printf("stack overflow\n");
        return;
    }
    queue[rear++] = data;
}

void pop(){
    if(front == rear){
        printf("stack underflow\n");
        return;
    }
    front++;
}

void show(){
    printf("start queue\n");
    for(int i = front; i < rear; i++){
        printf("%d\n", queue[i]);
    }
    printf("end queue\n");
}