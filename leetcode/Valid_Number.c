
#include "common.h"

#ifdef MY_DEBUG
#define msg(fmt, args...)   printf(fmt, ##args)
#else
#define msg(fmt, args...)
#endif // MY_DEBUG

bool isDigit(char c)
{
    return ('0'<= c && c <= '9');
}

bool pattern_fac(char *s, int idx)
{
    bool base = false;
    bool fanc = false;

    msg("%s %d\n", s, idx);

    if( *s == '-' || *s == '+')
    {
        s++;
        idx--;
    }

    for(int i=0; i<idx; ++i)
    {
        if( isDigit(s[i]) == false )
        {
            return false;
        }
        else
        {
            base = true;
        }
    }

    for(int i=idx+1; i<strlen(s); ++i)
    {
        if( isDigit(s[i]) == false )
        {
            return false;
        }
        else
        {
            fanc = true;
        }
    }

    return base || fanc;
}

bool pattern_num(char *s)
{
    if( *s == '-' || *s == '+')
        s++;

    if( strlen(s) == 0 )
        return false;

    for( int i=0; i<strlen(s); ++i)
    {
        if( isDigit(s[i]) == false )
        {
            return false;
        }
    }
    return true;
}

bool pattern_exp(char *s, int idx)
{
    bool base = false;
    bool fanc = false;

    if( idx == 0 )
        return false;

    s[idx] = 0;

    base = pattern_fac(s, idx);

    fanc = pattern_num(s+idx+1);

    msg("%d %d\n", base, fanc);

    return base && fanc;
}


bool isNumber(char* s)
{
    int dot = -1;
    int exp = -1;

    while( *s == ' ' )
    {
        s++;
    }

    for(int i=strlen(s)-1; i>=0; --i)
    {
        if( s[i] == ' ')
        {
            s[i] = 0;
        }
        else
        {
            break;
        }
    }

    if( strlen(s) == 0 )
    {
        return 0;
    }

    for( int i=0; i<strlen(s); ++i)
    {
        if( s[i] == 'e' )
        {
            if( exp != -1 )
            {
                return false;
            }
            exp = i;
        }

        if( s[i] == '.' )
        {
            if( dot != -1 )
            {
                return false;
            }
            dot = i;
        }
    }

    msg("%d %d\n", dot, exp);

    if( dot >= 0 && exp >= 0 )
    {
        if( dot > exp )
        {
            return false;
        }

        s[exp] = 0;
        bool fanc = pattern_fac(s, dot);
        bool numb = pattern_num(s+exp+1);
        return fanc && numb;
    }

    if( dot >= 0 )
    {
        return pattern_fac(s, dot);
    }

    if( exp >= 0 )
    {
        return pattern_exp(s, exp);
    }

    return pattern_num(s);
}