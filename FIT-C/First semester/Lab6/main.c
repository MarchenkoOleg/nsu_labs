#include <stdio.h>
#include <stdlib.h>

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

int main() {
    FILE *in;
    in  = fopen("in.txt", "r");
    int n;
    fscanf(in, "%d", &n);
    int * a = (int *) malloc(n * sizeof(int));
    for(int k = 0; k < n; k++)
        fscanf(in, "%d", &a[k]);
    qs(a, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}