//
// Created by march on 13.06.2018.
//
#include "bitio.h"
#include "tree.h"
#include "types.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <string.h>

#include "algorithmFunctions.h"

void putCodingTree(bitIO * output, Node * root){
    if (root == NULL){
        return;
    }
    if (((Element*)(root->elem))->sym){
        putBit(output, 1);
        putChar(output, (uint8_t)(((Element*)(root->elem))->sym));
        return;
    }
    putBit(output, 0);
    putCodingTree(output, root->left);
    putCodingTree(output, root->right);
}


void buildCode(Node *n, char *s, int len) {
    static char *out = buf;
    if (((Element*)(n->elem))->sym) {
        s[len] = 0;
        strcpy(out, s);
        code[((Element*)(n->elem))->sym] = out;
        out += len + 1;
        return;
    }

    s[len] = '0'; buildCode(n->left,  s, len + 1);
    s[len] = '1'; buildCode(n->right, s, len + 1);
}

void init(FILE *in, bitIO * output) {
    priorityQueue * queue = priorityQueueCreate();
    int freq[255] = {0};
    uint32_t all = 0;
    int cr;
    cr = getc(in);
    while(cr != EOF) {
        all++;
       // printf("%c", cr);
        freq[(int)cr]++;
        cr = getc(in);
    }
    //printf("\n");
    //int k = fprintf(out,"%d", all);
    char * str[35] = {0};
    for(int i = 31; i >= 0; i--) {
        str[i] = (all & 1);
       // printf("%d", (all & 1));
        all = all >> 1;
    }
    str[32] = "\0";
    //printf("\n");
    //printf("%d", output->currentBit);
    //printf("\n");
    for(int i = 0; i < 32; i++)
        putBit(output, str[i]);
    for (int i = 0; i < 255; i++)
        if (freq[i]) {
            //printf("%c %d\n", i, freq[i]);
            Element *newElement = malloc(sizeof(Element));
            Node *newNode = malloc(sizeof(Node));
            newElement->sym = i;
            newElement->fr = freq[i];
            newNode->elem = newElement;
            newNode->left = NULL;
            newNode->right = NULL;
            queueAddNew(queue, newNode, freq[i]);
        }
    // queue->first
    //printf("ok all: %d %d\n", all, k);
    Node *bufNode1 = malloc(sizeof(Element));
    Node *bufNode2 = malloc(sizeof(Element));
    Element *newElement = malloc(sizeof(Element));
    while(1) {
        bufNode1 = (Node*)queueGet(queue);
        bufNode2 = (Node*)queueGet(queue);
        if(bufNode2 == NULL) {
            break;
        }
        /*printf("%c %d %c %d\n",((Element*)(bufNode1->elem))->sym, ((Element*)(bufNode1->elem))->fr,
               ((Element*)(bufNode2->elem))->sym, ((Element*)(bufNode2->elem))->fr );*/

        int freqSum = ((Element*)(bufNode1->elem))->fr + ((Element*)(bufNode2->elem))->fr;
        newElement->fr = freqSum;
        newElement->sym = NULL;
        Node * newNode = malloc(sizeof(Node));
        newNode->elem = newElement;
        newNode->left = bufNode1;
        newNode->right = bufNode2;
        queueAddNew(queue, newNode, freqSum);
    }
    //printf("ok %d\n", ((Element*)(bufNode1->elem))->fr);
    tree = bufNode1;


}

void encode(FILE *in, FILE *out, bitIO * output, Node *t) {
    putCodingTree(output, t);
    int cr = getc(in);
    while(cr != EOF) {
        putBinlikeStr(output, code[cr]);
        cr = getc(in);
    }
    int bits = 8 - output->currentBit;
    for(int i = 0; i < bits; i++)
        putBit(output, 0);
    Dump(output);


}

Node *buildNode(char sym, bitIO *input, int dir) {
    Node *t = malloc(sizeof(Node));
    Element *element = malloc(sizeof(Element));
    element->sym = sym;
    t->elem = element;
    if(dir) {

        if(getBit(input) == 0) {
            t->left = buildNode(NULL, input, 1);
            t->right = buildNode(NULL, input, 1);
        } else {
            char sym = getChar(input);
            //printf("%c", sym);
            t = buildNode(sym, input, 0);
        }
    }
    return t;
}

char ReadTreeChar(bitIO * input,Node *tree) {
    Element *elem;
    int bit = getBit(input);
    if(bit) {
        elem = ((Node*)tree->right)->elem;
    } else {
        elem = ((Node*)tree->left)->elem;
    }
    if(elem->sym != NULL) {
        return elem->sym;
    } else {
        if(bit) {
            ReadTreeChar(input, tree->right);
        } else {
            ReadTreeChar(input, tree->left);
        }
    }
}

void decode(FILE *in, FILE *out, bitIO * input) {
    int all = 0;
    for(int i = 0; i < 32; i++) {
        all = all << 1;
        all = all | getBit(input);
    }
    printf("%d\n", all);
    tree = buildNode(NULL, input, 1);
   for(int i = 0; i < all; i++)
            printf("%c", ReadTreeChar(input, tree));

    }