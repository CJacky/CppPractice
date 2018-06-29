#include <bits/stdc++.h>
#include <math.h>

using namespace std;

vector<string> split_string(string);

#if 0
#define msg(fmt, args...)       printf(fmt, ##args)
#else
#define msg(fmt, args...)
#endif

typedef enum
{
    ANG_UP,
    ANG_DOWN,
    ANG_LEFT,
    ANG_RIGHT,
    ANG_RIGHT_UP,
    ANG_RIGHT_DOWN,
    ANG_LEFT_UP,
    ANG_LEFT_DOWN
}ANG;

typedef struct _Node
{
    ANG type;
    float ang;
    int len;
}Node;

Node cal_node(int x1, int y1, int x2, int y2)
{
    Node node;
    
    if( x1 == x2 )
    {
        if( y2 > y1 )
        {
            node.type = ANG_RIGHT;    
            node.ang = 0.0;
        }
        else
        {
            node.type = ANG_LEFT;    
            node.ang = 0.0;
        }
        node.len = abs(y1-y2);
    }
    else if( y2 == y1 )
    {
        if( x2 > x1 )
        {
            node.type = ANG_UP;    
            node.ang = 0.0;
        }
        else 
        {
            node.type = ANG_DOWN;    
            node.ang = 0.0;
        }            
        node.len = abs(x1-x2);
    }
    else
    {
        if( x2 > x1 && y2 > y1)
        {
            node.type = ANG_RIGHT_UP;
        }
        else if( x2 > x1 && y2 < y1)
        {
            node.type = ANG_LEFT_UP;
        }
        else if( x2 < x1 && y2 < y1)
        {
            node.type = ANG_LEFT_DOWN;
        }
        else // if( x2 < x1 && y2 > y1)
        {
            node.type = ANG_RIGHT_DOWN;
        }  
        node.ang = (float)(y2-y1)/(x2-x1);
        node.len = min( abs(x1-x2), abs(y1-y2) );
    }
    
    return node;
}

int attack_check(int x1, int y1, int x2, int y2, vector<vector<int>> obstacles)
{
    msg("p1(%d, %d) p2(%d, %d)\n", x1, y1, x2, y2);
    
    if( x1 == x2 && y1 == y2 )
        return 0;
    
    Node node = cal_node(x1, y1, x2, y2);
    int min_len = node.len;
    int min_idx = -1;
    
    msg("    ang(%d, %f), len(%d)\n", node.type, node.ang, node.len);
    
    for(int i=0; i<obstacles.size(); ++i)
    {
        Node node_tmp = cal_node(x1, y1, obstacles[i][0], obstacles[i][1]);
        if( node_tmp.type == node.type && node_tmp.ang == node.ang && node_tmp.len < min_len )
        {
            msg("    px(%d, %d), ang(%d, %f), len(%d)\n", obstacles[i][0], obstacles[i][1], 
                node_tmp.type, node_tmp.ang, node_tmp.len);
            min_idx = i;
            min_len = node_tmp.len;
        }
    }
    
    if( min_idx >= 0 )
    {
        msg("    min point(%d, %d)\n", obstacles[min_idx][0], obstacles[min_idx][1]);
        min_len--;
    }
    
    msg("    min_len = %d\n", min_len);
    return min_len;
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int attack = 0;
    int x, y;
    
    attack += attack_check(r_q, c_q, n, c_q, obstacles); // up
    
    attack += attack_check(r_q, c_q, 1, c_q, obstacles); // down
    
    attack += attack_check(r_q, c_q, r_q, 1, obstacles); // left
    
    attack += attack_check(r_q, c_q, r_q, n, obstacles); // right
    
    for(x=r_q, y=c_q; x<n && y<n; ++x, ++y);
    attack += attack_check(r_q, c_q, x, y, obstacles); // right-up
    
    for(x=r_q, y=c_q; x>1 && y<n; --x, ++y);
    attack += attack_check(r_q, c_q, x, y, obstacles); // right-down
    
    for(x=r_q, y=c_q; x<n && y>1; ++x, --y);
    attack += attack_check(r_q, c_q, x, y, obstacles); // left-up
    
    for(x=r_q, y=c_q; x>1 && y>1; --x, --y);
    attack += attack_check(r_q, c_q, x, y, obstacles); // left-down
    
    return  attack;
}

int main()
    
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

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
