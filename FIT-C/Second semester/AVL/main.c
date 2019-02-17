#include <stdio.h>
#include "avl.h"

int main() {
    FILE *in;
    in  = fopen("in.txt", "r");
    if (in == NULL) exit(1);
    int len, buf;
    fscanf(in, "%d", &len);
    node * Node;
    Node = NULL;
    for(int count = 0; count < len; count++) {
        fscanf(in, "%d", &buf);
        Node = insert(Node, buf);
    }
    printf("%d", height(Node));
    return 0;
}