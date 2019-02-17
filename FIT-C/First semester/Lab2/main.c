#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

#define K 100000

long seek_substring_BM(char *s, char *q, long Position, long lSize);

int main()
{
    char * tmpl = (char*) malloc(sizeof(char) * 17);
    long lSize, PosTmplEnd, Position, charRead, oldPosition;
    int l;

    for(int i = 0; i < 17; i++)
        tmpl[i] = '\0';

    FILE * ptrFile = fopen( "in.txt" , "rt" );

    if (ptrFile == NULL) {
        fputs("Ошибка файла", stderr);
        exit(1);
    }

    // определяем размер файла
    fseek(ptrFile , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
    lSize = ftell(ptrFile);                            // получаем размер в байтах
    rewind (ptrFile);                                       // устанавливаем указатель в начало файла

    char * buffer = (char*) malloc(sizeof(char) * (K + 1)); // выделяем память для хранения содержимого файла
    if (buffer == NULL) {
        fputs("Ошибка памяти", stderr);
        exit(2);
    }
    rewind (ptrFile);
    fgets(tmpl, 17, ptrFile);
    for(l = 16; l >= 0; l--)
        if(tmpl[l] == '\r' || tmpl[l] == '\n') break;
    tmpl[l] = '\0';
    PosTmplEnd = strlen(tmpl) + 2;
    Position = 0;
    fseek(ptrFile , Position +  PosTmplEnd, SEEK_SET);
    while(1) {
        charRead = lSize - Position - PosTmplEnd > K ? K + 1 : lSize - Position  - PosTmplEnd;
        charRead = fread(buffer, 1, charRead, ptrFile);
        buffer[charRead] = '\0';
        oldPosition = Position;
        Position = seek_substring_BM(buffer, tmpl, Position, lSize)  - (PosTmplEnd - 2) + 1;
        if(feof(ptrFile) || charRead == 0) break;
        if(Position + 1 - PosTmplEnd + 2 < 0) break;
        if(Position  + 1 + PosTmplEnd + 4 >= lSize) break;
        fseek(ptrFile, Position - charRead - oldPosition, SEEK_CUR);
    }
    fclose (ptrFile);
    free(buffer);
    //system("pause");
    return 0;
}

int compare(char c1, char c2, int k) {
    printf("%d ", k);
    if(c1 == c2)
        return 1;
    else
        return 0;
}

long seek_substring_BM(char *s, char *q, long Position, long lSize) {
    int d[256];
    int i, j, k, N, M;
    M = strlen(q);
    N = strlen(s);
    if(M + 2 >= lSize) exit(0);
    for(i = 0; i < 256; i++)
        d[i] = M;
    for(i = 0; i < M - 1; i++)
        d[(unsigned char)(q[i])] = M - i - 1;
    i = M - 1;
    do {
        j = M - 1;
        k = i;
        while ((j >= 0) && (compare(q[j], s[k], k + 1 + Position))) {
            k--;
            j--;
        }
        //if(j < 0) exit(0);
        i += d[(unsigned char)s[i]];
    } while (i < N);
    return i + Position;
}
