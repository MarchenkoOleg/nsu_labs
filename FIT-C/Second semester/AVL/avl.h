//
// Created by OlegMS on 25.02.2018.
//

#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H

#include <malloc.h>

typedef struct _Node {
    int key;
    unsigned int height;
    struct _Node* left;
    struct _Node* right;
} node;

unsigned int height(node* p);

int bfactor(node* p);

void fixheight(node* p);

node* rotateright(node* p);

node* rotateleft(node* q);

node* balance(node* p);

node* insert(node* p, int k);

#endif //AVL_TREE_AVL_H
