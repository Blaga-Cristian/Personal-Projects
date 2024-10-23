#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;
const int N = 2e5 + 9;

int n, m, q, v[N], sz, pos[N];
char s[N];

int aib[N];
void Update(int p, int v)
{
    if(p == 0)return;
    for(; p <= n; p += p & -p)
        aib[p] += v;
}
int Query(int p)
{
    int ret = 0;
    for(; p > 0; p -= p & -p)
        ret += aib[p];
    return ret;
}
int Query(int l, int r)
{
    return Query(r) - Query(l - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    cin >> (s + 1);

    set<int> st;
    for(int i = 1; i <= n; ++i)st.insert(i);

    int l, r;
    for(int i = 1; i <= m; ++i)
    {
        cin >> l >> r;
        for(auto it = st.lower_bound(l); it != st.end() && *it <= r; ++it)
            v[++ sz] = *it;
        st.erase(st.lower_bound(l), st.upper_bound(r));
    }
//    for(auto i : st)v[++ sz] = i;///sunt cateva care raman nefolosite

    for(int i = 1; i <= sz; ++i)pos[v[i]] = i;

    for(int i = 1; i <= sz; ++i)
        if(s[v[i]] == '1')
            Update(i, 1);

    int nr1 = 0;
    for(int i = 1; i <= n; ++i)nr1 += (s[i] == '1');

    int p;
    for(int i = 1; i <= q; ++i)
    {
        cin >> p;
        if(s[p] == '1')
        {
            s[p] = '0';
            nr1 --;
            Update(pos[p], -1);
        }
        else
        {
            s[p] = '1';
            nr1 ++;
            Update(pos[p], 1);
        }

        if(nr1 > sz)cout << sz - Query(sz) << '\n';
        else cout << nr1 - Query(nr1) << '\n';
    }

    return 0;
}
