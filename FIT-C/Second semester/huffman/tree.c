//
// Created by march on 13.06.2018.
//

#include "tree.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void printTree(Node *tree, int level) {
    /*if(tree == NULL) {
        return;
    }
    if(tree->left == NULL && tree->right == NULL) {
        printf(" %c ", ((Element*)(tree->elem))->sym);
    }
    printf(" %d\n", ((Element*)(tree->elem))->fr);
    printTree(tree->left);
    printTree(tree->right);
     */
    if(tree) {
        printTree(tree->left, level + 1);
        for(int i = 0; i < level; i++)
            printf("   ");
        printf("%c%d\n", ((Element*)(tree->elem))->sym, ((Element*)(tree->elem))->fr);
        printTree(tree->right, level + 1);
    }
}