//
// Created by march on 10.06.2018.
//

#include "Graph.h"

#include <stdlib.h>
#include "Edge.h"

#include "priority_queue.h"

Graph *graph_create(int vertexCount) {
    Graph *graph = malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;

    graph->edges = malloc(sizeof(Edge *) * vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        graph->edges[i] = malloc(sizeof(Edge) * vertexCount);

        for (int j = 0; j < vertexCount; j++) {
            graph->edges[i][j] = edge_infinite();
        }
    }

    return graph;
}

void graph_set_edge_length(Graph *graph, int from, int to, int length) {
    graph->edges[from][to] = edge_defined_length(length);
    graph->edges[to][from] = edge_defined_length(length);
}

Edge graph_get_edge_length(Graph *graph, int from, int to) {
    return graph->edges[to][from];
}

void graph_dijkstra_run(Graph *graph, int from, int *pathBack, Edge *lengths) {

    char *visited = malloc(sizeof(char) * graph->vertexCount);
    for (int i = 0; i < graph->vertexCount; i++) {
        lengths[i] = edge_infinite();
        visited[i] = 0;
    }
    lengths[from] = edge_defined_length(0);

    PriorityQueue *queue = priority_queue_create();
    priority_queue_insert(queue, from, lengths);

    while (!priority_queue_is_empty(queue)) {
        int index;
        priority_queue_extract_minimum(queue, &index);
        Edge tag = lengths[index];

        if (edge_compare(tag, lengths[index]) < 0) continue;

        for (int i = 0; i < graph->vertexCount; i++) {
            Edge edge = graph_get_edge_length(graph, index, i);
            if (edge_is_infinite(edge) || edge_is_overflowed(edge)) continue;

            Edge new_tag = edge_summ(lengths[index], edge);
            Edge old_tag;
            if (edge_compare(new_tag, lengths[i]) >= 0) {
                old_tag = lengths[i];
                lengths[i] = new_tag;
                pathBack[i] = index;
                priority_queue_remove(queue, i);
                priority_queue_insert(queue, i, lengths);
                if (edge_is_overflowed(new_tag) && edge_is_overflowed(old_tag))
                    pathBack[i] = -2;
            }
        }
    }
}

void graph_free(Graph *graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}