#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;
const string TASK("vacanta2020");
//ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
#define cout fout
auto fin = fopen("vacanta2020.in", "r");
void next();
void get(int&);

const int N = 35009, K = 11;
const ll Inf = 0x3f3f3f3f;

int n, m, k, d[N][K];
vvpi G(N);

void Dijkstra()
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>q;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            d[i][j] = Inf;

    d[1][0] = 0;
    q.push({0, {1, 0}});

    while(!q.empty())
    {
        int dx = q.top().ff, x = q.top().ss.ff, vou = q.top().ss.ss;
        q.pop();

        if(dx > d[x][vou])continue;

        for(auto aux : G[x])
        {
            int y = aux.ff, c = aux.ss;

            if(d[y][vou] > d[x][vou] + c)
                q.push({d[y][vou] = d[x][vou] + c, {y, vou}});

            if(vou < k && d[y][vou + 1] > d[x][vou])
                q.push({d[y][vou + 1] = d[x][vou], {y, vou + 1}});
        }
    }
}

int main()
{
    next();

    get(n), get(m), get(k);

    int u, v, c;
    for(int i = 1; i <= m; ++i)
    {
        get(u), get(v), get(c);
        G[u].pb({v, c});
        G[v].pb({u, c});
    }

    Dijkstra();

    for(int i = 1; i <= n; ++i)
    {
        int ans = Inf;
        for(int j = 0; j <= k; ++j)
            ans = min(ans, d[i][j]);
        cout << ans << ' ';
    }
    return 0;
}




const int Lim = 1e6;
char s[Lim];
int p = Lim - 1;

void next()
{
   if(++ p == Lim)
   {
       p = 0;
       fread(s, 1, Lim, fin);
   }
}

void get(int& x)
{
    while(!isdigit(s[p]))next();

    for(x = 0; isdigit(s[p]); next())
        x = x * 10 + s[p] - '0';
}
