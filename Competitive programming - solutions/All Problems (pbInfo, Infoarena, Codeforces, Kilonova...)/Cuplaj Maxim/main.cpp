#include <bits/stdc++.h>

using namespace std;
const int N = 10009;

int n, m, e, L[N], R[N], a, b;
bitset<N> viz;
vector<vector<int>> G;

bool DoMatch(int x)
{
    if(viz[x])return false;
    viz[x] = true;

    for(auto y : G[x])
        if(!R[y] || DoMatch(R[y]))
        {
            L[x] = y;
            R[y] = x;
            return true;
        }

    return false;
}

int MaxMatching()
{
    int max_matching = 0;
    bool found_match = true;
    while(found_match)
    {
        found_match = false;
        viz.reset();

        for(int i = 1; i <= n; ++i)
            if(!L[i] && DoMatch(i))
            {
                found_match = true;
                max_matching ++;
            }
    }
    return max_matching;
}

int main()
{
    freopen("cuplaj.in", "r", stdin);
    freopen("cuplaj.out", "w", stdout);

    cin >> n >> m >> e;
    G = vector<vector<int>>(n + 1);
    while(e --)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    cout << MaxMatching() << '\n';
    for(int i = 1; i <= n; ++i)
        if(L[i])
            cout << i << ' ' << L[i] << '\n';
    return 0;
}
