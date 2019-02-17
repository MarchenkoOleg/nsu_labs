//
// Created by march on 13.06.2018.
//

#ifndef HUFFMAN_ALGORITMFUNCTIONS_H
#define HUFFMAN_ALGORITMFUNCTIONS_H

#include "tree.h"

char *code[255];
char *buf[1024];
Node *tree;

void putCodingTree(bitIO * output, Node * root);
void buildCode(Node *n, char *s, int len);
void init(FILE *in, bitIO * output);
void encode(FILE *in, FILE *out, bitIO * output, Node *t);
void decode(FILE *in, FILE *out, bitIO * input);
Node *buildNode(char sym, bitIO *input, int dir);

#endif //HUFFMAN_ALGORITMFUNCTIONS_H
