//
// Created by march on 13.06.2018.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

typedef struct _node {
    struct _node *left, *right;
    void * elem;
} Node;

void printTree(Node *tree, int level);

#endif //HUFFMAN_TREE_H
