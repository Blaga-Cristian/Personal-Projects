#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;
const int N = 1e5 + 9, K = 26, Mod = 998244353;

int n, q, k, pos[K];
int ql[N], qr[N], ans[N], st[N][K], dr[N][K];
int fr[K][K];
string a, s;

void divide(int l, int r, vector<int>& ids)
{
    if(l == r)
    {
        if(k != 1)return;

        for(auto i : ids)ans[i] = (s[l] == a[0]);

        return;
    }

    int m = (l + r) / 2;
    vector<int> stanga, dreapta, mij;
    for(auto i : ids)
    {
        if(qr[i] <= m)stanga.pb(i);
        else if(ql[i] > m)dreapta.pb(i);
        else mij.pb(i);
    }

    divide(l, m, stanga);
    divide(m + 1, r, dreapta);

    if(mij.empty())return;

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            fr[i][j] = 0;

    for(int i = l; i <= r; ++i)
        for(int j = 0; j < k; ++j)
            st[i][j] = dr[i][j] = 0;

    for(int i = m; i >= l; --i)
    {
        int p = pos[s[i] - 'a'];
        fr[p][p] ++;

        for(int j = p + 1; j < k; ++j)
            fr[p][j] = (fr[p][j] + fr[p + 1][j]) % Mod;

        for(int j = 0; j < k; ++j)
            st[i][j] = fr[0][j];
    }

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            fr[i][j] = 0;

    for(int i = m + 1; i <= r; ++i)
    {
        int p = pos[s[i] - 'a'];
        fr[p][p] ++;

        for(int j = 0; j < p; ++j)
            fr[j][p] = (fr[j][p] + fr[j][p - 1]) % Mod;

        for(int j = 0; j < k; ++j)
            dr[i][j] = fr[j][k - 1];
    }


    for(auto i : mij)
    {
        ans[i] = (st[ql[i]][k - 1] + dr[qr[i]][0]) % Mod;

        for(int j = 0; j + 1 < k; ++j)
            ans[i] = (ans[i] + (1LL * st[ql[i]][j] * dr[qr[i]][j + 1]) % Mod) % Mod;
    }
}

int main()
{
    cin >> k >> n;
    cin >> a;
    cin >> s;

    for(int i = 0; i < k; ++i)pos[a[i] - 'a'] = i;

    cin >> q;
    vector<int> query_ids;
    for(int i = 1; i <= q; ++i)
    {
        cin >> ql[i] >> qr[i];
        ql[i] --, qr[i] --;
        query_ids.pb(i);
    }

    divide(0, n - 1, query_ids);

    for(int i = 1; i <= q; ++i)cout << ans[i] << '\n';
    return 0;
}
