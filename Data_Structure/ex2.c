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
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head);
    freeAll(head);
    systme("pause")
    return 0;
}
// 9,7,1,2