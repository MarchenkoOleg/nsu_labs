//
// Created by march on 13.06.2018.
//
#include <stdlib.h>
#include <stdio.h>
//#include "types.h"

#include "priorityQueue.h"

priorityQueue * priorityQueueCreate(){
    priorityQueue * queue = malloc(sizeof(priorityQueue));
    queue->first = NULL;
    queue->size = 0;
    return queue;
}

void * queueGet(priorityQueue *queue) {
    if (queue == NULL || queue->first == NULL) return NULL;
    else {
        queueElement * firstElement = queue->first;
        void * firstItem = (firstElement->elem);
        //printf("sym =%c\n", firstItem->sym);
        queue->first = firstElement->next;
        queue->size--;
        free(firstElement);
        return firstItem;
    }
}



void queueAddNew(priorityQueue *queue, void *item, int priority) {
    queueElement * newQueue = malloc(sizeof(queueElement));
    newQueue->elem = item;
    newQueue->priority = priority;
    if (queue->first == NULL) {
        newQueue->next = NULL;
        queue->first = newQueue;

    } else if (queue->first->priority > priority) {
        newQueue->next = queue->first;
        queue->first = newQueue;
    } else {
        queueElement *currentElement = queue->first;
        while (currentElement->next != NULL && currentElement->next->priority < priority) {
            currentElement = currentElement->next;
        }

        newQueue->next = currentElement->next;
        currentElement->next = newQueue;
    }
    queue->size++;
}
