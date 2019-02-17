//
// Created by march on 04.04.2018.
//

#include "tolological_sort.h"

int topological_sort() {
    int Cycle;
    for (int i = 0; i < N; i++) {
        Cycle = dfs(i);
        if (Cycle)return 0;
    }

    return 1;
}

int dfs(int v) {
    if (colors[v] == 1)return 1;
    if (colors[v] == 2)return 0;
    colors[v] = 1;
    while (edges[v] != NULL) {
        if (dfs(pop(&edges[v])))return 1;
    }

    push(&out, v);
    colors[v] = 2;
    return 0;
}