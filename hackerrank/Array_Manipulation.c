#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n; 
    int m; 
    int *arr;
    scanf("%i %i", &n, &m);
    
    arr = (int*)malloc(n * sizeof(int));
    memset(arr, 0, n * sizeof(int));
    
    for(int a0 = 0; a0 < m; a0++){
        int a; 
        int b; 
        int k; 
        scanf("%i %i %i", &a, &b, &k);
        arr[a-1] += k;
        arr[b] -= k;
    }
    
    uint64_t max = 0;
    uint64_t cur = 0;
    for(int i=0; i<n; ++i)
    {
        cur += arr[i];
        if( cur > max )
        {
            max = cur;
        }
    }
    
    printf("%"PRIu64"\n", max);
    
    return 0;
}
