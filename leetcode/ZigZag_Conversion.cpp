class Solution {
public:
    string convert(string s, int numRows)
    {
        string str[numRows];
        string out;
        
        bool dir = true;
        int idx = 0;
        
        if( numRows == 1 )
        {
            return s;
        }
        
        for(auto c : s)
        {
            //cout << idx << " += " << c << "\n";
            str[idx] += c;
            
            if(dir)
            {
                if( idx+1 == numRows)
                {
                    dir = false;
                    idx--;
                }
                else
                {
                    idx++;
                }
            }
            else
            {
                if( idx == 0 )
                {
                    dir = true;
                    idx++;
                }
                else
                {
                    idx--;
                }
            }
        }
        
        for(int i=0; i<numRows; ++i)
        {
            //cout << str[i] << "\n";
            out += str[i];
        }
        
        return out;
    }
};
