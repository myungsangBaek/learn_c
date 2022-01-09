#include <stdio.h>
#include <sidlib.h>
#define INF 9999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

//큐 삽입 함수

void push(Queue *queue, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (queue->count == 0){
        queue->front = node;
    }
    else{
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

//큐 추출 함수

int pop(Queue *queue) {
    if (queue->count == 0){
        printf("큐 언더플로우가 발생했습니다.")
        return -INF;
    }
    Node *node = queue->front;
    int data = node->data;
    queue->front = node->enext;
    free(node);
    queue->count--;
    return data;
}

//큐 전체 출력 함수

void show(Queue *queue){
    Node *cur = queue->front;
    while (cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("--- 큐의 뒤 ---\n");
}

//완성된 큐 사용하기

int main(void){
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    push(&queue, 7);
    push(&queue, 5);
    push(&queue, 4);
    pop(&queue);
    push(&queue, 6);
    pop(&queue);
    show(&queue);
    system("pause");
    return 0;
}