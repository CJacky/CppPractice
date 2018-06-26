#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SLOT_MAX_ZERO   (4)
#define SLOT_MAX        ((int)pow(10, SLOT_MAX_ZERO))

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n)
{
    vector<int> ans;
    ans.push_back(1);
    
    for(int i=1; i<=n; ++i)
    {
        //cout<<"i="<<i<<endl;
        for(int j=0; j<ans.size(); ++j)
        {
            ans[j] *= i;
        }
        for(int j=0; j<ans.size(); ++j)
        {
            if( ans[j] >= SLOT_MAX )
            {
                if( j == ans.size()-1 )
                {
                    ans.push_back(ans[j]/SLOT_MAX);
                    ans[j] = ans[j] % SLOT_MAX;
                }
                else
                {
                    ans[j+1] += ans[j]/SLOT_MAX;
                    ans[j] = ans[j] % SLOT_MAX;
                }
            }
            //cout<<"ans["<< j <<"] = "<<ans[j]<<endl;
        }
    }
    
    printf("%d", ans.back());
    for(int j=ans.size()-2; j>=0; --j)
    {
        printf("%0*d", SLOT_MAX_ZERO, ans[j]);
    }
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
