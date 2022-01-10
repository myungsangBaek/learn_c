#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChilde=leftChild;
    node->rightChild=rightChild;
    return node;
}