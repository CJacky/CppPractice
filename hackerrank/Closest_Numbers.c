#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* closestNumbers(int arr_size, int* arr, int *result_size) {
    int min = INT_MAX;
    int *ret = malloc(sizeof(int)*(2*arr_size-2));
    int idx = 0;
    for(int i=0; i<arr_size-1; ++i)
    {
        if( (arr[i+1] - arr[i]) < min )
        {
            min = arr[i+1] - arr[i];
        }
    }
    
    for(int i=0; i<arr_size-1; ++i)
    {
        if( (arr[i+1] - arr[i]) == min )
        {
            ret[idx++] = arr[i];
            ret[idx++] = arr[i+1];
        }
    }
    
    *result_size = idx;
    return ret;
}

int main() {
    int n; 
    scanf("%i", &n);
    int *arr = malloc(sizeof(int) * n);
    
    for (int i=0, j; i<n; i++)
    {
        int x;
        scanf("%i", &x);
        //printf("inser: %i %i\n", i, x);
        for(j=i-1; j>=0; j--)
        {
            if( x > arr[j] )
            {
                j++;
                break;
            }
            arr[j+1] = arr[j];
        }
        if( j < 0 )
        {
            arr[0] = x;
        }
        else
        {
            arr[j] = x;
        }
/*        
        for (int k=0; k<n; k++)
        {
            printf("%i\n", arr[k]);
        }
*/        
    }
   
    
    
    //printf("ans:\n");
    int result_size;
    int* result = closestNumbers(n, arr, &result_size);
    for(int i = 0; i < result_size - 1; i++)
    {
        printf("%d ", result[i]); 
    }
    printf("%d\n", result[result_size - 1]);

    return 0;
}
