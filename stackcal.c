#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

char res[1000] = "";

void push(Stack *stack, char *data){
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}

char* pop(Stack *stack){
    if(stack->top == NULL){
        printf("stack underflow\n");
        return NULL;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

char *getTop(Stack *stack){
    Node *top = stack->top;
    return top->data;
}

//후위 표기법 변환 함수
int getPriority(char *i){
    if(!strcmp(i, "(")) return 0;
    if(!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if(!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3;
}


char* transition(Stack *stack, char **s, int size){
    for(int i = 0; i < size; i++){
        if(!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){//연산자일 경우
            while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i]))//본인보다 연산 우선 순위가 높은 경우를 전부 stack에서 뽑고 본인을 stack에 삽입
            {
                strcat(res, pop(stack)); strcat(res, " ");
            }
            push(stack, s[i]);  
        }
        else if(!strcmp(s[i], "(")){
            push(stack, s[i]);
        }
        else if(!strcmp(s[i], ")")){
            while(strcmp(getTop(stack), "(")){//"("가 나오기 전까지 전부 뽑아서 result에 담음
                strcat(res, pop(stack)); strcat(res, " ");
            }
            pop(stack);// "("를 출력하기 위한 pop
        }
        else {
            strcat(res, s[i]); strcat(res, " ");
        }
    }
    while(stack->top != NULL){//잔류 data 출력(stack비우기 위함)
        strcat(res, pop(stack)); strcat(res, " ");
    }
    return res;
}

void calculate(Stack *stack, char **s, int size){
    int x, y, result;
    for(int i = 0; i <size; i++){
        if(!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){
            x = atoi(pop(stack));//연산자일 경우 s[i]의 위에 2개의 수를 출력해 atoi를 통해 char형을 int형으로 변환.
            y = atoi(pop(stack));
            if(!strcmp(s[i], "+")) result = y + x;
            if(!strcmp(s[i], "-")) result = y - x;
            if(!strcmp(s[i], "*")) result = y * x;
            if(!strcmp(s[i], "/")) result = y / x;

            char buf[100];
            sprintf(buf, "%d", result); //int형을 char형으로 재전환.
            push(stack, buf);//연산값을 push해줌.
        }
        else
        {
            push(stack, s[i]);
        }
    }
    printf("%s ", pop(stack));
}

void main(){
    Stack stack;
    stack.top = NULL;
    char arr[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
    int size = 1;
    for(int i = 0; i < strlen(arr); i++){
        if(arr[i] == ' ') size++;
    }
    char *ptr = strtok(arr, " ");//arr에서 공백전까지 잘라냄.

    char **input = (char**)malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){
        input[i] = (char*)malloc(sizeof(char) * 100);
    }

    for(int i = 0; i < size; i++){
         strcpy(input[i], ptr);
         ptr = strtok(NULL, " ");
        
    }
    char buf[1000] = "";
    strcpy(buf, transition(&stack, input, size));
    printf("후위 표기법 : %s\n", buf);

    size = 1;
    for(int i = 0; i < strlen(buf) - 1; i++){//마지막에 공백이 들어감으로 1을 빼준다.
        if(buf[i] == ' ') size++;
    }

    char *ptr2 = strtok(buf, " ");
    for(int i = 0; i < size; i++){
        strcpy(input[i], ptr2);
         ptr2 = strtok(NULL, " ");
    }

    calculate(&stack, input, size);

}