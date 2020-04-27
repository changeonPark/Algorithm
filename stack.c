/*
    STACK()
        한쪽으로 들어가서 한쪽으로 나오는 자료 구조(Data Struct)
        수식 계산 등에 사용
        연결리스트, 배열을 통해 구현 가능

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
    node->next = stack->linkedtop; // (처음)추가된 노드가 탑이 되도록, (2번째부터~)탑이 이전 노드를 가리키고 있으므로 현재 삽입된 노드가 가리키는 곳을 이전 노드로 설정
    stack->linkedtop = node; //스택의 탑을 현재 추가한 노드로 변경한다.
}

int linkedpop(Stack *stack){
    if(stack->linkedtop == NULL){
        printf("Stack UnderFlow\n");
        return -INF;
    }
    Node *node = stack->linkedtop; //현재 노드값 저장을 위해 node생성
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