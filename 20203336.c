#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // 큐의 최대 크기

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

// 큐 초기화
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// 큐가 비어 있는지 확인
int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

// 큐가 가득 찼는지 확인
int isFull(CircularQueue* q) {
    return (q->rear + 1) % SIZE == q->front;
}

// 큐에 삽입
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// 큐에서 삭제
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) { // 큐에 하나의 요소만 남아있는 경우
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Dequeued %d\n", value);
    return value;
}

// 큐의 상태를 출력
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q);

    return 0;
}
