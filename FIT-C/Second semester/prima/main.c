#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
// A structure to represent a node in adjacency list
struct AdjListNode {
    unsigned int dest;
    unsigned int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList {
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph {
    unsigned int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(unsigned int dest, unsigned int weight) {
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(unsigned int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (unsigned int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, unsigned int src, unsigned int dest, unsigned int weight) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode {
    unsigned int  v;
    unsigned int key;
};

// Structure to represent a min heap
struct MinHeap {
    unsigned int size;      // Number of heap nodes present currently
    unsigned int capacity;  // Capacity of min heap
    unsigned int *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, double key) {
    struct MinHeapNode* minHeapNode =
            (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// A utilit function to create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap =
            (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (unsigned int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
            (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, unsigned int idx) {
    unsigned int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
            minHeap->array[left]->key < minHeap->array[smallest]->key )
        smallest = left;

    if (right < minHeap->size &&
            minHeap->array[right]->key < minHeap->array[smallest]->key )
        smallest = right;

    if (smallest != idx) {
        // The nodes to be swapped in min heap
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];

        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decreasy key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, unsigned int v, double key) {
    // Get the index of v in  heap array
    unsigned int i = minHeap->pos[v];

    // Get the node and update its key value
    minHeap->array[i]->key = key;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, unsigned int v) {
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

// A utility function used to print the constructed MST
void printArr(unsigned int arr[], unsigned int n) {
    int point1, point2;
    for (unsigned int i = 1; i < n; ++i) {
        point1 = arr[i] + 1;
        point2 = i + 1;
        if(point1 != 0) {

            if (point1 < point2)
                printf("%d %d\n", point1, point2);
            else
                printf("%d %d\n", point2, point1);
        }
    }
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
int PrimMST(struct Graph* graph, unsigned int *parent) {
    unsigned int V = graph->V;// Get the number of vertices in graph
    unsigned int NV = V;
    double key[V];      // Key values used to pick minimum weight edge in cut

    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (unsigned int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = LONG_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap)) {
        // Extract the vertex with minimum key value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        unsigned int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            unsigned int v = pCrawl->dest;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            unsigned int w = pCrawl->weight;
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v] ) {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
                NV--;
            }
            pCrawl = pCrawl->next;
        }
    }
    //printf("%d %d\n", NV, minHeap->size);
    return (NV <= 0);
}

// Driver program to test above functions
int main() {
    unsigned int NV, NE;
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


    if(NV == 1 && NE == 0)
        return 0;

    if(NE < 0 || NE > NV*(NV-1)/2) {
        printf("bad number of edges");
        return 0;
    }

    struct Graph* graph = createGraph(NV);

    unsigned int point1, point2;
    double weight;

    if(NE == 0) {
        printf("no spanning tree");
        exit(0);
    }
    for(int i = 0; i < NE ; i++) {
        if(fscanf(in,"%d %d %lf", &point1, &point2, &weight) != 3) {
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
        addEdge(graph, point1 - 1, point2 - 1, weight);
    }

    int parent[NV];   // Array to store constructed MST



    if(PrimMST(graph, parent))
        printArr(parent, NV);
    else
        printf("no spanning tree");
    return 0;
}
