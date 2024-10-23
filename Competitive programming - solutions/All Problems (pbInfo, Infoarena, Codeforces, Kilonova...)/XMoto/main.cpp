#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define all(v) (v).begin(), (v).end()
#define pdd pair<double, double>
#define vd vector<double>
#define vpd vector<pdd>
#define double long double
using namespace std;
const string TASK("xmoto");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 50009, V = 10000;

double n, L, a[N], b[N], k[N], q[N];
int v[N];
vvi G(V + 9);
vector<double> ans;

int main()
{
    cin >> n >> L;


    FOR(i, 1, n)cin >> a[i] >> b[i] >> k[i] >> q[i] >> v[i];

    FOR(i, 1, n)G[v[i] + 1].pb(i);

    double sumcoef = 0, cnst = 0;
    FOR(i, 1, n)
    {
        sumcoef += a[i];
        cnst += k[i];
    }

    map<int, vi> mp;
    FOR(i, 1, n)mp[v[i]].pb(i);

//    for(auto i : mp)
//    {
//        for(auto j : i.ss)cout << j << ' ';
//        cout << '\n';
//    }

    auto l = mp.begin(), r = next(l);

    ///vit e intre 0 si l
    if(sumcoef != 0)
    {
        double cand = (L - cnst) / sumcoef;
        if(cand >= 0 && cand <= (*l).ff)ans.pb(cand);
    }
    else if(cnst == L)ans.pb((*l).ff);

    while(r != mp.end())
    {
        for(auto i : (*l).ss)
        {
            sumcoef += b[i] - a[i];
            cnst += q[i] - k[i];
        }

        if(sumcoef != 0)
        {
            double cand = (L - cnst) / sumcoef;
            if(cand >= (*l).ff && cand <= (*r).ff)ans.pb(cand);
        }
        else if(cnst == L)ans.pb((*r).ff);

        l ++;
        r ++;
    }

    for(auto i : (*l).ss)
    {
        sumcoef += b[i] - a[i];
        cnst += q[i] - k[i];
    }

    ///vit e intre l si 10000
    if(sumcoef != 0)
    {
        double cand = (L - cnst) / sumcoef;
        if(cand >= (*l).ff && cand <= 10000)ans.pb(cand);
    }
    else if(cnst == L)ans.pb((*l).ff);

    cout << ans.size() << '\n';
    cout << fixed << setprecision(6);
    for(auto i : ans)cout << i << ' ';
    return 0;
}
