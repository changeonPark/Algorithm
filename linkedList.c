#include <stdio.h>
#include <stdlib.h>
/*
    단일 연결 리스트(Linked - List)
        포인터를 이용해 단방향적으로 다음 노드를 가리킴.
        연결 리스트의 시작 노드: HEAD -> 별도로 관리.
        끝 노드의 다음 위치 값으로 NULL.
*/
/*
    연결 리스트의 특징
        삽입, 삭제가 배열에 비해 간단함.
        특정 인덱스로 즉시 접근 불가, 순차적으로 검색.
        추가적인 포인터 변수 사용으로 메모리 공간 낭비.
*/

/*
    연결 리스트는 데이터를 선형적으로 저장, 처리.
    삽입, 삭제 = 연결 리스트
    특정 인덱스 참조 = 배열
*/


//연결 리스트 사용을 위한 구조체.
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void singleCreate(Node *head, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;  //head -
    newNode->next = head->next;
    head->next = newNode;
}

void singleAdd(Node *head, int data){
    Node *addNode = (Node*)malloc(sizeof(Node));
    addNode->data = data;
    addNode->next = head->next;
    head->next = addNode;
}

void singleDel(Node *head){
    Node *delNode = head->next;//head가 가리키는 node 즉, 1번째 노드를 delNode가 가리킴.
    head->next = delNode->next;
    free(delNode);
}

void freeAll(Node *head){
    
    Node *target = head; //head를 비우기 위해  target에 head 삽입.
    Node *temp = target; //head의 next값을 살리기 위해 temp 값에 저장.
    while(target != NULL){
        temp = target->next;
        free(target);
        target = temp;
    }
}

void printNode(Node *head){
    Node *curr = head->next;//순환용 노드
    while (curr != NULL)//curr의 값이 null이 아닐동안 반복.
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

void searchNode(Node *head, int data){
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == data){//입력받은 데이터와 curr이 가르키는 데이터 값이 동일 > 노드를 찾았다!
            printf("찾은 노드의 데이터: %d, 주소: %p\n", curr->data, curr);
            return;
        }
        curr = curr->next;
    }//while문이 탈출된 경우 일치하는 노드가 없는 경우이다.
    printf("찾으려는 노드가 없습니다\n");
}
void main(){
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    
    singleCreate(head, 10);
    singleCreate(head, 20);
    singleCreate(head, 30);
    printNode(head);
    singleAdd(head, 15);
    printNode(head);
    singleDel(head);
    printNode(head);
    searchNode(head, 15);
    searchNode(head, 20);
    freeAll(head);
    printNode(head);
}