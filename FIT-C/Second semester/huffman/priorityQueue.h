//
// Created by march on 13.06.2018.
//

#ifndef HUFFMAN_PRIORITYQUEUE_H
#define HUFFMAN_PRIORITYQUEUE_H

typedef struct _queueElement {
    void * elem;
    int priority;
    struct _queueElement * next;
} queueElement;

typedef struct _priorityQueue {
    queueElement * first;
    int size;
} priorityQueue;

priorityQueue * priorityQueueCreate();
void * queueGet(priorityQueue *queue);
void queueAddNew(priorityQueue *queue, void *item, int priority);


#endif //HUFFMAN_PRIORITYQUEUE_H
