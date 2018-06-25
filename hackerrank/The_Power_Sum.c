#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DBG 0

#if DBG == 1
#define PRINT(fmt, args...) printf(fmt, ##args)
#else
#define PRINT(fmt, args...)
#endif // DBG

int myPow(int b, int e)
{
    int ans = 1;
    
    if( e == 0 )
    {
        return 0;
    }

    while(e-->0)
    {
        ans *= b;
    }
    return ans;
}

int func(int x, int n, int s)
{
    int i, v, r = 0;

    PRINT("%d %d %d\n",  x,  n, s);
    for( i=s; (v=myPow(i, n)) <= x; ++i )
    {
        if( v == x )
        {
            r++;
        }
        else
        {
            r += func(x - v, n, i+1);
        }
    }
    return r;
}

int main() {
    int x = 100, n = 2;
    int ans = 0;
#if DBG == 0
    scanf("%d %d\n", &x, &n);
#endif // DBG

    ans = func( x, n, 1 );

    printf("%d\n", ans);

    return 0;
}
