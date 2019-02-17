//
// Created by march on 16.04.2018.
//

#ifndef KRUSKAL_V2_MST_H
#define KRUSKAL_V2_MST_H

typedef struct  Edge_t{
    int from;       // edge start vertex
    int to;         // edge end vertex
    double w;
    //int k;// edge weight
} edge_t;

typedef struct Set_t {
    struct Set_t p; // link on parent
} set_t;


int NS;      // number of sets
set_t *sets; // array of sets
int NE;      // number of edges
edge_t *E;   // array of edges
int NV;      // number of edges



// compare function for sorting edges by weight
int cmpw(edge_t, edge_t);

set_t* get_set_id(set_t* s);

void take_edge(int);

set_t* join_sets(set_t *, set_t);

void mst_f();

#endif //KRUSKAL_V2_MST_H
