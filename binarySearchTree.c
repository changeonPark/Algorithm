#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* leftchild;
    struct Node* rightchild;
}Node;
//노드 생성 함수
Node* insert(Node* root, int data){
    if(root == NULL){//노드 생성
        root = (Node*)malloc(sizeof(Node));
        root->leftchild = root->rightchild = NULL;
        root->data = data;
        return root;
    }
    else{
        if(root->data > data){//새로 추가할 노드가 현재 노드보다 작은 경우
            root->leftchild = insert(root->leftchild, data);
        }
        else{//새로 추가할 노드가 현재 노드보다 큰 경우
            root->rightchild = insert(root->rightchild, data);
        }
    }
    return root;
}
//전위 순회 함수
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->leftchild);
    printf("%d ", root->data);
    inorder(root->rightchild);
}
//특정 값보다 큰 수중 제일 작은 수를 찾는다.
Node* findMin(Node* root){
    Node* node = root;
    while(node->leftchild != NULL) node = root->leftchild;
    return node;
}

Node* delete(Node* root, int data){
    Node* node = NULL;//null초기화 필수: 양쪽 자식이 없는 경우 null값을 반환해야 하므로
    if(root == NULL) return NULL;
    
    //이하의 조건들을 모두 불만족 시 현재의 값을 그대로 반환한다.
    if(root->data > data) root->leftchild = delete(root->leftchild, data);
    else if(root->data < data) root->rightchild = delete(root->rightchild, data);
    else{//현재 노드와 지우려는 값이 일치할 경우
        if(root->leftchild != NULL && root->rightchild != NULL){//양쪽 자식이 모두 있다
            node = findMin(root->rightchild);//우측 노드 중 최솟값을 찾는다
            root->data = node->data;//최솟값을 지우려는 값의 위치로 이동
            root->rightchild = delete(root->rightchild, node->data);//최솟값 삭제
        }
        else{
            node = (root->leftchild != NULL) ? root->leftchild : root->rightchild;
            free(root);
            return node;
        }
    }
    return root;
}

void main(){
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 17);
    root = insert(root, 48);
    root = insert(root, 5);
    root = insert(root, 23);
    root = insert(root, 37);
    root = insert(root, 50);
    root = delete(root, 17);
    inorder(root);
}
