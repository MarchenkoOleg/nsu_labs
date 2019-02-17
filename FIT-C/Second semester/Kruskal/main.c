#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "mst.h"

extern int NS;      // number of sets
extern set_t *sets; // array of sets
extern int NE;      // number of edges
extern edge_t *E;   // array of edges
extern int NV;

int main() {

    FILE *in;
    in  = fopen("in.txt", "r");
    if (in == NULL) return -1;

    fscanf(in,"%d", &NV);

    if(NV < 0 || NV > 5000) {
        printf("bad number of vertices");
        return 0;
    }

    if(!fscanf(in, "%d", &NE)) {
        printf("bad number of lines");
        return 0;
    }

    if(NE < 0 || NE > NV*(NV-1)/2) {
        printf("bad number of edges");
        return 0;
    }

    E = (edge_t*) malloc(NE * sizeof(edge_t));
    sets = (set_t*) malloc(NV * sizeof(set_t));
    int point1, point2, weight;
    for(int i = 0; i < NE ; i++) {
        if(fscanf(in,"%d %d %d", &point1, &point2, &weight) != 3) {
            printf("bad number of lines");
            exit(0);
        }
        if(weight <= 0 || weight > INT_MAX) {
            printf("bad length");
            exit(0);
        }
        if(point1 > NV || point2 > NV || point1 < 1 || point2 < 1) {
            printf("bad vertex");
            exit(0);
        }
        E[i].from = point1 - 1;
        E[i].to = point2 - 1;
        E[i].w = weight;
        //E[i].k = 0;
    }

    mst_f();

    if(NS != 1) {
        printf("no spanning tree");
        return 0;
    }
    for(int d = 0; d < NE; d++) {
        if(E[d].w == 0) {
            take_edge(d);
        }
    }
}