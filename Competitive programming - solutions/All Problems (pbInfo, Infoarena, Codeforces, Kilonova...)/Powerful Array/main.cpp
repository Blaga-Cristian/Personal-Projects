#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

using namespace std;
const int N = 2e5 + 9, V = 1e6 + 9;

int n, q, a[N];
int block;

int cnt[V];
ll sum;
void Add(int x)
{
    sum += 1LL * (2 * cnt[a[x]] + 1) * a[x];
    cnt[a[x]] ++;
}
void Del(int x)
{
    sum += 1LL * (- 2 * cnt[a[x]] + 1) * a[x];
    cnt[a[x]] --;
}

struct info
{
    int l, r, ind;
    ll ans;
};
bool cmp1(info x, info y){return (x.l / block == y.l / block) ? x.r < y.r : x.l < y.l;}
bool cmp2(info x, info y){return x.ind < y.ind;}
vector<info> queries;

int main()
{
//    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    block = sqrt(n);

    FOR(i, 1, n)cin >> a[i];

    int l, r;
    FOR(i, 1, q)
    {
        cin >> l >> r;
        queries.pb({l, r, i, -1});
    }

    sort(queries.begin(), queries.end(), cmp1);

    int st = 1, dr = 0;
    for(auto& e : queries)
    {
        while(dr < e.r)Add(++ dr);
        while(st > e.l)Add(-- st);
        while(st < e.l)Del(st ++);
        while(dr > e.r)Del(dr --);

        e.ans = sum;
    }

    sort(queries.begin(), queries.end(), cmp2);

    for(auto e : queries)cout << e.ans << '\n';
    return 0;
}
