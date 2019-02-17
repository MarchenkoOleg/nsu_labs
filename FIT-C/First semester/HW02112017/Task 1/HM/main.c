#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

void FunctionG(int arg1, char *arg2);

void FunctionC(char *arg);

int main(int argc, char * argv[]) {
    if(argc == 1) {
        printf("Command line has no additional arguments\n");
        exit(1);
    }
    if(!strcmp(argv[1],"-g")) {
        if(argv[2] != NULL && argv[3] != NULL) {
            FunctionG(atoi(argv[2]), argv[3]);
        }
        else {
            printf("Wrong arguments for -g\n");
            exit(1);
        }
    } else if(!strcmp(argv[1],"-c")) {
        if(argv[2] != NULL) {
            FunctionC(argv[2]);
        }
        else {
            printf("Wrong arguments for -c\n");
            exit(1);
        }
    } else {
        printf("Wrong arguments: %s, %d\n", argv[1], strlen(argv[1]));
        for(int i = 0 ; i < argc; i++) {
            printf("Argument %d: %s\n", i, argv[i]);
        }
        exit(1);
    }
    system("pause");
    return 0;
}

void FunctionC(char *arg) {
    FILE *file;
    if ((file = fopen(arg,"r")) == NULL) {
        printf("File can't be opened or read\n");
        exit(1);
    }
    int prevValue, Value, Counter;
    fscanf(file, "%d", &prevValue);
    Counter = 1;
    while(!feof(file)) {
        fscanf(file, "%d", &Value);
        if(Value < prevValue) {
            printf("Not sorted. Failed position = %d, a[i]= %d, a[i+1]=%d\n", Counter, prevValue, Value);
            exit(0);
        }
        prevValue = Value;
        Counter++;
    }
    printf("Sorted\n");
    fclose(file);
}

void FunctionG(int arg1, char *arg2) {
    FILE *file;
    if ((file = fopen(arg2,"w")) == NULL) {
        printf("File can't be opened or created\n");
        exit(1);
    }
    fprintf(file, "%d\n", arg1);
    for(int j = 0; j < arg1; j++) {
        fprintf(file, "%d\n", rand()%10);
    }
    fclose(file);
}