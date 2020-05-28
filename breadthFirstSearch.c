#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX 1000

//������ ������ ���� Node struct
typedef struct Node
{
    int index;
    struct Node* next;
}Node;

//�湮 ������ ���� Queue struct
typedef struct Queue
{
    Node* front;
    Node* rear;
    int cnt;
}Queue;

Node** a;//�� ������ ������ �������� ������ ���� 2���� ������ �迭
int node, edge, check[MAX];//������ ��, ������ ��, �� ���� �湮 Ȯ�ο� �迭

//������ ���� ������ ���� ��带 �����ϴ� ���Ḯ��Ʈ �Լ�
void add(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush(Queue* queue, int index){
    //ť�� ���� ������ �����ϱ� ���� ���
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    //ť�� ���ʷ� �����Ͱ� �� ���
    if(queue->cnt == 0){
        queue->front = node;
    }
    else{//�̹� ť�� �����Ͱ� ���� ��� ���� �� ����� �������� ����
        queue->rear->next = node;
    }
    //rear�� ����Ű�� ��ġ�� ���� ������ ��带 ����Ű�� ���ش�
    queue->rear = node;
    //ť�� ���ο� ��尡 �߰��Ǿ����Ƿ� cnt�� ���������ش�
    queue->cnt++;
}

int queuePop(Queue* queue){
    //ť�� �ƹ��� �����͵� ���� ���
    if(queue->cnt == 0){
        printf("queue underflow!\n");
        return -INF;
    }
    //ť�� �����Ͱ� ���� ���
    //ť�� ������ ������ ��带 ������ front�� ����Ű�� ����� ������ ��´�.
    Node* node = queue->front;
    //index������ node�� ����� index�� ���� �����Ѵ�(��ȯ�ϱ� ����)
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->cnt--;
    return index;
}

void bfs(int start){
    //ť �ʱ�ȭ
    Queue que;   
    que.front = que.rear = NULL;
    que.cnt = 0;
    //ť�� ������ �߰�
    queuePush(&que, start);
    //start��° ���� �湮 ó��
    check[start] = 1;

    //que�� ��� �����Ͱ� ���� �� ���� �ݺ��Ѵ�
    while(que.cnt != 0){
        //�湮�� ��� ���� �� ���
        int x = queuePop(&que);
        printf("%d ", x);
        //���� �湮�� ����� ���� ����� ������ cur�� ����
        Node* cur = a[x]->next;
        //��� ��带 �湮�� ������ �ݺ�
        while (cur != NULL)
        {
            //���� ����� index�� next�� ����
            int next = cur->index;
            //check[next] != 0 -->�湮���� ���� ����� ���
            if (!check[next])
            {
                //ť�� �߰����ְ� �湮ó�� ���ش�.
                queuePush(&que, next);
                check[next] = 1;
            }
            cur = cur->next;        
        }
    }
}

void main(){
    printf("������ ���� ������ ���� �Է��ϼ���: ");
    scanf("%d %d", &node, &edge);
    a = (Node**)malloc(sizeof(Node*) * MAX);

    for(int i = 0; i < node; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    for (int i = 0; i < edge; i++){
        int x, y;
        printf("������ �� ������ �Է��ϼ���: ");
        scanf("%d %d", &x, &y);
        add(a[x], y);
        add(a[y], x);
    }
    bfs(0);
}