#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 1009;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const char dir[] = {'U', 'R', 'D', 'L'};

int mat[N][N];
int n, m;
char s[N];
vector<PI> monsters;
PI start;

inline bool inmat(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}


void Lee()
{
    queue<pair<PI, bool>> q;

    for(auto i : monsters)
    {
        q.push({{i.F, i.S}, true});
        mat[i.F][i.S] = -3;
    }

    q.push({{start.F, start.S}, false});
    mat[start.F][start.S] = 1;




    while(!q.empty())
    {
        int x = q.front().F.F,
        y = q.front().F.S;
        bool ismonster = q.front().S;
        q.pop();

        for(int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(!inmat(nx, ny) || mat[nx][ny] != 0)continue;

            if(ismonster)
                mat[nx][ny] = -3;
            else
                mat[nx][ny] = mat[x][y] + 1;

            q.push({{nx, ny}, ismonster});
        }
    }
}

int main()
{
    cin >> n >> m;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s, N);
        cin.get();

        for(int j = 1; j <= m; ++j)
        {
            if(s[j - 1] == '#')
                mat[i][j] = -3;
            else if(s[j - 1] == 'A')
                start = {i, j};
            else if(s[j - 1] == 'M')
                monsters.push_back({i, j});
        }
    }

    Lee();

    bool possible = false;
    PI poz;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || i == n)
        {
            for(int j = 1; j <= m; ++j)
                if(mat[i][j] >= 0)
                {
                    possible = true;
                    poz = {i, j};
                }
        }
        else
        {
            if(mat[i][1] >= 0)
            {
                possible = true;
                poz = {i, 1};
            }
            else if(mat[i][m] >= 0)
            {
                possible = true;
                poz = {i, m};
            }
        }
    }



    if(!possible)
    {
        cout << "NO";
        return 0;
    }


    cout << "YES\n";
    vector<int> moves;
    while(poz != start)
    {
        int x = poz.F,
        y = poz.S;

        for(int k = 0; k < 4; ++k)
        {
            int nx = x - dx[k];
            int ny = y - dy[k];

            if(inmat(nx, ny) && mat[nx][ny] + 1 == mat[x][y])
            {
                moves.push_back(k);
                poz = {nx, ny};
                break;
            }
        }
    }

    cout << moves.size() << '\n';
    for(int i = moves.size() - 1; i >= 0; --i)
        cout << dir[moves[i]];


    return 0;
}
