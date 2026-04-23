#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data;
}

bool isEmpty(const Queue* q) {
    return (q->front == q->rear);
}

bool isFull(const Queue* q) {
    return ((q->rear + 1 == q->data + MAX && q->front == q->data) ||
            (q->rear + 1 == q->front));
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "Queue penuh";
    }

    *(q->rear) = value;

    if (q->rear == q->data + MAX - 1)
        q->rear = q->data;
    else
        q->rear++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }

    if (q->front == q->data + MAX - 1)
        q->front = q->data;
    else
        q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw "Queue kosong";
    }

    if (q->rear == q->data)
        return *(q->data + MAX - 1);
    else
        return *(q->rear - 1);
}