///O(n * sqrt(n))


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

//#define int long long
using namespace std;
const int N = 1e5 + 9, BUCKET = 400;

int n, q, a[N], lb[N], rb[N];
ll ansPrev[N], ansThere[N], ans[N];

struct query
{
    int l, r, ind;
    ll ans;
};
vector<query> qs, iv[N];

int v[N], block[N / BUCKET + 1];
void Update(int p, int x)
{
    int i = p;

    for(; i < N && i % BUCKET; ++i)
        v[i] += x;

    for(int nr = i / BUCKET; i < N; i += BUCKET, ++nr)
        block[nr] += x;
}
int Query(int p)
{
    return v[p] + block[p / BUCKET];
}

///el mai mari
int DelF(int x){return Query(N - 1) - Query(x);}
///el mai mici
int DelB(int x){return Query(x - 1);}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    FOR(i, 1, n)cin >> a[i];

    vi norm;
    FOR(i, 1, n)norm.pb(a[i]);
    sort(norm.begin(), norm.end());
    norm.erase(unique(norm.begin(), norm.end()), norm.end());
    FOR(i, 1, n)a[i] = distance(norm.begin(),
                                lower_bound(norm.begin(), norm.end(), a[i])) + 1;

    FOR(i, 1, q)
    {
        cin >> lb[i] >> rb[i];
        ++lb[i];
        qs.pb({lb[i], rb[i], i, -1});
    }

    sort(qs.begin(), qs.end(), [&](query const& a, query const& b)
         {
             return (a.l / BUCKET == b.l / BUCKET) ? a.r < b.r : a.l < b.l;
         });


    int st = 1, dr = 0;
    for(auto& e : qs)
    {
        if(dr < e.r)
        {
            iv[st - 1].pb({dr + 1, e.r, e.ind, -1});///Front
            dr = e.r;
        }

        if(e.l < st)
        {
            iv[dr].pb({e.l, st - 1, -e.ind, 1});///Back
            iv[N - 1].pb({e.l, st - 1, e.ind, -1});
            st = e.l;
        }

        if(e.r < dr)
        {
            iv[st - 1].pb({e.r + 1, dr, e.ind, 1});///Front
            dr = e.r;
        }

        if(st < e.l)
        {
            iv[dr].pb({st, e.l - 1, -e.ind, -1});///Back
            iv[N - 1].pb({st, e.l - 1, e.ind, 1});
            st = e.l;
        }
    }

    FOR(i, 1, n)
    {
        ansPrev[i] = ansPrev[i - 1] + DelF(a[i]);

        Update(a[i], 1);

        for(auto [l, r, ind, sgn] : iv[i])
        {
            ll g = 0;
            for(int j = l; j <= r; ++j)
                if(ind < 0)g += DelB(a[j]);
                else g += DelF(a[j]);
            ans[abs(ind)] += g * sgn;
        }

        ansThere[i] = ansThere[i - 1] + DelB(a[i]);
    }

    for(auto [l, r, ind, sgn] : iv[N - 1])
        ans[ind] += sgn * (ansThere[r] - ansThere[l - 1]);

    ll cur_ans = 0;
    for(auto& e : qs)
    {
        cur_ans += ans[e.ind];
        e.ans = cur_ans + ansPrev[e.r];
    }

    sort(qs.begin(), qs.end(), [](query const& a, query const& b)
    {
        return a.ind < b.ind;
    });

    for(auto e : qs)cout << e.ans << '\n';
    return 0;
}
