#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 10009;

int n, a, b, c, i, ti, lant[N], poz[N], w[N], tree[4 * N], OFFSET, off[N], t[N], head[N], dep[N];
long long  d[N];
char s[101];
vector<vector<PI>> G;
vector<vector<int>> lanturi;
struct muchie
{
    int a, b, c;
}muchii[N];

void Build(int OFFSET, int nod, int st, int dr, int idx)
{
    if(st == dr)
    {
        tree[OFFSET + nod] = lanturi[idx][st];
        return;
    }
    int mij = (st + dr) >> 1;

    Build(OFFSET, nod << 1, st, mij, idx);
    Build(OFFSET, nod << 1 | 1, mij + 1, dr, idx);

    tree[OFFSET + nod] = max(tree[OFFSET + (nod << 1)], tree[OFFSET + (nod << 1 | 1)]);
}

void Dfs(int x, int p)
{
    t[x] = p;
    dep[x] = dep[p] + 1;

    if(G[x].size() == 1 && x != 1)
    {
        w[x] = 1;
        lant[x] = lanturi.size();
        head[lant[x]] = x;
        poz[x] = 0;
        lanturi.push_back(vector<int>(1, d[x] - d[p]));

        return;
    }

    int mx = -3, heavy_son;
    for(auto aux : G[x])
    {
        int y = aux.F, c = aux.S;

        if(y == p)continue;

        d[y] = d[x] + c;
        Dfs(y, x);

        w[x] += w[y];
        if(w[y] > mx)
        {
            mx = w[y];
            heavy_son = y;
        }
    }

    lant[x] = lant[heavy_son];
    head[lant[x]] = x;
    poz[x] = poz[heavy_son] + 1;
    lanturi[lant[x]].push_back(d[x] - d[p]);
}

void Build()
{
    Dfs(1, 0);

    for(int i = 0; i < lanturi.size(); ++i)
    {
        off[i] = OFFSET;
        Build(OFFSET, 1, 0, lanturi[i].size() - 1, i);
        OFFSET += lanturi[i].size() * 4;
    }
}

int Query(int OFFSET, int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
        return tree[OFFSET + nod];
    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(OFFSET, nod << 1, st, mij, a, b);
    else if(a > mij)return Query(OFFSET, nod << 1 | 1, mij + 1, dr, a, b);
    return max(Query(OFFSET, nod << 1, st, mij, a, b), Query(OFFSET, nod << 1 | 1, mij + 1, dr, a, b));
}

int Query(int a, int b)
{
    int ans = 0;
    while(lant[a] != lant[b])
    {
        if(dep[t[head[lant[a]]]] > dep[t[head[lant[b]]]])
        {
            ans = max(ans, Query(off[lant[a]], 1, 0, lanturi[lant[a]].size() - 1, 0, poz[a]));
            a = t[head[lant[a]]];
        }
        else
        {
            ans = max(ans, Query(off[lant[b]], 1, 0, lanturi[lant[b]].size() - 1, 0, poz[b]));
            b = t[head[lant[b]]];
        }
    }

    if(a == b)return ans;
    return max(ans, Query(off[lant[a]], 1, 0, lanturi[lant[a]].size() - 1, min(poz[a], poz[b]), max(poz[a] + 1, poz[b])));
}

void Update(int OFFSET, int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        tree[OFFSET + nod] = val;
        return;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)Update(OFFSET, nod << 1, st, mij, poz, val);
    else Update(OFFSET, nod << 1 | 1, mij + 1, dr, poz, val);

    tree[OFFSET + nod] = max(tree[OFFSET + (nod << 1)], tree[OFFSET + (nod << 1 | 1)]);
}

void solve()
{
    memset(lant, 0, sizeof(lant));
    memset(poz, 0, sizeof(poz));
    memset(w, 0, sizeof(w));
    memset(tree, 0, sizeof(tree));
    memset(off, 0, sizeof(off));
    memset(t, 0, sizeof(t));
    memset(head, 0, sizeof(head));
    memset(dep, 0, sizeof(dep));
    lanturi.clear();
    G.clear();

    cin >> n;
    G = vector<vector<PI>>(n + 1);
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        muchii[i] = {a, b, c};
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    Build();

    while(true)
    {
        cin >> s;

        if(s[0] == 'Q')
        {
            cin >> a >> b;
            cout << Query(a, b) << '\n';
        }
        else if(s[0] == 'C')
        {
            cin >> i >> ti;
            int a = muchii[i].a, b = muchii[i].b;
            if(t[a] == b)swap(a, b);
            Update(off[lant[b]], 1, 0, lanturi[lant[b]].size() - 1, poz[b], ti);
        }
        else if(s[0] == 'D') break;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
