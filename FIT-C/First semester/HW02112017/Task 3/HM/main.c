#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if(argc != 2) {
        printf("Bad arguments\n");
        exit(1);
    }
    int N = atoi(argv[1]);
    int Counter = 0;
    int M = 0;
    char * valueIn = (char *) malloc(32);
    char * valueOut = (char *) malloc(32);
    for(int i = 0; i < 32; i++) {
        valueOut[i] = '0';
        if(N >> i & 1) {
            valueIn[i] = '1';
            Counter++;
        } else {
            valueIn[i] = '0';
        }
    }
    valueIn[32] = 0;
    valueOut[32] = 0;
    if(Counter != 0) {
        int Z = 0;
        while(1) {
            M = M | 1;
            valueOut[Z] = '1';
            Z++;
            if(Counter == Z) break;
            M = M << 1;
        }
    }
    printf("%d\n", M);
    for(int i = 31; i >= 0; i--)
        printf("%c", valueIn[i]);
    printf("\n");
    for(int i = 31; i >= 0; i--)
        printf("%c", valueOut[i]);
    printf("\n");
    system("pause");
    return 0;
}
