/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include "common.h"

#include <math.h>

#ifdef MY_DEBUG
#define msg(fmt, args...)   printf(fmt, ##args)
#else
#define msg(fmt, args...)
#endif // MY_DEBUG

#define isBetween(x, a, b)      ((a)<=(x)&&(x)<=(b))
#define max(a, b, c)            (((a)>(b)&&(a)>(c))? (a):((b)>(a)&&(b)>(c))? (b):(c))
#define min(a, b, c)            (((a)<(b)&&(a)<(c))? (a):((b)<(a)&&(b)<(c))? (b):(c))

static double test(struct Interval* intervals, int intervalsSize, int x)
{
    if(x < intervals[0].start)
    {
        return 0.5;
    }

    if(x > intervals[intervalsSize-1].end)
    {
        return intervalsSize + 0.5;
    }

    for(int i=0; i<intervalsSize; ++i)
    {
        if( isBetween(x, intervals[i].start, intervals[i].end))
        {
            return (double)i+1;
        }
        if( i+1<intervalsSize && isBetween(x, intervals[i].end+1, intervals[i+1].start-1))
        {
            return i+1.5;
        }
    }
    return -1.0;
}


struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize)
{
    double S, E;
    struct Interval* newArray = NULL;

    if( intervalsSize == 0 )
    {
        newArray = malloc(sizeof(struct Interval));
        memcpy(newArray, &newInterval, sizeof(struct Interval));
        *returnSize = 1;
        return newArray;
    }

    S = test(intervals, intervalsSize, newInterval.start);
    E = test(intervals, intervalsSize, newInterval.end);

    msg("%f %f\n", S, E);

    if( S == E && ceil(S) != floor(E) )
    {
        newArray = malloc(sizeof(struct Interval)*(intervalsSize+1));
        *returnSize = intervalsSize + 1;

        for(int i=0, j=0; i<intervalsSize;)
        {
            if( isBetween(S, i, i+1))
            {
                S = -1;
                memcpy(&newArray[j++], &newInterval, sizeof(struct Interval));
            }
            else
            {
                memcpy(&newArray[j++], &intervals[i++], sizeof(struct Interval));
            }
        }
        if( S >= 0 )
        {
            memcpy(&newArray[intervalsSize], &newInterval, sizeof(struct Interval));
        }
    }
    else
    {
        int Si = (int)ceil(S)-1;
        int Ei = (int)floor(E)-1;

        msg("%d %d\n", Si, Ei);

        intervals[Si].start = min(intervals[Si].start, intervals[Si].end, newInterval.start);
        intervals[Si].end   = max(intervals[Si].start, intervals[Si].end, newInterval.end);

        intervals[Ei].start = min(intervals[Ei].start, intervals[Ei].end, newInterval.start);
        intervals[Ei].end   = max(intervals[Ei].start, intervals[Ei].end, newInterval.end);

        intervals[Si].end = intervals[Ei].end;

        newArray = malloc(sizeof(struct Interval)*(intervalsSize - (Ei-Si)));
        for(int i=0, j=0; i<intervalsSize; i++)
        {
            if( !isBetween(i, Si+1, Ei) )
            {
                memcpy(&newArray[j++], &intervals[i], sizeof(struct Interval));
            }
        }

        *returnSize = intervalsSize - (Ei-Si);
    }

    return newArray;
}
