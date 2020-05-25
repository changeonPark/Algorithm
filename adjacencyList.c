#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int idx;
    int distance;
    struct Node* next;
}Node;

void add(Node* root, int idx, int distance){
    Node* node = (Node*)malloc(sizeof(Node));
    node->idx = idx;
    node->distance = distance;
    node->next = root->next;
    root->next = node;
}

void show(Node* root){
    Node* cur = root->next;
    while(cur != NULL){
        printf("%d(distanc: %d) ", cur->idx, cur->distance);
        cur = cur->next;
    }
}

void main(){
    int node, edge;
    printf("���� ������ ���� �Է��ϼ���: ");
    scanf("%d %d", &node, &edge);

    Node** arr = (Node**)malloc(sizeof(Node*) * node);

    //�Է¹��� �� ��ŭ �� ������ ����� ����Ű�� ������ NULL�� �ǵ��� �ʱ�ȭ�Ѵ�.
    for(int i = 0; i < node; i++){
        arr[i] = (Node*)malloc(sizeof(Node));
        arr[i]->next = NULL;
    }
    //�Է¹��� ������ ����ŭ add�Լ��� ���� ������ ���� �ְ� ������ �����Ѵ�.
    for(int i = 0; i < edge; i++){
        int num, idx, distance;
        printf("���� ���� ������ ���, �Ÿ��� �Է��ϼ���: ");
        scanf("%d %d %d", &num, &idx, &distance);
        add(arr[num], idx, distance);
    }
    //�� ������ ���� ������ ������ ����Ѵ�.
    for(int i = 0; i < node; i++){
        printf("���� [%d] : ", i);
        show(arr[i]);
        printf("\n");
    }
}