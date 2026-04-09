#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue() {
    QueueType* cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = 0;
    cQ->rear = 0;
    return cQ;
}

int isCQueueEmpty(QueueType* cQ) {
    if (cQ->front == cQ->rear) {
        printf(" Circular Queue is empty! ");
        return 1;
    }
    else return 0;
}

int isCQueueFull(QueueType* cQ) {
    if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
        printf(" Circular Queue is full! ");
        return 1;
    }
    else return 0;
}

void enCQueue(QueueType* cQ, element item) {
    if (isCQueueFull(cQ)) return;
    else {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

element deCQueue(QueueType* cQ) {
    if (isCQueueEmpty(cQ)) return;
    else {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

element peekCQ(QueueType* cQ) {
    if (isCQueueEmpty(cQ)) exit(1);
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void printCQ(QueueType* cQ) {
    int i;
    printf(" Circular Queue : [");

    if (cQ->front < cQ->rear) {
        for (i = cQ->front + 1; i <= cQ->rear; i++)
            printf("%3c", cQ->queue[i]);
    }
    else {
        for (i = cQ->front + 1; i < cQ_SIZE; i++)
            printf("%3c", cQ->queue[i]);
        for (i = 0; i <= cQ->rear; i++)
            printf("%3c", cQ->queue[i]);
    }

    printf(" ]");
}