//
// Created by march on 05.06.2018.
//

#ifndef HUFFMAN_BITIO_H
#define HUFFMAN_BITIO_H

//#define DEBUG

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bitIO {
    uint8_t bitBuffer;
    size_t currentBit;
    size_t nextByte;
    FILE * output;

} bitIO;

int noEnd;
int k;

void initIO(bitIO * bitstream, FILE * output);

void putBit(bitIO *outputstream, uint8_t bit);

void putChar(bitIO *outputstream, char ch);

void putBinlikeStr(bitIO *outputstream, char *s);

void Dump(bitIO * outputstream);

int getBit(bitIO* inputstream);

char getChar(bitIO* inputstream);

#endif //HUFFMAN_BITIO_H
