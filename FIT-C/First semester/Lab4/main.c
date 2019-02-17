#include<stdio.h>
#include <mem.h>
#include <stdlib.h>

#define true 0
#define false 1

typedef int bool;

int main() {
    FILE *in;
    int per[10], obr[10];
    int i, j, k, tmp, min, raz, n, N;
    char perChar[10];
    bool flag;
    in   = fopen("in.txt", "r");

    fscanf(in, "%s", perChar);
    fscanf(in, "%d", &N);
    n = strlen(perChar);
    if(n > 10) n = 10;
    int counter[10] = {0};
    for(int p = 0; p < n; p++) {
        counter[(perChar[p] - '0')]++;
        if(counter[(perChar[p] - '0')] > 1 || ((perChar[p] - '0') < 0 || (perChar[p] - '0') > 9)) {
            printf("bad input");
            exit(0);
        }
    }
    for (i = 0; i < n; i++) {
        per[i] = perChar[i] - '0';
    }
    for(int x = 0; x < N; x++) {
        flag = false;
        for (i = n - 2; i >= 0; i--) {
            if (per[i] < per[i + 1]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            break;
        }
        raz = per[i+1];
        min = i + 1;
        for (j = i+1; j < n; j++) {
            if (((per[j] - per[i]) < raz) && (per[i] < per[j])) {
                min = j;
            }
        }
        tmp = per[i];
        per[i] = per[min];
        per[min] = tmp;
        for (j = i + 1; j < n; j++) {
            obr[j] = per[j];
        }
        j = i + 1;
        for (k = n-1; k >= i+1; k--) {
            per[j] = obr[k];
            j++;
        }
        for (k = 0; k < n; k++)
            printf("%d", per[k]);
        printf("\n");
    }
    fclose(in);
    //system("pause");
    return 0;
}