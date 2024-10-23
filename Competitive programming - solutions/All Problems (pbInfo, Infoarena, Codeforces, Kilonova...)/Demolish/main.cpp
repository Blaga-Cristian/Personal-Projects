#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll

using namespace std;
const int N = 500009;

int n, m, f, dx, dy;

struct event
{
    int x, y1, y2, c;

    bool operator < (event const& e)
    {
        return x < e.x;
    }
};
vector<event> events;


struct nod
{
    int mn, nd, lazy;

    bool operator < (nod const& a)
    {
        return mn < a.mn;
    }
};
nod tree[4 * N];

void Push(int nod, int st, int dr)
{
    if(st == dr || tree[nod].lazy == 0)return;

    int val = tree[nod].lazy;

    tree[nod << 1].mn += val;
    tree[nod << 1].lazy += val;
    tree[nod << 1 | 1].mn += val;
    tree[nod << 1 | 1].lazy += val;

    tree[nod].lazy = 0;
}

nod Merge(nod a, nod b)
{
    nod c{0, 0, 0};

    c.mn = min(a.mn, b.mn);
    if(a.mn <= b.mn)c.nd = a.nd;
    else c.nd = b.nd;

    return c;
}

void Build(int nod = 1, int st = 0, int dr = n)
{
    if(st == dr)
    {
        tree[nod].nd = st;
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = Merge(tree[nod << 1], tree[nod << 1 | 1]);
}

void Update(int a, int b, int val, int nod = 1, int st = 0, int dr = n)
{
    if(a <= st && dr <= b)
    {
        tree[nod].mn += val;
        tree[nod].lazy += val;
        return;
    }

    Push(nod, st, dr);

    int mij = (st + dr) >> 1;
    if(a <= mij)Update(a, b, val, nod << 1, st, mij);
    if(b > mij)Update(a, b, val, nod << 1 | 1, mij + 1, dr);

    tree[nod] = Merge(tree[nod << 1], tree[nod << 1 | 1]);
}

nod Query(int a, int b, int nod = 1, int st = 0, int dr = n)
{
    if(a <= st && dr <= b)
        return tree[nod];

    Push(nod, st, dr);

    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(a, b, nod << 1, st, mij);
    else if(a > mij)return Query(a, b, nod << 1 | 1, mij + 1, dr);
    return Merge(Query(a, b, nod << 1, st, mij), Query(a, b, nod << 1 | 1, mij + 1, dr));
}

int main()
{
    cin >> m >> n >> f >> dx >> dy;

    int x1, y1, x2, y2, c;
    FOR(i, 1, f)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> c;

        events.pb({x1 - dx + 1, max(0, y1 - dy + 1), y2, c});
        events.pb({x2 + 1, max(0, y1 - dy + 1), y2, -c});

//        cout << x1 - dx + 1 << ' ' << max(0, y1 - dy + 1) << ' ' << y2 << ' ' << c << '\n';
//        cout << x2 + 1 << ' ' << max(0, y1 - dy + 1) << ' ' << y2 << ' ' << -c << '\n';
    }

    sort(events.begin(), events.end());

    Build();

    int ans = INT_MAX;
    PI point = {INT_MAX, INT_MAX};

    int j = 0;
    for(int i = 0; i < m; ++i)
    {
        while(j < events.size() && events[j].x <= i)
        {
            Update(events[j].y1, events[j].y2, c);
            ++j;
        }

        auto opt = Query(0, n - dy);
        if(ans > opt.mn)
        {

            ans = opt.mn;
            point.F = i;
            point.S = opt.nd;
        }
    }



    cout << ans << '\n';
    cout << point.F << ' ' << point.S << '\n';
    return 0;
}
