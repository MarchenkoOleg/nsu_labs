//
// Created by march on 05.06.2018.
//

#include "bitio.h"

void initIO(bitIO * bitstream, FILE * output){

    bitstream->bitBuffer = 0;
    bitstream->currentBit = 0;
    bitstream->nextByte = NULL;
    bitstream->output = output;
    noEnd = 1;
    k = 1;
}

void putBit(bitIO *outputstream, uint8_t  bit){
    #ifdef DEBUG
        printf("%d", bit);
    #endif
    if (outputstream->currentBit == 8) {
        fwrite(&outputstream->bitBuffer, sizeof(outputstream->bitBuffer), 1, outputstream->output);

        outputstream->currentBit = 0;
        outputstream->bitBuffer = 0;
    }
    outputstream->bitBuffer |= ((uint8_t)bit << (7 - outputstream->currentBit));
    outputstream->currentBit++;

}
void putChar(bitIO *outputstream, char ch){
    uint8_t bit = 1;
    #ifdef DEBUG
        printf("%c", ch);
    #endif
    for (size_t i = 0; i < 8; i++){
        bit = (uint8_t)ch & (bit << (7 - i));
        bit = bit >> (7 - i);
        putBit(outputstream, bit);
        bit = 1;
    }
}
void putBinlikeStr(bitIO *outputstream,  char *s){
    size_t i = 0;
    #ifdef DEBUG
       // printf("|");
    #endif
    while (s[i] != '\0' ){
        putBit(outputstream, ((s[i] == '1') ? 1 : 0));
        i++;
    }
}
void Dump(bitIO * outputstream){
    if (outputstream->bitBuffer)
    {

        fwrite(&outputstream->bitBuffer, sizeof(outputstream->bitBuffer), 1, outputstream->output);

    }
}

int getBit(bitIO* inputstream){
    uint8_t buff=1;
    if ((inputstream->currentBit > 7) || (inputstream->currentBit == 0)){
        inputstream->bitBuffer = 0;
        if(k) {
            k = 0;
            fread(&inputstream->bitBuffer, 1, 1, inputstream->output);
            fread(&inputstream->nextByte, 1, 1, inputstream->output);
        } else {
            inputstream->bitBuffer = inputstream->nextByte;
            noEnd = fread(&inputstream->nextByte, 1, 1, inputstream->output);
        }
        //if(inputstream->nextByte == EOF) noEnd = 0;

        inputstream->currentBit = 0;
    }
    buff = (buff << (7 - inputstream->currentBit));
    buff = (inputstream->bitBuffer) & buff;
    buff = buff >> (7-(inputstream->currentBit));
    inputstream->currentBit++;
    if (buff % 2 == 1){
        return 1;
    }
    else{
        return 0;
    }
}
char getChar(bitIO* inputstream){
    int bit;
    char ch;
    for (size_t i = 0; i < 8; i++){
        bit = getBit(inputstream);
        ch = ch << 1;
        ch = ch | bit;
    }
    return ch;
}
