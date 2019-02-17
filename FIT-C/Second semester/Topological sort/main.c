#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"
#include "tolological_sort.h"

int main() {
    FILE *in;
    in  = fopen("in.txt", "r");
    if (in == NULL) return -1;
    int M = -1, ed, val;
    fscanf(in, "%d", &N);
    if(N < 0 || N > 1000) {
        printf("bad number of vertices");
        return 0;
    }
    int d = fscanf(in, "%d", &M);

    if(d == -1) {
        printf("bad number of lines");
        return 0;
    }

    if(M < 0 || M > N*(N-1)/2) {
        printf("bad number of edges");
        return 0;
    }

    edges = malloc(sizeof(Stack)*N);
    colors = malloc(sizeof(Stack)*N);

    for (int i = 0; i < N; i++) {
        edges[i] = NULL;
        colors[i] = 0;
    }
    for (int i = 0; i < M; i++) {

        ed = NULL;
        val = NULL;
        fscanf(in, "%d %d", &ed, &val);
        if(ed == NULL || val == NULL) {
            printf("bad number of lines");
            exit(0);
        }
        if(ed < 0 || ed > N) {
            printf("bad vertex");
            exit(0);
        }
        if(val < 0 || val > N) {
            printf("bad vertex");
            exit(0);
        }

        push(&edges[ed-1], val - 1);
    }

    if(topological_sort()) {
        while (out) {

            printf("%d ", pop(&out)+1);
        }
    } else {
        printf("impossible to sort");
    }
    fclose(in);
    return 0;
}

