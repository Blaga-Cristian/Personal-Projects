#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int N = 3e5 + 9, BLOCK = 750, Inf = 0x3f3f3f3f;

int n, q, a[N];

struct query
{
    int l, r, k, ans, ind;
};
vector<query> qs;

const int MX = 20;
set<pii> mst;
int cnt[N];
void Add(int p)
{
    auto it = mst.find({cnt[a[p]], a[p]});
    if(it != mst.end())mst.erase(it);
    cnt[a[p]] ++;
    mst.insert({cnt[a[p]], a[p]});
    if(mst.size() > MX)mst.erase(mst.begin());
}
void Rem(int p)
{
    auto it = mst.find({cnt[a[p]], a[p]});
    if(it != mst.end())mst.erase(it);
    cnt[a[p]] --;
    mst.insert({cnt[a[p]], a[p]});
    if(mst.size() > MX)mst.erase(mst.begin());
}

int main()
{
    cin >> n >> q;

    for(int i = 1; i <= n; ++i)cin >> a[i];

    int l, r, k;
    qs.resize(q);
    for(int i = 0; i < q; ++i)
    {
        cin >> qs[i].l >> qs[i].r >> qs[i].k;
        qs[i].ans = -1;
        qs[i].ind = i;
    }

    sort(qs.begin(), qs.end(), [](query a, query b)
         {
             return (a.l / BLOCK == b.l / BLOCK) ?
            (((a.l / BLOCK) & 1) ? a.r > b.r : a.r < b.r) :
            a.l < b.l;
         });



    int st = 1, dr = 0;
    for(auto& e : qs)
    {
        while(dr < e.r)Add(++ dr);
        while(st > e.l)Add(-- st);
        while(dr > e.r)Rem(dr --);
        while(st < e.l)Rem(st ++);

        e.ans = Inf;
        for(auto p : mst)
            if(p.ff > (e.r - e.l + 1) / e.k && p.ss < e.ans)
                e.ans = p.ss;
    }

    sort(qs.begin(), qs.end(), [](query a, query b)
         {
             return a.ind < b.ind;
         });

    for(auto e : qs)
        if(e.ans == Inf)cout << "-1\n";
        else cout << e.ans << '\n';
    return 0;
}
