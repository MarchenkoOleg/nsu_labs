#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

void write_to_file(FILE *pIobuf, char **pString, int lines);

void qs(char **s_arr, int first, int last, int max);

int main() {
    FILE * in = fopen("in.txt", "r");
    if(in == NULL) exit(1);
    FILE *out;
    out  = fopen("out.txt", "w");
    if(out == NULL) exit(1);
    char c;
    int max = 0, counter, line_counter = 0, d;
    while(!feof(in)) {
        counter = 0;
        while(((c = (char) fgetc(in)) != '\n') && (c != EOF))
            counter++;
        if(counter > max) max = counter;
        line_counter++;
    }
    rewind(in);
    char ** array = (char **) malloc(line_counter * sizeof(char *));
    for(int i = 0; i < line_counter; i++) {
        array[i] = (char *) malloc((max + 1) * sizeof(char));
        fscanf(in,"%s",array[i]);
    }
    qs(array, 0, line_counter - 1, max);
    write_to_file(out, array, line_counter);
    fclose(in);
    fclose(out);
    free(array);
    return 0;
}

void write_to_file(FILE *pIobuf, char **pString, int lines) {
    for(int i = 0; i < lines; i++)
        fprintf(pIobuf, "%s\n", pString[i]);
}

void qs(char **s_arr, int first, int last, int max) {
    if (first < last)
    {
        int left = first, right = last;
        char * middle;
        middle = s_arr[(left + right) / 2];
        do
        {
            while (strcmp(middle, s_arr[left]) > 0) left++;
            while (strcmp(s_arr[right], middle) > 0) right--;
            if (left <= right)
            {
                char * tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right, max);
        qs(s_arr, left, last, max);
    }
}