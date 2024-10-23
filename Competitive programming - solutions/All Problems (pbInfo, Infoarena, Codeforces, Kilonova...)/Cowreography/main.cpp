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

const int N = 1e6 + 9;

int n, k, ans;
//int l[N], r[N];
char s[N], f[N];
bool useds[N], usedf[N];
multiset<int> mss, msf;
map<pii, bool> seen;

int get_d(int a, int b)
{
    return (abs(a - b) + k - 1) / k;
}

signed main()
{
    cin >> n >> k;
    cin >> (s + 1) >> (f + 1);

//    l[1] = r[n] = -1;
//
//    int nxtl = -1;
//    FOR(i, 1, n)
//    {
//        if(i > 1)l[i] = nxtl;
//        if(f[i] == '1')nxtl = i;
//    }
//
//    int nxtr = -1;
//    FORR(i, n, 1)
//    {
//        if(i < n)r[i] = nxtr;
//        if(f[i] == '1')nxtr = i;
//    }

    FOR(i, 1, n)
    {
        if(s[i] == '1' && f[i] != '1')mss.insert(i);
        if(f[i] == '1' && s[i] != '1')msf.insert(i);
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
    for(auto i : mss)
    {
        auto l = msf.lower_bound(i), r = msf.upper_bound(i);
        if(l != msf.begin())
        {
            --l;
            q.push({get_d(i, *l), {i, *l}});
            seen[{i, *l}] = true;

//            cout << i << ' ' << *l << '\n';
        }
        if(r != msf.end())
        {
            q.push({get_d(i, *r), {i, *r}});
            seen[{i, *r}] = true;

//            cout << i << ' ' << *r << '\n';
        }
    }


    while(!q.empty())
    {
        int dx = q.top().ff, xs = q.top().ss.ff, xf = q.top().ss.ss;
        q.pop();

        if(useds[xs] || usedf[xf])continue;

//        cout << dx << ' ' << xs << ' ' << xf << '\n';

        ans += dx;
        useds[xs] = usedf[xf] = true;
        mss.erase(mss.find(xs));
        msf.erase(msf.find(xf));

        auto l = msf.lower_bound(xf), r = msf.upper_bound(xf);
        auto prv = mss.lower_bound(xs), nxt = mss.upper_bound(xs);

        if(prv != mss.begin())
        {
            --prv;
            if(l != msf.begin())
            {
                --l;
                if(!seen[{*prv, *l}])
                {
                    q.push({get_d(*prv, *l), {*prv, *l}});
                    seen[{*prv, *l}] = true;
                }
                ++l;
            }

            if(r != msf.end() && !seen[{*prv, *r}])
            {
                q.push({get_d(*prv, *r), {*prv, *r}});
                seen[{*prv, *r}] = true;
            }
        }

        if(nxt != mss.end())
        {
            if(l != msf.begin())
            {
                --l;
                if(!seen[{*nxt, *l}])
                {
                    q.push({get_d(*nxt, *l), {*nxt, *l}});
                    seen[{*nxt, *l}] = true;
                }
            }

            if(r != msf.end() && !seen[{*nxt, *r}])
                {
                    q.push({get_d(*nxt, *r), {*nxt, *r}});
                    seen[{*nxt, *r}] = true;
                }
        }
    }

    cout << ans << '\n';
    return 0;
}
