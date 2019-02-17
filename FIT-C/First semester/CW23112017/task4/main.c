#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

struct stack {
    char elem[NMAX];
    int top;
};


void init(struct stack *stk) {
    stk->top = 0;
}

void push(struct stack *stk, char f) {
    if(stk->top < NMAX) {
        stk->elem[stk->top] = f;
        stk->top++;
    } else
        exit(1);
}

char pop(struct stack *stk) {
    char elem;
    if((stk->top) > 0) {
        stk->top--;
        elem = stk->elem[stk->top];
        return(elem);
    } else
        return(0);
}

int isempty(struct stack *stk) {
    if((stk->top) == 0)    return(1);
    else return(0);
}

int main() {
    FILE * in = fopen("in.txt", "rt");
    if(in == NULL) exit(1);
    struct stack *stk;
    stk = (struct stack*) malloc(sizeof(struct stack));
    init(stk);
    char elem, k;

    while(!(feof(in) && isempty(stk))) {
        elem = fgetc(in);
        if(elem == '(' || elem == '{' || elem == '[')
            push(stk, elem);
        else {
            if(isempty(stk)) {
                printf("NO");
                exit(0);
            } else
                k = pop(stk);
            if(!((k == '(' && elem == ')') || (k == '{' && elem == '}') || (k == '[' && elem == ']'))) {
                printf("NO");
                exit(0);
            }
        }
    }
    printf("YES");
    return 0;
}