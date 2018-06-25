#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int formingMagicSquare(int s_size_rows, int s_size_cols, int s[3][3]) {
    int min = 4096;
    int sol[8][3][3] = {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}};
    
    for( int k=0; k<8; ++k)
    {
        int sum = 0;
        for(int i=0;i<3;++i)
        {
            for(int j=0; j<3; ++j)
            {
                sum += abs(s[i][j]-sol[k][i][j]);
            }
        }
        if( sum < min)
        {
            min = sum;
        }
    }
    return min;
}

int main() {
    int s[3][3];
    for (int s_i = 0; s_i < 3; s_i++) {
       for (int s_j = 0; s_j < 3; s_j++) {
      
          scanf("%i",&s[s_i][s_j]);
       }
    }
    int result = formingMagicSquare(3, 3, s);
    printf("%d\n", result);
    return 0;
}
