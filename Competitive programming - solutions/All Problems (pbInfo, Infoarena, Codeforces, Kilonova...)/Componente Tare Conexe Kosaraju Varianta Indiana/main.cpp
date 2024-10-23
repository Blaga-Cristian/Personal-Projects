#include <bits/stdc++.h>

using namespace std;
const int N = 100009;

int n, m, a, b, cnt;
int which[N];
bool viz[N];
vector<vector<int>> G, Gi;
vector<int> discovered;

void Dfs1(int x)
{
    viz[x] = true;
    for(auto i : G[x])
        if(!viz[i])
            Dfs1(i);
    discovered.push_back(x);
}
void Dfs2(int x, int cmp)
{
    which[x] = cmp;
    for(auto i : Gi[x])
        if(!which[i])
            Dfs2(i, cmp);
}

int main()
{
    freopen("ctc.in", "r", stdin);
    freopen("ctc.out", "w", stdout);

    cin >> n >> m;
    Gi = G = vector<vector<int>>(n + 1);
    while(m --)
    {
        cin >> a >> b;
        G[a].push_back(b);
        Gi[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            Dfs1(i);

    for(; !discovered.empty(); discovered.pop_back())
        if(!which[discovered.back()])
            Dfs2(discovered.back(), ++cnt);

    vector<vector<int>> ctc(cnt + 1);
    for(int i = 1; i <= n; ++i)
        ctc[which[i]].push_back(i);

    cout << cnt << '\n';
    for(int i = 1; i <= cnt; ++i)
    {
        for(auto j : ctc[i])
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
