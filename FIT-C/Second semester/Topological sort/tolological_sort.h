//
// Created by march on 04.04.2018.
//

#ifndef GRAPH_DFS_TOLOLOGICAL_SORT_H
#define GRAPH_DFS_TOLOLOGICAL_SORT_H

#include <stdio.h>
#include "stack.h"

int N;
int *colors = NULL;
Stack *out = NULL;
Stack **edges = NULL;

int topological_sort();
int dfs(int v);

#endif //GRAPH_DFS_TOLOLOGICAL_SORT_H
