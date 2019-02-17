#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char IntToChar(unsigned int in);

unsigned int CharToInt(char in);

void CheckInputValues(unsigned int b1, unsigned int b2, char *CharArray);

double ToDec(double b1, char *CharArray);

void FromDec(int b2, double Numeric);

int main() {
    int b1;
    int b2;
    char CharArray[14] = {0};
    double Result;

    scanf("%d %d %13s", &b1, &b2, CharArray);
    CheckInputValues(b1, b2, CharArray);
    Result = ToDec(b1, CharArray);
    FromDec(b2, Result);
    //system("pause");
    return 0;
}

char IntToChar(unsigned int in) {
    if(in < 10) return (char)(in + 48);
    else return (char)(in + 55);
}

unsigned int CharToInt(char in) {
    if(in == '\0') return 0;
    char alphabet[] = {"ABCDEF"};
    int k;
    for(k = 0; k < 7; k++) {
        if(in == alphabet[k]) {
            return k +10;
        }
    }
    return (in -'0');
}

void CheckInputValues(unsigned int b1, unsigned int b2, char *CharArray) {

    int i, k = 0;

    if(b1 < 2 || b1 > 16 )
        printf("bad input 0\n");

    if( b2 < 2 || b2 > 16)
        printf("bad input 1\n");


    if(CharArray[0] == '.')
        printf("bad input 2\n");

    for(i = 0; i < 13; i++) {
        CharArray[i] = toupper(CharArray[i]);
        if(CharArray[i] == '\0') break;
        if(CharArray[i] == '.') {
            if(CharArray[i+1] == '\0')
                printf("bad input 3\n");

            k++;
            if(k > 1)
                printf("bad input 4\n");

            continue;
        }
        if(CharToInt(CharArray[i]) >= b1)
            printf("bad input 5 %c\n", CharArray[i]);
    }
}



void FromDec(int b2, double Numeric) {
    double WholePart;
    char k;
    double FractionalPart = modf(Numeric, &WholePart);
    char CharArray[52] = {0};
    int c = 0;
    if(WholePart == 0) printf("0");
    else {
        while((int)WholePart !=0) {
            k = IntToChar((int)(fmod(WholePart,b2)));
            CharArray[c] = k;
            c++;
            WholePart /= b2;
        }
        c--;
        do{
            printf("%c", CharArray[c]);
            c--;
        } while(c >= 0);
    }

    if(FractionalPart > 0) {
        printf(".");
        unsigned int x, l;
        for(x=0; x < 12; x++) {
            l = FractionalPart * b2;
            printf("%c", IntToChar(l));
            FractionalPart = FractionalPart*b2 - l;
            if(FractionalPart == 0) break;
        }
    }
}

double ToDec(double b1, char *CharArray) {
    double Numeric;
    int i;
    double WholePart, Result;
    double FractionalPart;
    Numeric = CharToInt(CharArray[0]);
    WholePart = Numeric;
    for(i = 1;; i++) {
        if(CharArray[i] == '.' ||  CharArray[i] == '\0') break;
        Numeric = CharToInt(CharArray[i]);
        WholePart = WholePart*b1 + Numeric;
    }
    FractionalPart = 0;
    if(CharArray[i] != '\0') {
        int m = i;
        for(; CharArray[m] != '\0'; m++);
        for (int p = m - 1; CharArray[p] != '.'; p--) {
            Numeric = CharToInt(CharArray[p]);
            if (CharArray[p] == '\0') break;
            FractionalPart = (Numeric + FractionalPart) / b1;
        }
    }
    Result = WholePart + FractionalPart;

    return Result;
}



