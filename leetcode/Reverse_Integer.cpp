class Solution {
public:
    int reverse(int x)
    {
        int sign;
        int64_t in  = x;
        int64_t out = 0;
        
        while( x != 0 )
        {
            out = (out*10) + (x%10);
            
            if( out > INT_MAX || out < INT_MIN )
            {
                return 0;
            }    
            
            x /= 10;
        }
        return (int)out;
    }
};
