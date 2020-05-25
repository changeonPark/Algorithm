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
    printf("노드와 간선의 수를 입력하세요: ");
    scanf("%d %d", &node, &edge);

    Node** arr = (Node**)malloc(sizeof(Node*) * node);

    //입력받은 수 만큼 빈 정점을 만들고 가리키는 방향이 NULL이 되도록 초기화한다.
    for(int i = 0; i < node; i++){
        arr[i] = (Node*)malloc(sizeof(Node));
        arr[i]->next = NULL;
    }
    //입력받은 간선의 수만큼 add함수를 통해 정점에 값을 넣고 간선을 연결한다.
    for(int i = 0; i < edge; i++){
        int num, idx, distance;
        printf("현재 노드와 연결할 노드, 거리를 입력하세요: ");
        scanf("%d %d %d", &num, &idx, &distance);
        add(arr[num], idx, distance);
    }
    //각 정점에 대한 간선의 정보를 출력한다.
    for(int i = 0; i < node; i++){
        printf("원소 [%d] : ", i);
        show(arr[i]);
        printf("\n");
    }
}