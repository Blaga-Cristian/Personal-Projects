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

using namespace std;
const string TASK("minerale");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 409, M = 109, SZ = 1009;

int r, m;
bool dp[M][M][30];
char s[M], s1[10], s2[10];

//int arr[(1 << 25)];

vi t[2 * SZ], sn[2 * SZ];

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

//    for(auto i : t[SZ + 1])cout << i << ' ';

    FOR(x, 1, m)
    {
        cin >> (s + 1);

        int n = strlen(s + 1);

        FOR(i, 1, n)
            FOR(j, i, n)
                FOR(k, 0, 26)
                    dp[i][j][k] = false;

        FOR(i, 1, n)
            for(auto j : t[SZ + s[i] - 'a'])
                dp[i][i][j] = true;

        for(int len = 2; len <= n; ++len)
            for(int i = 1, j = i + len - 1; j <= n; ++i, ++j)
                for(int p = i; p < j; ++p)
                {
                    for(int k = 0; k < 26; ++k)
                        if(!dp[i][j][k])
                            for(auto nr : sn[k])
                                if(dp[i][p][nr / 26] && dp[p + 1][j][nr % 26])
                                    dp[i][j][k] = true;
                }

        if(dp[1][n]['S' - 'A'])cout << "1\n";
        else
        {
            bool ok = false;
            FOR(i, 0, 25)ok |= dp[1][n][i];
            if(ok)cout << "2\n";
            else cout << "0\n";
        }
    }
    return 0;
}
