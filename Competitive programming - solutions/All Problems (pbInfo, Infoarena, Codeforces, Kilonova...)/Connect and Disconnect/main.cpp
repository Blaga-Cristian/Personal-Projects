#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 3 * 1e5 + 9;

int n, m, x, y;
char ch;

int t[N], w[N], cc;
stack<PI> events;
inline int Find(int x)
{
    return (t[x] == 0) ? x : Find(t[x]);
}
inline void Unite(int x, int y)
{
    int rx = Find(x), ry = Find(y);
    if(rx == ry)return;
    if(w[rx] < w[ry])swap(rx, ry);

    t[ry] = rx;
    w[rx] += w[ry];
    cc --;
    events.push({ry, rx});
}
inline void Rollback()
{
    int ry = events.top().F, rx = events.top().S;
    t[ry] = 0;
    w[rx] -= w[ry];
    cc ++;
    events.pop();
}

struct edge
{
    int x, y, l, r;

    edge(int x, int y, int l, int r) : x(x), y(y), l(l), r(r)
    {}

    bool operator < (edge const& a) const
    {
        return (x == a.x) ? y < a.y : x < a.x;
    }
};

vector<edge> edges;
set<edge> srch;
bool ask[N];
int ans[N];

void solve(int l, int r, vector<int>* elist)
{
    int mij = (l + r) >> 1, sz = events.size();
    if(l != r)vector<int> *lelist = new vector<int>(), *relist = new vector<int>();

    for(auto ind : *elist)
    {
        auto e = edges[ind];
        if(e.l <= l && e.r >= r)Unite(e.x, e.y);
        else if(l != r)
        {
            if(e.l <= mij && e.r >= l)lelist->push_back(ind);
            if(e.r >= mij + 1 && e.l <= r)relist->push_back(ind);
        }
    }

    if(l != r)
    {
        solve(l, mij, lelist);
        delete lelist;
        solve(mij + 1, r, relist);
        delete elist;
    }
    else ans[l] = cc;

    while(events.size() != sz)Rollback();
}

int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> ch;
        if(ch == '?')ask[i] = true;
        else if(ch == '+')
        {
            cin >> x >> y;
            srch.insert(edge(x, y, i, 0));
        }
        else
        {
            cin >> x >> y;
            auto it = srch.lower_bound(edge(x, y, 0, 0));
            if(it == srch.end() || it->x != x || it->y != y)it = srch.lower_bound(edge(y, x, 0, 0));

            edges.push_back(edge(it->x, it->y, it->l, i));
            srch.erase(it);
        }
    }
    for(auto it : srch)
        edges.push_back(edge(it.x, it.y, it.l, m));

    vector<int> *elist = new vector<int>();
    for(int i = 0; i < edges.size(); ++i)elist->push_back(i);
    memset(w, 1, sizeof(w));
    cc = n;
    //solve(1, m, elist);

    for(int i = 1; i <= m; ++i)
        if(ask[i])cout << ans[i] << '\n';
    return 0;
}
