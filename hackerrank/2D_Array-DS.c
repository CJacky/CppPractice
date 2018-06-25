#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int func(int map[6][6], int x, int y)
{
    return map[x  ][y] + map[x  ][y+1] + map[x  ][y+2]
                       + map[x+1][y+1] +
           map[x+2][y] + map[x+2][y+1] + map[x+2][y+2];
}

int main(){
    int arr[6][6];
    int max = INT_MIN , tmp;
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    for(int i=0; i<=3; ++i )
    {
        for(int j=0; j<=3; ++j)
        {
            tmp = func(arr, i, j);
            if(tmp > max)
            {
                max = tmp;
            }
        }   
    }
    
    printf("%d\n", max);

    
    return 0;
}
