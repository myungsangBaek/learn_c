#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
//삽입함수
Node* insertNode(Node* root, int data){
    if(root ==NULL){
    root = (Node*)malloc(sizeof(Node));
    root->leftChild = root->rightChild = NULL;
    root->data = data;
    return root; //루트 초기화
    }
    else{
        if(root->data > data) {
        root->leftChild = insertNode(root->leftChild, data);
        }
        else{
        root->rightChild = insertNode(root->rightChild, data);
        }
    }
    return root;
}
//탐색함수
Node* searchNode(Node* root, int data){
    if (root == NULL) return NULL;
    if(root->data == data) return root;
    else if (root->data > data) return searchNode(root->leftChild, data);
    else return searchNode(root->rightChild, data);
}

//이진 탐색 트리의 순회

void preorder(Node* root){
    if (Root == NULL) return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

//이진 탐색 트리 이용

int main(Void){
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, );
    root = insertNode(root, 30);
    root = insertNode(root, 30);
}