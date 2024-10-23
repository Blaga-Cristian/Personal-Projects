#include <bits/stdc++.h>
using namespace std;


const int N = 2 * 1e5 + 9;

int n, m, a, b, tvalue[N];
bool ans[N], viz[N];
vector<vector<int>> G, G1;
char sgn;

vector<vector<int>> ctc;
int low[N], lvl[N], comp[N], in[N];
bool instk[N];
stack<int> stk;
int idx;



int Not(int a)
{
    return a > m ? a - m : a + m;
}

void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++idx;

    for(auto y : G[x])
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);


    if(lvl[x] == low[x])
    {
        vector<int> aux;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            aux.push_back(a);
            if(a == x)break;
        }
        ctc.push_back(aux);
    }
}


void DfsCtc(int x)
{
    viz[x] = true;

    for(auto i : ctc[x - 1])
    {

        if(i > m)
        {
            tvalue[i] = 1;
            tvalue[i - m] = 2;
        }
        else
        {
            tvalue[i] = 1;
            tvalue[i + m] = 2;
        }
    }

    for(auto y : G1[x])
        if(!viz[y])
            DfsCtc(y);
}

void Scrie(int x)
{
    if(x > m)cout << '~' << x - m;
    else cout << x;
}

int main()
{
    cin >> n >> m;
    G = vector<vector<int>>(2 * m + 9);
    for(int i = 1; i <= n; ++i)
    {
        cin >> sgn >> a;
        if(sgn == '-') a = Not(a);
        cin >> sgn >> b;
        if(sgn == '-') b = Not(b);

        G[Not(a)].push_back(b);
        G[Not(b)].push_back(a);
    }


    for(int i = 1; i <= 2 * m; ++i)
        if(!lvl[i])
            Dfs(i);

    for(int i = 0; i < ctc.size(); ++i)
        for(int j = 0; j < ctc[i].size(); ++j)
            comp[ctc[i][j]] = i + 1;

    bool possible = true;
    for(int i = 1; i <= m; ++i)
        if(comp[i] == comp[Not(i)])
            possible = false;

    if(!possible)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    ///Pana aici e bine

    G1 = vector<vector<int>>(2 * m + 9);
    for(int i = 1; i <= 2 * m; ++i)
        for(auto j : G[i])
            if(comp[i] != comp[j])
                G1[comp[i]].push_back(comp[j]);


    for(int i = ctc.size(); i >= 1; --i)
        if(!viz[i])
            DfsCtc(i);


    for(int i = 1; i <= m; ++i)
        if(tvalue[i] == 2)cout << "+ ";
        else cout << "- ";
    return 0;
}
