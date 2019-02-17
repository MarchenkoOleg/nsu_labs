//
// Created by march on 04.04.2018.
//

#include <stdio.h>
#include <malloc.h>
#include "stack.h"

int push(Stack **head, int value) {
    Stack *tmp = malloc(sizeof(Stack));
    if (tmp == NULL) {
       return NULL;

    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

int pop(Stack **head) {
    Stack *out;
    int value;
    if (*head == NULL) {
        //exit(-2);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}