#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

#define int long long
using namespace std;
const int N = 1009, M = 109, Al = 26, Mod = 1e9 + 7;

int n, m, mat[M][Al];
string s, aux;

int find_match()
{
    int i = 0;
    if(aux.size() > s.size())i = aux.size() - s.size();

    for(; i < (int)aux.size(); ++i)
    {
        for(int j = i; j < (int)aux.size(); ++j)
        {
            if(s[j - i] != aux[j])break;
            else if(j + 1 == (int)aux.size())return aux.size() - i;
        }
    }

    return 0;
}

struct mint
{
    int v;

    mint(){}

    mint(int x) : v(x % Mod) {}

    mint operator = (mint const& oth){return v = oth.v;}
    mint operator + (mint const& oth){return (v + oth.v) % Mod;}
    mint operator += (mint const& oth){return v = (v + oth.v) % Mod;}

    friend ostream& operator << (ostream& os, mint const& oth)
    {
        return os << oth.v;
    }
};
mint dp[N][M][2];

signed main()
{
    cin >> n;
    cin >> s;
    m = s.size();

    mat[0][s[0] - 'A'] = 1;

    FOR(i, 1, m)
    {
        aux.pb(s[i - 1]);

        FOR(c, 0, Al - 1)
        {
            aux.pb('A' + c);
            mat[i][c] = find_match();
            aux.pop_back();
        }
    }

    dp[0][0][0] = 1;
    FOR(i, 0, n)///merg din spate spre fata
        FOR(j, 0, m)
        {
            FOR(c, 0, Al - 1)
                if(j < m && c == s[j] - 'A')
                {
                    if(j == m - 1)
                    {
                        dp[i + 1][j + 1][1] += dp[i][j][0];
                        dp[i + 1][j + 1][1] += dp[i][j][1];
                    }
                    else
                    {
                        dp[i + 1][j + 1][0] += dp[i][j][0];
                        dp[i + 1][j + 1][1] += dp[i][j][1];
                    }
                }
                else
                {
                    dp[i + 1][mat[j][c]][0] += dp[i][j][0];
                    dp[i + 1][mat[j][c]][1] += dp[i][j][1];
                }
        }

    mint ans = 0;
    FOR(j, 0, m)ans += dp[n][j][1];

    cout << ans << '\n';
    return 0;
}
