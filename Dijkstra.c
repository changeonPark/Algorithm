/* Dijkstra`s Sortest Path Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE_MAX 10
#define EDGE_MAX 200//양방향 간선
/* Struct */
//정점과 비용의 정보를 담을 구조체
typedef struct Edge{
    int cost;
    int node;
}Edge;
//우선순위 큐 구조체
typedef struct PriorityQueue{
    Edge* heap[EDGE_MAX];
    int count;
}PriorityQueue;
//간선의 정보를 담을 구조체
typedef struct Node{
    Edge* data;
    struct Node* next;
}Node;

Node** g_adj; //연결한 두 정점과 간선의 비용을 저장하기 위한 2차원 배열
int g_answer[NODE_MAX]; //특정한 노드까지의 최단 거리 값 저장하기 위한 배열
/* Function */
//a와 b의 값을 바꾸어주는 함수
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
    //새 원소 삽입 후 최소값 상향식 힙 구성
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
    Edge* result = pq->heap[0];//첫번째 노드 추출하여 result에 저장
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;
    //하향식으로 구성
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
//연결 리스트 추가
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
    printf("정점과 간선의 수, 시작할 정점을 입력하세요: ");
    scanf("%d %d %d", &vertex, &edge, &startnode);
    g_adj = (Node**)malloc(sizeof(Node));
    for(int i = 1; i <= vertex; i++){
        g_adj[i] = NULL;
        g_answer[i] = INT_MAX;
    }
    //단방향 간선 생성
    for(int i = 0; i < edge; i++){
        int x, y, cost;
        printf("연결할 두 정점, 연결될 정점, 비용을 입력하세요: ");
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
    g_answer[startnode] = 0;//1번 노드-> 1번 노드의 가중치 = 0
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