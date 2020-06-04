/* Use to Prim`s Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE_MAX 11 //1���� ������ ���̹Ƿ� +1 
#define EDGE_MAX 201 //����� �����̹Ƿ� 100�� x 2

//������ ����� ������ ����� ���� ���� ����ü
typedef struct Edge{
    int cost;
    int node;
}Edge;
//�켱���� ť ����ü
typedef struct PriorityQueue{
    Edge* heap[EDGE_MAX];
    int count;
}PriorityQueue;
//Node�� ������ ���� ����ü
typedef struct Node{
    Edge* data;
    struct Node* next;
}Node;
//x�� y�� ���� �ٲپ��� �Լ�
void Swap(Edge* x, Edge* y){
    Edge temp;
    temp.cost = x->cost;
    temp.node = x->node;
    x->cost = y->cost;
    x->node = y->node;
    y->cost = temp.cost;
    y->node = temp.node;
}
/*�켱 ���� ť*/
//ť ���� �Լ�
void Push(PriorityQueue* pq, Edge* edge){
    if(pq->count >= EDGE_MAX) return; //stack overflow
    pq->heap[pq->count] = edge;//heap�� �� ���� edge ����
    int now = pq->count;
    int parent = (pq->count -1) / 2;
    //��������� �� ���� --> �ּ� �켱���� ť
    while(now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost){
        Swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent -1) / 2;
    }
    pq->count++;
}
//ť ���� �Լ�
Edge* Pop(PriorityQueue* pq){
    if(pq->count <= 0) return NULL;//stack underflow
    Edge* result = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;
    //��������� ����--> ū ���� �Ʒ��� ������.
    while(leftchild < pq->count){
        //���� ����� ���� �ڽ� ��뺸�� Ŭ ��� ���� �ڽ����� �̵�
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost) target = leftchild;
        //���� ����� ������ �ڽ� ��뺸�� Ŭ ��� ������ �ڽ����� �̵�
        if(pq->heap[target]->cost > pq->heap[rightchild]->cost && rightchild < pq->count) target = rightchild;
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
/*���� ���� ����Ʈ ����*/
void AddNode(Node** target, int index, Edge* edge){
    if(target[index] == NULL){//ù ��� ����
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
//���� �˰��� ����
Node** adj;
int arr[NODE_MAX];//�� ���� �湮 ���� Ȯ�ο� �迭

void main(){
    int vertex, edge;
    printf("������ ������ ���� �Է��Ͻÿ�: ");
    scanf("%d %d", &vertex, &edge);
    adj = (Node**)malloc(sizeof(Node*) * (vertex + 1));
    for(int i = 1; i <= vertex; i++) adj[i] = NULL;
    //����� ����
    for(int i = 1; i <= edge; i++){
        printf("������ �� ������ ����ġ�� �Է��Ͻÿ�: ");
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        
        Edge* edge1 = (Edge*)malloc(sizeof(Edge));
        edge1->node = y;
        edge1->cost = cost;
        AddNode(adj, x, edge1);

        Edge* edge2 = (Edge*)malloc(sizeof(Edge));
        edge2->node = x;
        edge2->cost = cost;
        AddNode(adj, y, edge2);
    }
    //start prim`s Algorithm
    PriorityQueue* pq;
    pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->count = 0;

    long long res = 0;
    Edge* start = (Edge*)malloc(sizeof(Edge));
    start->cost = 0; start->node = 1;
    Push(pq, start);
    //start ���� ���� �� ���� while������ node���� ������ �ҷ��� �Ŀ� 126�� while�� ���� �����Ѵ�.
    for(int i = 1; i <= vertex; i++){
        int nextnode = -1, nextcost = INT_MAX;
        while (1){
            Edge* now = Pop(pq);//1��° ��带 ������ now�� ����.
            if(now == NULL) break;
            nextnode = now->node;
            if(!arr[nextnode]){//arr[nextnode]�� �湮�� ������ ������..
             nextcost = now->cost;
             break;
            }
        }
        if(nextcost == INT_MAX) printf("Not Linked Graph\n");
        res += nextcost;
        arr[nextnode] = 1;//�湮 ó��

        Node* cur = adj[nextnode];
        while (cur != NULL){
            Push(pq, cur->data);
            cur = cur->next;
        }  
    }
    printf("%lld\n", res);
}