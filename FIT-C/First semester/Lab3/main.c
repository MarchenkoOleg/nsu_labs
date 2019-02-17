#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define K 50//860000 //65536

long IntPower(int x, int power);

int main() {
    long tmplHash = 0, bufferHash = 0;
    char *tmpl = (char *) malloc(sizeof(char) * 19);
    for (int i = 0; i < 19; i++)
        tmpl[i] = '\0';
    FILE *ptrFile = fopen("in.txt", "rt");
    char *buffer = (char *) malloc(sizeof(char) * (2*K + 1));
    buffer[2 * K + 1] = '\0';
    buffer[2 * K] = '\n';
    if (buffer == NULL) {
        exit(2);
    }
    rewind(ptrFile);
    fgets(tmpl, 18, ptrFile);
    int l;
    for (l = 17; l >= 0; l--)
        if (tmpl[l] == '\r' || tmpl[l] == '\n') break;
    tmpl[l] = '\0';
    int tmplLen = strlen(tmpl);
    for(int i = 0; i < tmplLen; i++)
        tmplHash += ((unsigned)tmpl[i]%3)*(IntPower(3, i));
    printf("%ld ", tmplHash);
    long charRead, Position = 0, readPosition;
    Position -= (tmplLen - 1);
    do {
        //readPosition = Position != 0 ? Position % (2 * K) : 0;
        readPosition = (Position + (tmplLen - 1)) % (2 * K - 1);
        charRead = (long)fread(&buffer[readPosition], 1, K, ptrFile);
        if(bufferHash == 0) {
            Position = 0;
            for(int i = 0; i < tmplLen - 1; i++)
                bufferHash += ((unsigned)buffer[i]%3)*(IntPower(3, i));
        }
        buffer[((charRead + readPosition) % (2 * K))] = '\n';
        for(int p = 0; p < charRead - (tmplLen - 1); p++) {
            readPosition = (Position + tmplLen - 1) % (2*K);
            bufferHash += ((unsigned)buffer[readPosition]%3)*(IntPower(3, tmplLen - 1));
            if(tmplHash == bufferHash) {
                for (int c = 0; c < tmplLen; c++) {
                    printf("%d ", c + (Position + 1));
                    if (buffer[(c + Position) % (2 * K)] != tmpl[c]) break;
                }
            }
            bufferHash -= ((unsigned)buffer[Position % (2*K)]%3);
            bufferHash /= 3;
            Position++;
        }


        //Position += 1;
    } while(!feof(ptrFile));
    //system("pause");


    return 0;
}

long IntPower(int x, int power)  {
    if (power == 0) return 1;
    if (power == 1) return x;
    long result = 1;
    while(power) {
        if(power & 1) result *= x;
        power >>= 1;
        x=x*x;
    }
    return result ;
}