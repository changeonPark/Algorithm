#include <stdio.h>
#include <stdlib.h>
#include <math.h>//abs() << 절대값 함수

typedef struct Node
{
    int data;
    int height;//높이를 지정해야 시간 복잡도 보장 가능.
    struct Node* leftchild;
    struct Node* rightchild;
}Node;
//현재 노드의 높이를 반환하는 함수
int getHeight(Node* node){
    if(node == NULL) return 0;
    return node->height;
}
//두 값 중 큰 값을 반환시켜주는 함수 setHeight에서 사용함.
int getMax(int a, int b){
    if(a > b) return a;
    else return b;
}
//회전 후 높이를 다시 계산할 때 사용할 함수 --> 왼쪽 자식의 높이 vs 오른쪽 자식의 높이 -> winner + 1
void setHeihgt(Node* node){
    node->height = getMax(getHeight(node->leftchild), getHeight(node->rightchild)) + 1;
}
//LL회전: 왼쪽 자식 노드의 왼쪽에 문제가 발생하였을 경우 => 우회전
Node* rotateLL(Node* node){
    Node* leftchild = node->leftchild;
    node->leftchild = leftchild->rightchild;
    leftchild->rightchild = node;
    setHeihgt(node);
    return leftchild;
}
//RR회전: 오른쪽 자식의 노드의 오른쪽에 문제가 발생하였을 경우 => 좌회전
Node* rotateRR(Node* node){
    Node* rightchild = node->rightchild;
    node->rightchild = rightchild->leftchild;
    rightchild->leftchild = node;
    setHeihgt(node);
    return rightchild;
}
//LR회전: 왼쪽 자식의 노드의 오른쪽에 문제가 발생하였을 경우 ==> 자식 노드에서부터 좌회전 후 노드에서부터 우회전
Node* rotateLR(Node* node){
    Node* leftchild = node->leftchild;
    node->leftchild = rotateRR(leftchild);
    return rotateLL(node);
}
//RL회전: 오른쪽 자식의 노드의 왼쪽에 문제가 발생하였을 경우 ==> 자식 노드에서부터 우회전 후 노드에서부터 좌회전
Node* rotateRL(Node* node){
    Node* rightchild = node->rightchild;
    node->rightchild = rotateLL(rightchild);
    return rotateRR(node);
}
//균형 인수(Balance Factor)를 구하는 함수
int getDifference(Node* node){
    if(node == NULL) return 0;
    Node* leftchild = node->leftchild;
    Node* rightchild = node->rightchild;
    return getHeight(leftchild) - getHeight(rightchild);
}
//AVL트리의 균형을 맞추는 함수
Node* balance(Node* node){
    int diff = getDifference(node);
    if(diff >= 2){//왼쪽 자식 노드쪽에서 문제일 경우
        if(getDifference(node->leftchild) >= 1){
            node = rotateLL(node);
        }
        else{
            node = rotateLR(node);
        }
    }
    else if (diff <= -2){//오른쪽 자식 노드쪽에서 문제일 경우
        if(getDifference(node->rightchild) <= -1){
            node = rotateRR(node);
        }
        else{
            node = rotateRL(node);
        }
    }
    setHeihgt(node);//회전 후 높이 재계산
    return node;
}
//삽입 함수
Node* insert(Node* node, int data){
    if(!node){//노드 생성
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->height = 1;
        node->leftchild = node->rightchild = NULL;
    }
    else if(data < node->data){//왼쪽 자식으로 이동
        node->leftchild = insert(node->leftchild, data);
        node = balance(node);
    }
    else if(data > node->data){
        node->rightchild = insert(node->rightchild, data);
        node = balance(node);
    }
    else{
        printf("데이터 중복입니다!\n");
    }
    return node;
}

Node* root = NULL;//root의 값을 담아줄 Node 생성
//출력값을 보여줄 함수
void display(Node* node, int level){
    if(node != NULL){
        display(node->rightchild, level + 1);//최우측의 노드부터 출력
        printf("\n");
        if(node == root){
            printf("Root: ");
        }
        for(int i = 0; i < level && node != root; i++){
            printf("     ");
        }
        printf("%d(%d)", node->data, getHeight(node));
        display(node->leftchild, level+1);//좌측 노드로 이동
    }
}

void main(){
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 18);
    root = insert(root, 23);
    root = insert(root, 21);
    root = insert(root, 14);
    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 20);
    display(root, 1);
    printf("\n");
}