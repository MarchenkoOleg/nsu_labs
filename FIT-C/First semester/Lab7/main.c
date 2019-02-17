#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int op_preced(const char c)
{
    switch(c) {
        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;
    }
    return 0;
}


#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*')
#define is_ident(c) (c >= '0' && c <= '9')

bool shunting_yard(const char *input, char *output) {
    const char *strpos = input, *strend = input + strlen(input);
    char c,b, stack[1000], sc, *outpos = output;
    bool OpWas = false;
    unsigned int sl = 0;
    c = *strpos;
    while(strpos < strend) {
        b = c;
        c = *strpos;
        // Если токен оператор , то:
        if(is_operator(c)) {
            if(OpWas) {
                printf("syntax error\n");
                exit(0);
            }
            OpWas = true;
            while(sl > 0) {
                sc = stack[sl - 1];
                // Пока на вершине стека присутствует токен оператор
                if(is_operator(sc) && (op_preced(c) <= op_preced(sc)))
                {
                    // Переложить оператор из стека в очередь вывода.
                    *outpos = sc;
                    ++outpos;
                    sl--;
                }
                else
                {
                    break;
                }
            }
            // положить в стек оператор
            stack[sl] = c;
            ++sl;
        }
            // Если токен - левая круглая скобка, то положить его в стек.
        else if(c == '(')
        {
            stack[sl] = c;
            ++sl;
        }
            // Если токен - правая круглая скобка:
        else if(c == ')')
        {
            bool pe = false;
            // До появления на вершине стека токена "левая круглая скобка"
            // перекладывать операторы из стека в очередь вывода.
            if(sl == 1) {
                printf("syntax error\n");
                exit(0);
            }
            while(sl > 0)
            {
                sc = stack[sl - 1];
                if(sc == '(')
                {
                    pe = true;
                    break;
                }
                else
                {
                    *outpos = sc; ++outpos;
                    sl--;
                }
            }
            // Если стек кончится до нахождения токена левая круглая скобка, то была пропущена скобка.
            if(!pe)
            {
                printf("syntax error\n");
                exit(0);
            }
            // выкидываем токен "левая круглая скобка" из стека (не добавляем в очередь вывода).
            sl--;
            if(sl > 0)
            {
                sc = stack[sl - 1];
            }
        }
        else if(is_ident(c))
        {
            OpWas = false;
            *outpos = c; ++outpos;
        }
        else
        {
            printf("syntax error\n");
            exit(0);
        }
        ++strpos;
    }
    while(sl > 0)
    {
        sc = stack[sl - 1];
        if(sc == '(' || sc == ')')
        {
            printf("syntax error\n");
            exit(0);
        }
        *outpos = sc; ++outpos;
        --sl;
    }
    *outpos = 0;
    return true;
}


int main()
{
    FILE *in;
    in  = fopen("in.txt", "r");
    fseek(in , 0 , SEEK_END);
    long lSize = ftell(in);
    rewind (in);
    char *input = (char*) malloc(sizeof(char)*lSize);
    fread(input, 1, lSize, in);
    char output[1000];
    char c;
    int stack[1000] = {0};
    int sc = 0;
    int a,b;
    if(lSize <=2) {
        printf("syntax error\n");
        exit(0);
    }
    input[lSize-2] = '\0';
    // printf("%d   input: %s     %d\n%c",lSize, input, strlen(input), input[strlen(input)-1]);
    if(is_operator(input[strlen(input)-1])) {
        printf("syntax error\n");
        exit(0);
    }
    if(shunting_yard(input, output))
    {
    //    printf("output: %s   %d\n", output, strlen(output));
    }

    for(int d = 0; d < strlen(output); d++) {
        c = output[d];
        if(is_ident(c)) {
            stack[sc] = c - '0';
            sc++;
        } else {
            if(sc < 1) {
                printf("syntax error\n");
                exit(0);
            }
            switch(c) {
                case '*':
                    sc--;
                    a = stack[sc];
                    sc--;
                    b = stack[sc];
                    stack[sc] = a * b;
                    break;
                case '/':
                    sc--;
                    a = stack[sc];
                    sc--;
                    b = stack[sc];
                    if(a == 0) {
                        printf("division by zero\n");
                        exit(0);
                    }
                    stack[sc] = b / a;
                    break;
                case '+':
                    sc--;
                    a = stack[sc];
                    sc--;
                    b = stack[sc];
                    stack[sc] = a + b;
                    break;
                case '-':
                    sc--;
                    a = stack[sc];
                    sc--;
                    b = stack[sc];
                    stack[sc] = b - a;
                    break;
            }
            sc++;
        }
    }
    sc--;
    if(sc > 0) {
        printf("syntax error\n");
        exit(0);
    }
    printf("%d", stack[sc]);

}