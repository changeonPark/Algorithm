#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* initNode(int data, Node* leftchild, Node* rightchild){//create node
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftchild;
    node->rightChild = rightchild;
    return node;
}

void preorder(Node* root){//전위 순회
    if(root){
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
    }
}

void inorder(Node* root){//중위 순회
    if(root){
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

void postorder(Node* root){//후위 순회
    if(root){
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

void main(){
    Node* n7 = initNode(50, NULL, NULL);
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, n6, n7);
    Node* n2 = initNode(17, n4, n5);
    Node* n1 = initNode(30, n2, n3);
    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);
    printf("\n");
}