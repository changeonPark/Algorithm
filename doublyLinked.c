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
���� ���
1. �� ��� -> ���ο� ���(next)
2. ���ο� ��� -> �� ���(prev)
3. �� ��� -> ���ο� ���(prev)
4. ���ο� ��� -> �� ���(next)
*/
void insert(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node *curr = head->next;
    //curr->data�� �Է¹��� data ���� �۰�, tail�� �ƴҰ��
    //������ �����̹Ƿ� 1��° ������ tail������(�Է¹��� ������ ���� ����)
    while (curr->data <= data && curr != tail)
    {
        if(curr->data == data){//�ߺ� ��带 ���� ���� �� ���.
            printf("�̹� �Էµ� ����Դϴ�.\n");
            return;
        }
        curr = curr->next; //�̵�
    }
    //while�� ����� �Է¹��� data�� ������ ��ġ�� ����Ŵ.
    Node *prev = curr->prev;//������̹Ƿ� ���� �� ����� ���� ��带 ����ų �ʿ䰡 ����.
    prev->next = node;
    node->prev = prev;
    curr->prev = node;
    node->next = curr;
    printf("%d\n", node->data);
}

void delelte(int data){
    Node *node = head->next;
    while(node != tail){//head���� tail���� �ݺ�
        if(data == node->data){
            Node *prev = node->prev; //���� ����� ���� ��� ������
            Node *next = node->next; //���� ����� ���� ��� ������
            prev->next = node->next; //���� ����� next�� node�� next������ ����.
            next->prev = node->prev; //���� ����� prev�� node�� prev������ ����.
            free(node);//��� ����
            return;//�Լ� Ż��
        }
        node = node->next;//���� ���� �̵�.
    }
    printf("ã������ ��尡 �����ϴ�\n");
    return;
}

void show(){
    Node *node = head->next; //��忡 �ʱⰪ ����.
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
    head->prev = head;//�ʱⰪ
    tail->next = tail; //�ʱⰪ
    tail->prev = head;
    insert(2);
    insert(5);
    insert(3);
    insert(1);
    insert(2);
    delelte(10);
    show();
}