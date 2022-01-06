#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;
Node *head, *tail

// 리스트 추가
void insert(int data){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail){
		cur = cur -> next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

// 리스트 삭제 
void removeFront(){
	Node* node = head->next;
	head->next = node->next;
	Node* node = node->next;
	next->prev = head;
	free(node);
}

//리스트 전체 출력

void show() {
    Node* cur = head->next;
    while (cur != tail){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

// 양방향 연결 리스트 사용
int main(void){
    head = (Node*) malloc(sizeof(Node));
    tail = (Node*) malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);
    removeFront();
    show();
    system("pause");
    return 0;
}