#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back

using namespace std;
ifstream fin("2sat.in");
ofstream fout("2sat.out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;

int n, m;
vvi G(2 * N);

int nu(int x)
{
    return x > n ? x - n : x + n;
}

int low[2 * N], lvl[2 * N], idx, cmp[2 * N], in[2 * N];
stack<int> stk;
bool instk[2 * N];
vvi ctc;
vi c;

void Dfs(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);
    instk[x] = true;

    for(auto y : G[x])
    {
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);
    }

    if(low[x] == lvl[x])
    {
        c.clear();
        while(!stk.empty())
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;

            cmp[a] = ctc.size() + 1;
            c.pb(a);

            if(a == x)break;
        }
        ctc.pb(c);
    }
}

int value[2 * N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= 2 * n; ++i)
        value[i] = -1;

    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y;

        if(x < 0)x = n - x;
        if(y < 0)y = n - y;

        G[nu(x)].pb(y);
        G[nu(y)].pb(x);
    }

    for(int i = 1; i <= 2 * n; ++i)
        if(!lvl[i])
            Dfs(i);


    bool solvable = true;
    for(int i = 1; i <= n; ++i)
        if(cmp[i] == cmp[nu(i)])
            solvable = false;

    if(!solvable)
    {
        cout << "-1\n";
        return 0;
    }


    for(auto i : ctc)
        for(auto j : i)
            for(auto k : G[j])
                if(cmp[j] != cmp[k])
                    in[cmp[k]] ++;


    queue<int> q;
    for(int i = 1; i <= ctc.size(); ++i)
        if(!in[i])
            q.push(i);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto i : ctc[x - 1])
        {
            int x = (i > n) ? i - n : i;
            if(value[x] == -1)
                value[x] = (i <= n) ? 0 : 1;
        }

        for(auto i : ctc[x - 1])
            for(auto j : G[i])
                if(cmp[i] != cmp[j])
                    if(--in[cmp[j]] == 0)
                        q.push(cmp[j]);
    }

    for(int i = 1; i <= n; ++i)cout << value[i] << ' ';
    cout << '\n';
    return 0;
}
