#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
int toDec(char S) {
    char alf[16] = "0123456789ABCDEF";
    for(int c = 0; c < 16; c++) {
        if(alf[c] == S) {
            return c;
        }
    }
}

char toHex(int c) {
    char alf[16] = "0123456789ABCDEF";
    return  alf[c];
}

int main(int argc, char * argv[]) {

    if(argc != 4) {
        printf("Command line has wrong arguments\n");
        exit(1);
    }

    FILE * in;
    FILE * out;

    if ((in = fopen(argv[2],"r")) == NULL) {
        printf("File %s can't be opened\n", argv[1]);
        exit(1);
    }
    if ((out = fopen(argv[3],"w")) == NULL) {
        printf("File %s can't be opened\n", argv[2]);
        exit(1);
    }

    int L = strlen(argv[1]);
    int read_L;
    char * str = (char *) malloc(sizeof(int) * (L + 1));

    while(!feof(in)) {

        read_L = fread(str, 1, L, in);
        str[read_L] = '\0';
        for(int d = 0; d < read_L; d++) {

            fprintf(out, "%c", (char) toHex(toDec(str[d]) ^ toDec(argv[1][d])));
        }


    }

    fclose(in);
    fclose(out);

    return 0;

}