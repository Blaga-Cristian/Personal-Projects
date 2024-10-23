#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define ll long long
#define vl vector<ll>

using namespace std;
const string TASK("minerale");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 409, M = 109, SZ = 1009;

int r, m;
long long dp[M][M];
char s[M], s1[10], s2[10];

//int arr[(1 << 25)];

vi t[2 * SZ], sn[2 * SZ];
vl pos[26];

int main()
{
    cin >> r >> m;

//    FOR(i, 0, (1 << 25) - 1)arr[i] = i;

    FOR(i, 1, r)
    {
        cin >> s1 >> s2;

        if(strlen(s2) == 2)///se descompune in s inst
        {
            t[(s2[0] - 'A') * 26 + s2[1] - 'A'].pb(s1[0] - 'A');
            sn[s1[0] - 'A'].pb((s2[0] - 'A') * 26 + s2[1] - 'A');
        }
        else
            t[SZ + s2[0] - 'a'].pb(s1[0] - 'A');
    }

    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j)
            for(auto x : t[i * 26  + j])
                pos[x].pb((1LL << (i + 26)) | (1LL << j));

    FOR(x, 1, m)
    {
        cin >> (s + 1);

        int n = strlen(s + 1);

        FOR(i, 1, n)
            FOR(j, i, n)
                dp[i][j] = 0;

        FOR(i, 1, n)
            for(auto j : t[SZ + s[i] - 'a'])
                dp[i][i] |= (1 << j);

        for(int len = 2; len <= n; ++len)
            for(int i = 1, j = i + len - 1; j <= n; ++i, ++j)
                for(int p = i; p < j; ++p)
                    for(int k = 0; k < 26; ++k)
                        if(!(dp[i][j] & (1 << k)))
                            for(auto b : pos[k])
                                if(((b & (dp[i][p] << 26)) | (b & dp[p + 1][j])) == b)
                                    dp[i][j] |= (1 << k);

        if(dp[1][n] & (1 << ('S' - 'A')))cout << "1\n";
        else
        {
            bool ok = false;
            FOR(i, 0, 25)
                if(dp[1][n] & (1 << i))
                    ok = true;
            if(ok)cout << "2\n";
            else cout << "0\n";
        }
    }
    return 0;
}
