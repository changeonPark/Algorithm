#include <stdio.h>
#include <stdlib.h>
/*
    ���� ���� ����Ʈ(Linked - List)
        �����͸� �̿��� �ܹ��������� ���� ��带 ����Ŵ.
        ���� ����Ʈ�� ���� ���: HEAD -> ������ ����.
        �� ����� ���� ��ġ ������ NULL.
*/
/*
    ���� ����Ʈ�� Ư¡
        ����, ������ �迭�� ���� ������.
        Ư�� �ε����� ��� ���� �Ұ�, ���������� �˻�.
        �߰����� ������ ���� ������� �޸� ���� ����.
*/

/*
    ���� ����Ʈ�� �����͸� ���������� ����, ó��.
    ����, ���� = ���� ����Ʈ
    Ư�� �ε��� ���� = �迭
*/


//���� ����Ʈ ����� ���� ����ü.
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
    Node *delNode = head->next;//head�� ����Ű�� node ��, 1��° ��带 delNode�� ����Ŵ.
    head->next = delNode->next;
    free(delNode);
}

void freeAll(Node *head){
    
    Node *target = head; //head�� ���� ����  target�� head ����.
    Node *temp = target; //head�� next���� �츮�� ���� temp ���� ����.
    while(target != NULL){
        temp = target->next;
        free(target);
        target = temp;
    }
}

void printNode(Node *head){
    Node *curr = head->next;//��ȯ�� ���
    while (curr != NULL)//curr�� ���� null�� �ƴҵ��� �ݺ�.
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

void searchNode(Node *head, int data){
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == data){//�Է¹��� �����Ϳ� curr�� ����Ű�� ������ ���� ���� > ��带 ã�Ҵ�!
            printf("ã�� ����� ������: %d, �ּ�: %p\n", curr->data, curr);
            return;
        }
        curr = curr->next;
    }//while���� Ż��� ��� ��ġ�ϴ� ��尡 ���� ����̴�.
    printf("ã������ ��尡 �����ϴ�\n");
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