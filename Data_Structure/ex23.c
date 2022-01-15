#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b){
    if (a > b) return a;
    return b;
}

typedef struct {
    int data;
    int height; //높이를 저장해야 시간 복잡도를 보장할 수 있음
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

//높이 계산 함수

int getHeight(Node* node){
    if (node == NULL) return 0;
    return node->height;
}

//모든 노드는 회전을 수행한 이후에 높이를 다시 계산

void setHegiht(Node* node){
    node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference(Node* node){
    if (node == NULL) return 0;
    Node* leftChild = node->leftChild;
    Node* rightChild = node->rightChild;
    return getHeight(leftChild) - getHeight(rightChild); // 균형인수를 구한다
}

Node* rotateLL(Node* node){
    Node *leftChild = node->leftChild;
    node->leftChild = leftChild->rightChild;
    leftChild->rightChild = node;
    setHegiht(node);//회전 이후에 높이를 다시 계산
    return leftChild; //leftChild는 이후에 setHeight() 수행
}

Node* rotateRR(Node* node){
    Node *rightChild = node->rightChild;
    node->rightChild = rightChild->leftChild;
    rightChild->leftChild = node;
    setHegiht(node);//회전 이후에 높이를 다시 계산
    return rightChild; //leftChild는 이후에 setHeight() 수행
}

Node* rotateLR(Node* node){
    Node *leftChild = node->leftChild;
    node->leftChild = rotateRR(leftChild);
    setHegiht(node->leftChild);
    return rotateLL(node); 
}

Node* rotateRL(Node* node){
    Node *rightChild = node->rightChild;
    node->rightChild = rotateLL(rightChild);
    setHegiht(node->rightChild);
    return rotateRR(node); 
}

//균형 잡기
Node* balance(Node* node){
    int difference = getDifference(node);
    if (difference > = 2){
        if(getDifference(node->leftChild) >= 1){
            node = rotateLL(node);
        }
        else{
            node = rotateLR(node);
        }
    }
    else if (difference <= -2){
        if(getDifference(node->rightChild) <= -1){
            node = rotateRR(node);
        }
        else {
            node = rotateRL(node);
        }
    }
    setHegiht(node); //회전 이후에 높이를 다시 계산
    return node;
}

//삽입

Node *insertNode(Node* node, int data){
    if(!node){
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->geight = 1;
        node->leftChild = node->rightChild = NULL;
    }
    else if (data < node->data){
        node->leftChild = insertNode(node->leftChild, data);
        node = balance(node);
    }
    else if (data > node->data){
        node->rightChild = insertNode(node->rightChild, data);
        node = balance(node);
    }
    else {
        printf("데이터 중복이 발생했습니다. \n");
    }
    return node;
}

Node* root = NULL;

void display(Node* node, int level){
    if (node != NULL){
        display(node->rightChild, level + 1);
        printf("\n");
        if(node == root){
            printf("Root: ");
        }
        for (int i = 0; i < level && node != root; i++){
            printf("    ");
        }
        printf("%d(%d)", node->data, getHeight(node));
        display(node->leftChild, level + 1);
    }
}

int main(void){
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 34);
    root = insertNode(root, 12;
    root = insertNode(root, 3);
    root = insertNode(root, 95);
    root = insertNode(root, 31);
    root = insertNode(root, 29);
    display(root, 1); printf("\n");
    system("pause");
}