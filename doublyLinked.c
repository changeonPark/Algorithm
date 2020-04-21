#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

/*
삽입 방법
1. 앞 노드 -> 새로운 노드(next)
2. 새로운 노드 -> 앞 노드(prev)
3. 뒷 노드 -> 새로운 노드(prev)
4. 새로운 노드 -> 뒷 노드(next)
*/
void insert(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node *curr = head->next;
    //curr->data가 입력받은 data 보다 작고, tail이 아닐경우
    //오름차 정렬이므로 1번째 노드부터 tail전까지(입력받은 수보다 작을 동안)
    while (curr->data <= data && curr != tail)
    {
        if(curr->data == data){//중복 노드를 받지 않을 시 사용.
            printf("이미 입력된 노드입니다.\n");
            return;
        }
        curr = curr->next; //이동
    }
    //while문 종료시 입력받은 data가 들어가야할 위치를 가리킴.
    Node *prev = curr->prev;//양방향이므로 새로 들어갈 노드의 이전 노드를 가리킬 필요가 있음.
    prev->next = node;
    node->prev = prev;
    curr->prev = node;
    node->next = curr;
    printf("%d\n", node->data);
}

void delelte(int data){
    Node *node = head->next;
    while(node != tail){//head부터 tail까지 반복
        if(data == node->data){
            Node *prev = node->prev; //지울 노드의 이전 노드 포인터
            Node *next = node->next; //지울 노드의 다음 노드 포인터
            prev->next = node->next; //이전 노드의 next를 node의 next값으로 변경.
            next->prev = node->prev; //다음 노드의 prev를 node의 prev값으로 변경.
            free(node);//노드 삭제
            return;//함수 탈출
        }
        node = node->next;//다음 노드로 이동.
    }
    printf("찾으려는 노드가 없습니다\n");
    return;
}

void show(){
    Node *node = head->next; //노드에 초기값 적용.
    printf("START -> ");
    while(node != tail){//head->tail
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void main(){
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;//초기값
    tail->next = tail; //초기값
    tail->prev = head;
    insert(2);
    insert(5);
    insert(3);
    insert(1);
    insert(2);
    delelte(10);
    show();
}