#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define pb push_back

using namespace std;

ifstream fin("connectthetree.in");
ofstream fout("connectthetree.out");

const int N = 250009, LG = 20;


int n, m;
int t[N][LG], dep[N], first[N], last[N], idx;
bool is[N];
vvi G(N);

void Dfs(int x = 1, int p = 0)
{
    t[x][0] = p;
    dep[x] = dep[p] + 1;
    for(int i = 1; i < LG; ++i)t[x][i] = t[t[x][i - 1]][i - 1];

    first[x] = ++idx;

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    last[x] = ++idx;
}

int aib[2 * N];
void Update(int p, int val)
{
    for(; p <= 2 * n; p += p & -p)
        aib[p] += val;
}
int Query(int p)
{
    int ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}
int Query(int l, int r)
{
    return Query(r) - Query(l - 1);
}

int get_lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);

    for(int i = LG - 1; i >= 0; --i)
        if(dep[x] - (1 << i) >= dep[y])
            x = t[x][i];

    if(x == y)return x;

    for(int i = LG - 1; i >= 0; --i)
        if(t[x][i] != t[y][i])
        {
            x = t[x][i];
            y = t[y][i];
        }

    return t[x][0];
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; ++i)is[i] = true;

    int a, b;
    for(int i = 1; i < n; ++i)
    {
        fin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    Dfs(1, 0);

    int op, x, y;
    int total = 0;
    for(int i = 1; i <= m; ++i)
    {
        fin >> op >> x >> y;

        if(op == 1)
        {
            if(dep[x] < dep[y])swap(x, y);

            if(is[x])
            {
                Update(first[x], 1);
                Update(last[x], -1);
                is[x] = false;
            }
            else
            {
                Update(first[x], -1);
                Update(last[x], 1);
                is[x] = true;
            }
        }
        else
        {
            x = (x + total) % n + 1, y = (y + total) % n + 1;

            int ans = Query(1, first[x]) + Query(1, first[y]) - 2 * Query(1, first[get_lca(x, y)]);
            total += (ans == 0);
            fout << (ans == 0) << '\n';
        }
    }

    return 0;
}

//const int Lim = 1e6;
//char s[Lim + 1];
//int p = Lim - 1;
//void next()
//{
//    if(++p == Lim)
//    {
//        fread(s, 1, Lim, fin);
//        p = 0;
//    }
//}
//void get(int& x)
//{
//    while(!isdigit(s[p]))next();
//    for(x = 0; isdigit(s[p]); next())
//        x = x * 10 + s[p] - '0';
//}
