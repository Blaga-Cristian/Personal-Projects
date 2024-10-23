#include <bits/stdc++.h>
#include <bits/extc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
using namespace __gnu_pbds;

const int N = 1e5 + 9;

int n, q, s[N], t[N];

struct query
{
    int x, y, z, ind, ans;
};
vector<query> qs;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> omultiset;

omultiset d[4 * N];

void Update(int p, int v, int nod = 1, int st = 1, int dr = n)
{
    d[nod].insert(v);
    if(st == dr)return;
    int m = (st + dr) >> 1;
    if(p <= m)Update(p, v, nod << 1, st, m);
    else Update(p, v, nod << 1 | 1, m + 1, dr);
}

int Query(int l, int r, int v, int nod = 1, int st = 1, int dr = n)///cate is mai mari sau eg cu v
{
    if(l <= st && dr <= r)return d[nod].size() - d[nod].order_of_key(v);
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, v, nod << 1, st, m);
    else if(l > m)return Query(l, r, v, nod << 1 | 1, m + 1, dr);
    return Query(l, r, v, nod << 1, st, m) + Query(l, r, v, nod << 1 | 1, m + 1, dr);
}

vector<int> nor;
int index_of(int x)
{
    return distance(nor.begin(), lower_bound(nor.begin(), nor.end(), x)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    FOR(i, 1, n)cin >> s[i] >> t[i];

    FOR(i, 1, n)nor.pb(s[i]);
    sort(nor.begin(), nor.end());
    nor.erase(unique(nor.begin(), nor.end()), nor.end());

    qs.resize(q);
    FOR(i, 0, q - 1)
    {
        cin >> qs[i].x >> qs[i].y >> qs[i].z;
        qs[i].ind = i;
        qs[i].ans = -1;
    }
    sort(qs.begin(), qs.end(), [](query const& a, query const& b){return a.z > b.z;});

    vector<int> v;
    FOR(i, 1, n)v.pb(i);
    sort(v.begin(), v.end(), [](int a, int b){return s[a] + t[a] > s[b] + t[b];});

    auto it = v.begin();
    for(auto& e : qs)
    {
        while(it != v.end() && s[*it] + t[*it] >= e.z)
        {
            Update(index_of(s[*it]), t[*it]);
            ++ it;
        }

        if(index_of(e.x) == n + 1)e.ans = 0;
        else e.ans = Query(index_of(e.x), n, e.y);
    }

    sort(qs.begin(), qs.end(), [](query const& a, query const& b){return a.ind < b.ind;});

    for(auto e : qs)cout << e.ans << '\n';
    return 0;
}
