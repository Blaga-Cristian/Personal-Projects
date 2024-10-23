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
#define double long double
using namespace std;
const string TASK("network");
ifstream fin(TASK + ".in");
ofstream fout(TASK  + ".out");
#define cin fin
#define cout fout

const int N = 5009;

int n, m;

struct muchie
{
    int y;
    double p0, p1;
};
vector<vector<muchie>> G(N);

bool viz[N];
vi sir;
void Sort_Top(int x = 0)
{
    viz[x] = true;
    for(auto [y, p0, p1] : G[x])
        if(!viz[y])
            Sort_Top(y);
    sir.pb(x);
}

double dp[N][2];

int main()
{
    cin >> n >> m;

    int x, y;
    double p0, p1;
    FOR(i, 1, m)
    {
        cin >> x >> y;
        cin >> p0 >> p1;
        G[x].pb({y, p0, p1});
    }

    Sort_Top();
    reverse(sir.begin(), sir.end());

    cout << fixed << setprecision(7);

    dp[0][0] = 1;
    for(auto x : sir)
        for(auto [y, p0, p1] : G[x])
        {
            dp[y][0] += (dp[x][0] * p0 + dp[x][1] * (1 - p1)) / G[x].size();
            dp[y][1] += (dp[x][1] * p1 + dp[x][0] * (1 - p0)) / G[x].size();
        }

    cout << dp[n - 1][0] << '\n';

    FOR(i, 0, n - 1)dp[i][0] = dp[i][1] = 0;

    dp[0][1] = 1;
    for(auto x : sir)
        for(auto [y, p0, p1] : G[x])
    {
        dp[y][0] += (dp[x][0] * p0 + dp[x][1] * (1 - p1)) / G[x].size();
        dp[y][1] += (dp[x][1] * p1 + dp[x][0] * (1 - p0)) / G[x].size();
    }

    cout << dp[n - 1][1] << '\n';
    return 0;
}
