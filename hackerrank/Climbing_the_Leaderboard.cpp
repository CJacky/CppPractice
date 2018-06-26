#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice)
{
    vector<int> rank;
    vector<int> result;
    
    rank.push_back(scores[0]);
    for(int i=1; i<scores.size(); i++)
    {
        if( scores[i] != rank.back() )    
        {
            rank.push_back(scores[i]);
        }
    }
    
    for(int i=0; i<alice.size(); ++i)
    {
        if( alice[i] >= rank[0])
        {
            result.push_back(1);
        }
        else if( alice[i] < rank[rank.size()-1])
        {
            result.push_back(rank.size()+1);
        }
        else
        {
            int A = 0;
            int B = rank.size()-1;

            cout<<"alice = "<<alice[i]<<endl;
            while( 1 )
            {
                int X = rank[(A+B)/2];
                /*
                cout << "A = rank[" << A << "] = " << rank[A];
                cout << ", B = rank[" << B << "] = " << rank[B];
                cout << ", X = rank[" << (A+B)/2 << "] = " << X << endl;
                */
                if( alice[i] == X )
                {
                    result.push_back((A+B)/2+1);
                    break;                                     
                }
                else if( alice[i] == rank[A] )
                {
                    result.push_back(A+1);
                    break;
                }
                else if( alice[i] == rank[B] )
                {
                    result.push_back(B+1);
                    break;
                }
                else if( B - A == 1 && rank[A] > alice[i] && alice[i] > rank[B] )
                {
                    result.push_back(B+1);
                    break;
                }
                else if( alice[i] > X )
                {
                    B = (A+B)/2;
                }
                else if( alice[i] < X )
                {
                    A = (A+B)/2;
                }
            }
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
