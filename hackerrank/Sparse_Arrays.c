/*
Sparse Arrays
https://www.hackerrank.com/challenges/sparse-arrays/problem
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LEN 21

int main()
{
    int N, Q;
    char **str;
    char q[LEN];
    int i, j, ans;

    scanf("%d", &N);
    str = (char**)malloc( N * sizeof(char*));
    for(i=0; i<N; ++i)
    {
        str[i] = (char*)malloc(LEN * sizeof(char));
        memset(str[i], 0, LEN);
        scanf("%s", str[i]);
    }

    scanf("%d", &Q);
    for(i=0; i<Q; ++i)
    {
        memset(q, 0, LEN);
        scanf("%s", q);
        ans = 0;
        for(j=0; j<N; ++j)
        {
            if(strcmp(q, str[j]) == 0)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
