/* Dijkstra`s Sortest Path Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE_MAX 10
#define EDGE_MAX 200//����� ����
/* Struct */
//������ ����� ������ ���� ����ü
typedef struct Edge{
    int cost;
    int node;
}Edge;
//�켱���� ť ����ü
typedef struct PriorityQueue{
    Edge* heap[EDGE_MAX];
    int count;
}PriorityQueue;
//������ ������ ���� ����ü
typedef struct Node{
    Edge* data;
    struct Node* next;
}Node;

Node** g_adj; //������ �� ������ ������ ����� �����ϱ� ���� 2���� �迭
int g_answer[NODE_MAX]; //Ư���� �������� �ִ� �Ÿ� �� �����ϱ� ���� �迭
/* Function */
//a�� b�� ���� �ٲپ��ִ� �Լ�
void Swap(Edge* a, Edge* b){
    Edge temp;
    temp.cost = a->cost;
    temp.node = a->node;
    a->cost = b->cost;
    a->node = b->node;
    b->cost = temp.cost;
    b->node = temp.node;
}
//Queue Push Function
void Push(PriorityQueue* pq, Edge* edge){
    if(pq->count >= EDGE_MAX) return; //stack overflow
    pq->heap[pq->count] = edge;
    int now = pq->count;
    int parent = (now - 1) / 2;
    //�� ���� ���� �� �ּҰ� ����� �� ����
    while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost){
        Swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (now - 1) / 2;
    }
    pq->count++;
}
//Queue Pop Function
Edge* Pop(PriorityQueue* pq){
    if(pq->count <= 0) return NULL;
    Edge* result = pq->heap[0];//ù��° ��� �����Ͽ� result�� ����
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;
    //��������� ����
    while (leftchild < pq->count){
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost) target = leftchild;
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost && rightchild < pq->count) target = rightchild;
        
        if(target == now) break;
        else{
            Swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
        }
    }
    return result;
}
//���� ����Ʈ �߰�
void AddNode(Node** target, int index, Edge* edge){
    if(target[index] == NULL){
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    }
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}

void main(){
    int vertex, edge, startnode;
    printf("������ ������ ��, ������ ������ �Է��ϼ���: ");
    scanf("%d %d %d", &vertex, &edge, &startnode);
    g_adj = (Node**)malloc(sizeof(Node));
    for(int i = 1; i <= vertex; i++){
        g_adj[i] = NULL;
        g_answer[i] = INT_MAX;
    }
    //�ܹ��� ���� ����
    for(int i = 0; i < edge; i++){
        int x, y, cost;
        printf("������ �� ����, ����� ����, ����� �Է��ϼ���: ");
        scanf("%d %d %d", &x, &y, &cost);

        Edge* input = (Edge*)malloc(sizeof(Edge));
        input->node = y;
        input->cost = cost;
        AddNode(g_adj, x, input);
    }
    //startnode Dijkstra Algorithm
    PriorityQueue* pq;
    pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->count = 0;
    
    Edge* startedge = (Edge*)malloc(sizeof(Edge));
    startedge->node = startnode, startedge->cost = 0;
    g_answer[startnode] = 0;//1�� ���-> 1�� ����� ����ġ = 0
    Push(pq, startedge);

    while (1){
        Edge* now = Pop(pq);
        if(now == NULL) break;
        int curnode = now->node, curcost = now->cost;
        if(g_answer[curnode] < curcost) continue;
        
        Node* cur = g_adj[curnode];
        while (cur != NULL){
            Edge* temp = cur->data;
            temp->cost += curcost;
            if(temp->cost < g_answer[temp->node]){
                g_answer[temp->node] = temp->cost;
                Push(pq, temp);
            }
            cur = cur->next;
        }
    }

    for(int i = 1; i <= vertex; i++){
        if(g_answer[i] == INT_MAX) printf("INF\n");
        else printf("%d\n", g_answer[i]);
    }
    
}