#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX(a,b) (((a)>(b))? (a):(b))

int pickingNumbers(int a_size, int* a) {
    int count[100] = {0};
    int max;
    
    for(int i=0; i<a_size; ++i)
    {
        count[ a[i] ]++;
    }
    
    max = count[98]+count[99];
        
    for(int i=0; i<=98; ++i)
    {
        int len = count[i] + count[i+1];
        max = MAX(max, len);
    }
    return max;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int result = pickingNumbers(n, a);
    printf("%d\n", result);
    return 0;
}
