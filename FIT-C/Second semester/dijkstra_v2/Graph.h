//
// Created by march on 10.06.2018.
//

#ifndef DIJKSTRA_V2_GRAPH_H
#define DIJKSTRA_V2_GRAPH_H

#include "Edge.h"

    typedef struct graph {
        int vertexCount;
        Edge ** edges;
    } Graph;

    Graph * graph_create(int vertexCount);

    void graph_set_edge_length(Graph * graph, int from, int to, int length);

    Edge graph_get_edge_length(Graph * graph, int from, int to);

    void graph_dijkstra_run(Graph * graph, int from, int * pathBack, Edge * lengths);

    void graph_free(Graph * graph);

#endif //DIJKSTRA_V2_GRAPH_H
