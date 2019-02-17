#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class String {
private:
    char *str;
    int len;
    int len_now;

public:
    String(int size = 10) {
        len = size;
        str = (char *) malloc(size);
        len_now = 0;
    }
    void append(char c) {
        if(len_now == len) {
            str = (char *) realloc(str, len*2);
            len *= 2;
        }
        str[len_now++] = c;
    }
    ~String() {
        free(str);
    }

};
int main() {
    String str(10);

    char c;
    do {
        scanf("%c", &c);
        str.append(c);
    } while(c != '\n');
    std::cout << "Hello, World!" << std::endl;
    return 0;
}