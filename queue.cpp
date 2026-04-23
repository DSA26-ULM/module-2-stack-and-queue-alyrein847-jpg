#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return (q->rear - q->front + 1) == MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue penuh");
    }

    if (q->rear == q->data + MAX - 1) {
        int size = q->rear - q->front + 1;
        for (int i = 0; i < size; i++) {
            q->data[i] = *(q->front + i);
        }
        q->front = q->data;
        q->rear = q->data + size - 1;
    }

    q->rear++;
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue kosong");
    }

    q->front++;

    if (isEmpty(q)) {
        q->front = q->data;
        q->rear  = q->data - 1;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue kosong");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue kosong");
    }
    return *(q->rear);
}