//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "bitio.h"
#include "priorityQueue.h"
#include "types.h"
#include "tree.h"
#include "algorithmFunctions.h"

extern char *code[255];
extern char *buf[1024];
extern Node *tree;
extern int noEnd;

int main() {
    for(int i = 0; i < 255; i++)
        code[i] = 0;
    for(int i = 0; i < 1024; i++)
        buf[i] = "\0";
    setlocale(LC_CTYPE, "rus");
    FILE *in = fopen("in.txt", "rb");
    FILE *out = fopen("out.txt", "wb+");
    bitIO _bitIO;
    char flag[3];
    //flag = (char) fgetc(in);
    fgets(flag, 80, in);
    /*if (fgetc(in) == '\r') {
        if(fgetc(in) == '\r') {
            fgetc(in);
        }
    }*/
    if(flag[0] == 'c') {

        initIO(&_bitIO, out);
        init(in, &_bitIO);
        char c[24];
        //printf("sym = %c\n", ((Element*)tree->elem)->sym);
        buildCode(tree, c, 0);
        #ifdef DEBUG
        for(int i = 0; i < 255; i++) {
            if (code[i]) printf("%d '%c': %s\n", i, i, code[i]);
        }
        #endif
        fseek(in, 3, SEEK_SET);
        encode(in, out, &_bitIO, tree);

    } else if(flag[0] == 'd') {
        printf("decode");
       // FILE *in1 = fopen("in.txt", "rb");
       // FILE *out1 = fopen("out.txt", "wb+");
        initIO(&_bitIO, in);
        decode(in, in, &_bitIO);


    } else {
        printf("Wrong flag!");
    }
    //fseek(out, 0, SEEK_SET);



    fclose(in);
    fclose(out);
    free(in);
    free(out);

    return 0;
}