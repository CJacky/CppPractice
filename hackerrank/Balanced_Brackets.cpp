#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s)
{
    bool result = true;
    stack<int> *backet = new stack<int>[3];

    for( size_t i=0; i<s.length(); ++i )
    {
        switch( s.at(i) )
        {
            case '(': backet[0].push(i); break;
            case '[': backet[1].push(i); break;
            case '{': backet[2].push(i); break;

            case ')':
                if( backet[0].empty() )
                {
                    result = false;
                }
                else
                {
                    int x = backet[0].top();
                    backet[0].pop();

                    if( !backet[1].empty() && backet[1].top() > x )
                    {
                        result = false;
                    }
                    if( !backet[2].empty() && backet[2].top() > x )
                    {
                        result = false;
                    }
                }
                break;

            case ']':
                if( backet[1].empty() )
                {
                    result = false;
                }
                else
                {
                    int x = backet[1].top();
                    backet[1].pop();

                    if( !backet[0].empty() && backet[0].top() > x )
                    {
                        result = false;
                    }
                    if( !backet[2].empty() && backet[2].top() > x )
                    {
                        result = false;
                    }
                }
                break;

            case '}':
                if( backet[2].empty() )
                {
                    result = false;
                }
                else
                {
                    int x = backet[2].top();
                    backet[2].pop();

                    if( !backet[1].empty() && backet[1].top() > x )
                    {
                        result = false;
                    }
                    if( !backet[0].empty() && backet[0].top() > x )
                    {
                        result = false;
                    }
                }
                break;

            default:
                result = false;
                break;
        }
    }

    if( !backet[0].empty() || !backet[1].empty() || !backet[2].empty())
    {
        result = false;
    }

    return result? "YES":"NO";
}

int main()
{


    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}

