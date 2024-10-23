#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int N = 3e5 + 9, C = 1e5 + 9, BLOCK = 333;

int n, c, q, a[N];
vi app[C];

pii t[4 * N];

pii merge(pii const& a, pii const& b)
{
    if(a.ff == b.ff)return {a.ff, a.ss + b.ss};
    else if(a.ss > b.ss)return {a.ff, a.ss - b.ss};
    return {b.ff, b.ss - a.ss};
}

void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        t[nod] = {a[st], 1};
        return;
    }
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
    t[nod] = merge(t[nod << 1], t[nod << 1 | 1]);
}

pii Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return t[nod];
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return merge(Query(l, r, nod << 1, st, m), Query(l, r, nod << 1 | 1, m + 1, dr));
}


int main()
{
    cin >> n >> c;

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        app[a[i]].pb(i);
    }

    Build();

    int l, r;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        cin >> l >> r;

        auto ans = Query(l, r);

        if(distance(lower_bound(all(app[ans.ff]), l),
                    upper_bound(all(app[ans.ff]), r)) > (r - l + 1) / 2)
            cout << "yes " << ans.ff << '\n';
        else cout << "no\n";
    }
    return 0;
}
