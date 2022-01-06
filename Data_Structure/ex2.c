#include <stido.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

// 연결리스트 삽입
void addFront(Node *root, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root){
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

//연결 리스트 메모리 해제 함수

void freeAll(Node *root){
    Node *cur = head->next;
    while (cur != NULL){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

//연결 리스트 전체 출력 함수
void showAll(Node *root){
    Node *cur = head->next;
    while (cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void){
    head = (Node*) malloc(sizeof(Node));
    Node *node1 = (Node*) malloc(sizeof(Node));
    node1->data = 1;
    Node *node2 = (Node*) malloc(sizeof(Node));
    node2->data = 2;
    head->next = node1;
    node1->next = node2;
    node2->next = NULL;
    Node *Cur = head->next;
    while (cur != NULL){
        printf("%d ", cur->data);
            cur = cur->next;
    }
    systme("pause")
    return 0;
}
// 1, 2