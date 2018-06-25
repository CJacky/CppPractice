#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n; 
    char *unit[100][8192] = {0};
    scanf("%i", &n);
    
    for(int i = 0; i < n; i++)
    {
        char s[16] = {0};
        int x;
        scanf("%i %s", &x, s);
        if( i < n/2 )
        {
            strcat(unit[x], "- ");
        }
        else
        {
            s[ strlen(s)] = ' ';
            strcat(unit[x], s);
        }
    }
    
    for(int i = 0; i < 100; i++)
    {
        printf("%s", unit[i]);
    }
    printf("\n");
    
    return 0;
}
