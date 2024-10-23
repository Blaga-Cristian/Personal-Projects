#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 1e5 + 9;

int n, m, a, b, L[N], R[2 * N];
vector<vector<int>> G;
bitset<N> viz;

bool DoMatch(int x)
{
    if(viz[x])return false;
    viz[x] = true;

    for(auto y : G[x])
        if(!R[y])
        {
            R[y] = x;
            L[x] = y;
            return true;
        }

    for(auto y : G[x])
        if(DoMatch(R[y]))
        {
            R[y] = x;
            L[x] = y;
            return true;
        }


    return false;
}

void Match()
{
    bool found_path = true;
    while(found_path)
    {
        found_path = false;

        viz.reset();
        for(int i = 1; i <= n; ++i)
            if(!L[i])found_path |= DoMatch(i);
    }
}

void solve()
{
    cin >> n >> m;
    fill(L + 1, L + n + 1, 0);
    fill(R + 1, R + m + 1, 0);
    G = vector<vector<int>>(n + 1);

    for(int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        G[i].push_back(a);
        G[i].push_back(b);
    }

    Match();

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(L[i])ans ++;
    if(ans == n)cout << "DA\n";
    else cout << "NU\n";
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
