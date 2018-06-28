#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    long num = 0;
    long len = s.length();
    char *str = (char*)s.c_str();
    for(long i=0; i<len; ++i)
    {
        if( str[i] == 'a' )
        {
            num++;
        }
    }
    
    long ans = (n/len)*num;
    for(long i=0; i<n%len; ++i)
    {
        if( str[i] == 'a' )
        {
            ans++;
        }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
