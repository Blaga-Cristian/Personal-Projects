#include <bits/stdc++.h>

using namespace std;
const string TASK("sortaret");
//ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
#define cout fout
auto fin = fopen("sortaret.in", "r");
void next();
void get(int&);

const int N = 1e5 + 9;

int n, m, in[N];
vector<vector<int>> G(N);

vector<int> ord;
bool viz[N];
void Dfs(int x)
{
    viz[x] = true;
    for(auto y : G[x])
        if(!viz[y])
            Dfs(y);
    ord.push_back(x);
}

int main()
{
    next();

    get(n), get(m);

    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        get(x), get(y);
        G[x].push_back(y);
        in[y] ++;
    }

    for(int i = 1; i <= n; ++i)
        if(!in[i])
            Dfs(i);

    reverse(ord.begin(), ord.end());

    for(auto i : ord)cout << i << ' ';
    cout << '\n';
    return 0;
}


const int Lim = 1e6;
char s[Lim];
int p = Lim - 1;

void next()
{
    if(++p == Lim)
    {
        p = 0;
        fread(s, 1, Lim, fin);
    }
}

void get(int& x)
{
    while(s[p] != '-' && !isdigit(s[p]))next();

    int sgn = 1;
    if(s[p] == '-')sgn = -1, next();

    for(x = 0; isdigit(s[p]); next())
        x = x * 10 + s[p] - '0';
    x *= sgn;
}
