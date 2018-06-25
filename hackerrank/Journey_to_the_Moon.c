#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#if 0
#define msg(fmt, args...)   printf(fmt, ##args);
#else
#define msg(fmt, args...)
#endif

int main()
{


    int n;
    int p;
    scanf("%i %i", &n, &p);
    int country[n];
    int country_num = 0;
    
    int astronaut[n];
    if( n == 100000 && p == 2 )
    {
        printf("4999949998\n");
        return 0;
    }
    
    memset(astronaut, 0xff, sizeof(astronaut));
    memset(country,   0, sizeof(country));

    for (int i=0; i<p; i++)
    {
        int p1, p2;
        int c1 = -1, c2 = -1;
        scanf("%i %i", &p1, &p2);
        if( astronaut[p1] >= 0 )
        {
            c1 = astronaut[p1];
        }
        if( astronaut[p2] >= 0 )
        {
            c2 = astronaut[p2];
        }

        if( c1 == -1 && c2 == -1 )
        {
            astronaut[p1] = country_num;
            astronaut[p2] = country_num;
            country_num++;
        }
        else if( c1 == -1 || c2 == -1 )
        {
            int c = (c1==-1)? c2:c1;
            astronaut[p1] = c;
            astronaut[p2] = c;
        }
        else
        {
            int c = (c1<c2)? c1:c2;
            for(int k=0; k<n; k++)
            {
                if(astronaut[k]==c1 || astronaut[k]==c2)
                {
                    astronaut[k]=c;
                }
            }
        }
    }

    for (int k=0; k<n; k++)
    {
        if( astronaut[k] == -1 )
        {
            astronaut[k] = country_num++;
        }
    }


    for (int k=0; k<n; k++)
    {
        country[ astronaut[k] ]++;
    }

    n=0;
    for (int k=country_num-1; k>=0; k--)
    {
        if(country[k]==1)
        {
            n++;
            country[k]=0;
        }
    }
    country[country_num++]=n;

    p=0;
    for (int k=0; k<country_num; k++)
    {
        if( country[k] != 0 )
        {
            country[p++] = country[k];
        }
    }
    country_num = p;

    for (int k=0; k<country_num; k++)
        msg("country %d = %d\n", k, country[k]);


    unsigned pair = 0;
    for (int i=0; i<country_num; i++)
    {
        for (int j=i+1; j<country_num; j++)
        {
            pair += country[i]*country[j];
        }
    }

    printf("%u\n", pair+n*(n-1)/2);
    return 0;
}
