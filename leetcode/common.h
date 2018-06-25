#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MY_DEBUG

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct Interval
{
    int start;
    int end;
};