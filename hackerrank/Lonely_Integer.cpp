#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector <int> a) {
    // Complete this function
    int table[101] = {0};
    for( vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        table[ *it ]++;
    }
    for(int i=0; i<=100; ++i)
    {
        if( table[i] == 1 )
        {
            return i;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = lonelyinteger(a);
    cout << result << endl;
    return 0;
}
