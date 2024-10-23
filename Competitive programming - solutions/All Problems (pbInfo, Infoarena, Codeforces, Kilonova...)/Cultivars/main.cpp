#include <bits/stdc++.h>
#include <vector>
#include <string>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long
#define pll pair<ll, ll>
#define int long long

using namespace std;
//ifstream fin("cowpatibility.in");
//ofstream fout("cowpatibility.out");
//#define cin fin
//#define cout fout

const int N = 2e5 + 9;

int n, ans[N];
struct cultivar
{
    int l, r, k, ind;
};
cultivar v[N];

struct cmp
{
    bool operator() (cultivar const& a, cultivar const& b)
    {
        return a.k < b.k;
    }
};


signed main()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> v[i].l >> v[i].r >> v[i].k;
        v[i].ind = i;
    }

    priority_queue<cultivar, vector<cultivar>, cmp> q;
    FOR(i, 1, n)q.push(v[i]);

    sort(v + 1, v + n + 1, [](cultivar a, cultivar b){return a.r - a.l > b.r - b.l;});///le numar dupa marime

    multiset<int> mst;
    for(int i = 1; i <= n;)
    {
        int j = i;

        while(!q.empty() && q.top().k > v[i].r - v[i].l)
        {
            auto x = q.top();
            q.pop();

            ans[x.ind] += distance(mst.lower_bound(x.l), mst.upper_bound(x.r - x.k)) - 1;///se numara pe sine
        }

        while(j <= n && v[j].r - v[j].l == v[i].r - v[i].l)
        {
            mst.insert(v[j].l);
            ++ j;
        }
        i = j;
    }

    while(!q.empty())
    {
        auto x = q.top();
        q.pop();

        ans[x.ind] += distance(mst.lower_bound(x.l), mst.upper_bound(x.r - x.k)) - 1;///se numara pe sine
    }

//    FOR(i, 1, n)cout << ans[i] << ' ';
//    cout << '\n';
    ///Pana aici e bine

    sort(v + 1, v + n + 1, [](cultivar a, cultivar b){return a.l < b.l;});

    mst.clear();
    for(int i = 1; i <= n;)
    {
//        cout << "While processing " << v[i].l << ' ' << v[i].r << ' ' << v[i].k << '\n';
//        for(auto i : mst)cout << i << ' ';
//        cout << '\n';

        int j = i;
        while(j <= n && v[j].l == v[i].l)
        {
            ///cate cult se afla intre 0 si l - 1 cu r >= l + k
            ans[v[j].ind] += distance(mst.lower_bound(v[j].l + v[j].k), mst.end());
            ++ j;
        }

        for(int k = i; k < j; ++k)
            mst.insert(v[k].r);
        i = j;
    }

    FOR(i, 1, n)cout << ans[i] << ' ';
    return 0;
}
