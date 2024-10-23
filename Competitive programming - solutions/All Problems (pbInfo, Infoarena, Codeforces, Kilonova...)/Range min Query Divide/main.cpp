#include <bits/stdc++.h>

using namespace std;
ifstream fin("rmq.in");
ofstream fout("rmq.out");
#define cin fin
#define cout fout

const int N = 1e5 + 9, Q = 1e6 + 9;

int n, q, a[N], ql[Q], qr[Q], ans[Q], calc[N];

void divide(int l, int r, vector<int>& ids)
{
    if(l == r)
        for(auto i : ids)
            ans[i] = a[l];

    if(l >= r)return;

    int m = (l + r) >> 1;

    vector<int> st, dr, mid;
    for(auto i : ids)
    {
        if(qr[i] < m)st.push_back(i);
        else if(ql[i] > m)dr.push_back(i);
        else mid.push_back(i);
    }

    divide(l, m - 1, st);
    divide(m + 1, r, dr);

    if(mid.empty())return;

    calc[m] = a[m];
    for(int i = m - 1; i >= l; --i)calc[i] = min(a[i], calc[i + 1]);
    for(int i = m + 1; i <= r; ++i)calc[i] = min(a[i], calc[i - 1]);

    for(auto i : mid)
        ans[i] = min(calc[ql[i]], calc[qr[i]]);
}

int main()
{
    cin >> n >> q;
    for(int i =1 ; i <= n; ++i)cin >> a[i];

    vector<int> query_ids;
    for(int i = 1; i <= q; ++i)
    {
        cin >> ql[i] >> qr[i];
        query_ids.push_back(i);
    }

    divide(1, n, query_ids);

    for(int i = 1; i <= q; ++i)cout << ans[i] << '\n';
    return 0;
}
