#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class String{
    char * str;
    int len;
    int len_now;

    void append(char c) {
        if(len_now == len) {
            str = (char *) realloc(str, len * 2);
            len *= 2;
        }
        str[len_now++] =c;

    }

    void init(int size) {
        len_now = 0;
        len = size;
        str = 0;

    }

    void free_memory() {
        free(this->str);
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
