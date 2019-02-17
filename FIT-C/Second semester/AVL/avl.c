//
// Created by OlegMS on 25.02.2018.
//

#include "avl.h"

unsigned int height(node* p) {
    return p?p->height:0;
}

int bfactor(node* p) {
    return height(p->right)-height(p->left);
}

void fixheight(node* p) {
    unsigned int hl = height(p->left);
    unsigned int hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* rotateleft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* balance(node* p) {
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( p == NULL ) {
        node * new_node = malloc(sizeof(node));
        new_node->key = k;
        new_node->left = 0;
        new_node->right = 0;
        new_node->height = 1;
        return new_node;
    }
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}
