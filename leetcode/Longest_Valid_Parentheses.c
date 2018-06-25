int longestValidParentheses(char* s)
{
    int len = strlen(s);
    
    int *Left = malloc(sizeof(int)*len);
    int LeftIdx = 0;
    
    int max = 0;
    int dot = 0;
    
    for(int i=0; i<len; ++i)
    {
        
        if( s[i] == '(' )
        {
            Left[ LeftIdx++ ] = i;
        }
        else
        {
            if( LeftIdx > 0 )
            {
                s[i] = '.';
                s[ Left[ --LeftIdx ] ] = '.';
            }
        }
    }
    
    for(int i=0; i<len; ++i)
    {
        if( s[i] == '.' )
        {
            ++dot;
        }
        else
        {
            dot = 0;
        }
        if( dot > max )
        {
            max = dot;
        }
    }
    
    return max;
}
