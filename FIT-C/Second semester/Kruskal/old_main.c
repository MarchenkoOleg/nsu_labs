#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
    int from;       // edge start vertex
    int to;         // edge end vertex
    double w;
    //int k;// edge weight
} edge_t;

typedef struct set_t {
    struct set_t *p; // link on parent
} set_t;


int NS;      // number of sets
set_t *sets; // array of sets
int NE;      // number of edges
edge_t *E;   // array of edges
int NV;      // number of edges

// compare function for sorting edges by weight
int cmpw(edge_t *a, edge_t *b) {
    if(a->w > b->w ) return 1;
    if(a->w < b->w ) return -1;
    return 0;
}

set_t* get_set_id(set_t* s) {
    if(s == s->p )
        return s;
    else {
        set_t *p = get_set_id(s->p);
        s->p = p;
        return p;
    }
}

set_t* join_sets(set_t *a, set_t *b) {
    a->p = b;
    return a;
}

void take_edge(int edge_id) {
    int point1 = E[edge_id].from + 1;
    int point2 = E[edge_id].to + 1;
    if(point1 < point2)
        printf("%d %d\n", point1, point2);
    else
        printf("%d %d\n", point2, point1);
}

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

    qsort(E, NE, sizeof(edge_t), (int (*)(const void*, const void*)) cmpw);

    NS = NV;
    for(int i = 0; i < NS ; i++)
        sets[i].p = &sets[i];

    for(int i=0; NS > 1 && i < NE; i++) {
        if ( get_set_id ( &sets[E[i].from]) == get_set_id ( &sets[E[i].to]) )
            continue;
        join_sets ( get_set_id (&sets[E[i].from] ),  get_set_id ( &sets[E[i].to]) );
        NS--;
        E[i].w = 0;
    }

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