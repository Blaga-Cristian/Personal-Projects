#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define int long long
using namespace std;
const int N = 1e6 + 9;

int n, q, lazy[N];
int l, r, c, x, i;

struct info
{
    int l, r, c;

    bool operator < (info const& oth) const noexcept
    {
        return (l == oth.l) ? ((r == oth.r) ? (c < oth.c) : (r < oth.r)) : (l < oth.l);
    }
};
set<info> st;

int aib[N];
void Update(int p, int v)
{
    for(; p <= n; p += p & -p)
        aib[p] += v;
}
int Query(int p)
{
    int ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    st.insert({1, n, 1});

    string s;
    FOR(i, 1, q)
    {
        cin >> s;

        if(s[0] == 'C')
        {
            cin >> l >> r >> c;

            auto it = st.lower_bound({l + 1, 0, 0});
            it --;
            for(; it != st.end() && (*it).l <= r; ++ it)
            {
                if((*it).l < l)
                {
                    Update(l, lazy[(*it).c] - lazy[c]);
                    Update(min((*it).r, r) + 1, lazy[c] - lazy[(*it).c]);
                }
                else if((*it).r > r)
                {
                    Update(max((*it).l, l), lazy[(*it).c] - lazy[c]);
                    Update(r + 1, lazy[c] - lazy[(*it).c]);
                }
                else
                {
                    Update((*it).l, lazy[(*it).c] - lazy[c]);
                    Update((*it).r + 1, lazy[c] - lazy[(*it).c]);
                }

//                cout << "Iterating " << (*it).l << ' ' << (*it).r << ' ' << (*it).c << '\n';
            }
//            cout << '\n';

            it = st.lower_bound({l + 1, 0, 0});
            it --;
            vector<info> toerase, toinsert;
            for(; it != st.end() && (*it).l <= r; ++ it)
            {
                if((*it).l < l)toinsert.pb({(*it).l, l - 1, (*it).c});
                if((*it).r > r)toinsert.pb({r + 1, (*it).r, (*it).c});
                toerase.pb(*it);
            }

            for(auto e : toerase)st.erase(st.lower_bound(e));
            for(auto e : toinsert)st.insert(e);
            st.insert({l, r, c});
        }
        else if(s[0] == 'A')
        {
            cin >> c >> x;
            lazy[c] += x;
        }
        else if(s[0] == 'Q')
        {
            cin >> x;
            c = (*(--st.lower_bound({x + 1, 0, 0}))).c;
            cout << Query(x) + lazy[c] << '\n';
        }

//        FOR(i, 1, n)cout << Query(i) << ' ';
//        cout << '\n';

//        cout << '\n';
//        for(auto i : st)cout << i.l << ' ' << i.r << ' ' << i.c << '\n'; ///E BINE!!
    }
    return 0;
}
