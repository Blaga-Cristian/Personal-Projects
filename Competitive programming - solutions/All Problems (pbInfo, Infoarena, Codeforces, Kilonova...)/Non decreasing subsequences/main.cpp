#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pb push_back
#define ll long long

using namespace std;
const string TASK("nondec");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 50009, K = 21, Q = 2e5 + 9, Mod = 1e9 + 7;

int n, k, q, a[N], ql[Q], qr[Q], ans[Q];
int dp[N][K], cnt[K][K];

void divide(int l, int r, vector<int>& ids)
{
    if(l == r)
    {
        for(auto i : ids)ans[i] = 1;
        return;
    }

    int m = (l + r) >> 1;
    vector<int> st, dr, mj;
    for(auto i : ids)
    {
        if(qr[i] <= m)st.pb(i);
        else if(ql[i] > m)dr.pb(i);
        else mj.pb(i);
    }

    divide(l, m, st);
    divide(m + 1, r, dr);

    if(mj.empty())return;

    FOR(i, l, r)FOR(j, 1, k)dp[i][j] = 0;
    FOR(i, 1, k)FOR(j, 1, k)cnt[i][j] = 0;

    FORR(i, m, l)
    {
        FOR(j, a[i], k)
            FOR(l, j, k)
                cnt[a[i]][l] = (cnt[a[i]][l] + cnt[j][l]) % Mod;
        cnt[a[i]][a[i]] = (cnt[a[i]][a[i]] + 1) % Mod;

        FOR(j, 1, k)
            FOR(l, j, k)
                dp[i][l] = (dp[i][l] + cnt[j][l]) % Mod;
    }

    FOR(i, 1, k)FOR(j, 1, k)cnt[i][j] = 0;

    FOR(i, m + 1, r)
    {
        FOR(j, 1, a[i])
            FORR(l, a[i], j)
                cnt[j][a[i]] = (cnt[j][a[i]] + cnt[j][l]) % Mod;
        cnt[a[i]][a[i]] = (cnt[a[i]][a[i]] + 1) % Mod;

        FOR(j, 1, k)
            FOR(l, j, k)
                dp[i][j] = (dp[i][j] + cnt[j][l]) % Mod;
    }

//    cout << l << ' ' << m << ' ' << r << '\n';
    for(auto i : mj)
    {
//        cout << "Answering " << i << '\n';
        FOR(j, 1, k)
        {
//            cout << j << "  " << dp[ql[i]][j] << ' ' << dp[qr[i]][j] << '\n';
            ans[i] = ((ans[i] + dp[ql[i]][j]) % Mod + dp[qr[i]][j]) % Mod;
            FOR(l, j, k)
                ans[i] = (ans[i] + 1LL * dp[ql[i]][j] * dp[qr[i]][l] % Mod) % Mod;
        }
    }

//    cout << "\n";
}

int main()
{
    cin >> n >> k;
    FOR(i, 1, n)cin >> a[i];

    cin >> q;

    vector<int> qids;
    FOR(i, 1, q)
    {
        cin >> ql[i] >> qr[i];
        qids.pb(i);
    }

    divide(1, n, qids);

    FOR(i, 1, q)cout << (ans[i] + 1) % Mod << '\n';
    return 0;
}
