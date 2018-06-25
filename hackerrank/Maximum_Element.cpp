#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{


    list<unsigned int> myStack;
    unsigned int myMax = 0;
    unsigned int x, value;
    int cmd;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    while( cin >> cmd )
    {
        switch( cmd )
        {
            case 1:
                cin >> x;
                myStack.push_back(x);
                if( x > myMax )
                {
                    myMax = x;
                }
                break;

            case 2:
                value = myStack.back();
                myStack.pop_back();
                if( value == myMax )
                {
                    myMax = 0;
                    for( list<unsigned int>::iterator it = myStack.begin(); it!=myStack.end(); ++it)
                    {
                        if( *it > myMax )
                        {
                            myMax = *it;
                        }
                    }
                }
                break;

            case 3:
                cout << myMax << endl;
                break;

            default:
                break;
        }
    }
    return 0;
}
