/*
    STACK()
        �������� ���� �������� ������ �ڷ� ����(Data Struct)
        ���� ��� � ���
        ���Ḯ��Ʈ, �迭�� ���� ���� ����

        PUSH: INPUT DATA
        POP: OUTPUT DATA
*/
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

//------------------------------- ARRAY STACK START -------------------------------
#define SIZE 10000

int stack[SIZE];
int arrtop = -1;

void arraypush(int data){//input data
    if(arrtop == SIZE - 1){//max size -> can`t input data
        printf("stack overflow\n");
    }
    stack[++arrtop] = data;
    printf("push tet: %d\n", stack[arrtop]);
}

int arraypop(){
    if(arrtop == -1){//none data
        printf("stack underflow\n");
    }
    arrtop--;
    printf("pop tet\n");
    for(int i = arrtop; i > -1; i--){
        printf("%d\n", stack[i]);
    }
    
    printf("-----------test-----------\n");
    return stack[arrtop];
    
}

void arrayshow(){
    printf("-----------start-----------\n");
    for(int i = arrtop; i > -1; i--){
        printf("%d\n", stack[i]);
    }
    printf("-----------e n d-----------\n");
}


//------------------------------- LINKED STACK START -------------------------------

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *linkedtop;
}Stack;

void linkedpush(Stack *stack, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data; //input data
    node->next = stack->linkedtop; // (ó��)�߰��� ��尡 ž�� �ǵ���, (2��°����~)ž�� ���� ��带 ����Ű�� �����Ƿ� ���� ���Ե� ��尡 ����Ű�� ���� ���� ���� ����
    stack->linkedtop = node; //������ ž�� ���� �߰��� ���� �����Ѵ�.
}

int linkedpop(Stack *stack){
    if(stack->linkedtop == NULL){
        printf("Stack UnderFlow\n");
        return -INF;
    }
    Node *node = stack->linkedtop; //���� ��尪 ������ ���� node����
    int data = node->data;
    stack->linkedtop = node->next;
    free(node);
    return data;

}

void linkedshow(Stack *stack){
    Node *curr = stack->linkedtop;
    printf("--- stack start ---\n");
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    
    printf("--- stack e n d ---\n");
}

void main(){
    /*arraypush(7);
    arraypush(5);
    arraypush(4);
    arraypop();
    arraypush(6);
    arraypop();
    arrayshow();*/

    Stack stack;
    stack.linkedtop = NULL;
    linkedpush(&stack, 7);
    linkedpush(&stack, 5);
    linkedpush(&stack, 4);
    linkedpop(&stack);
    linkedpush(&stack, 6);
    linkedpop(&stack);
    linkedshow(&stack);
}