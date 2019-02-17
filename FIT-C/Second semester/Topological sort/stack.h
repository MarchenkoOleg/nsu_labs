//
// Created by march on 04.04.2018.
//

#ifndef GRAPH_DFS_STACK_H
#define GRAPH_DFS_STACK_H

typedef struct _stack {
    int value;
    struct _stack *next;
} Stack;

int push(Stack **, int);
int pop(Stack **);

#endif //GRAPH_DFS_STACK_H
