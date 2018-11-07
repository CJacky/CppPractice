class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {       
        if( s.length() == 0 || s.length() == 1 )
        {
            return s.length();
        }
                
        int length[s.length()] = {0};
        length[0] = 1;
        
        for(int i=1; i<s.length(); ++i)
        {
            length[i] = length[i-1] + 1;
            
            for(int j=1; j<length[i]; ++j)
            {
                if( s[i-j] == s[i] )
                {
                    length[i] = j;
                    break;
                }
            }           
        }
        
        int lengthest = 0;
        for(int i=0; i<s.length(); ++i)
        {
            //cout << s[i] << " : " << length[i] << "\n";
            if( length[i] > lengthest)
            {
                lengthest = length[i];
            }
        }
        
        return lengthest;        
    }
};
