#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

const int N = 3e5 + 9;

int n, m, t[N];
VVI G(N);
VVI v(N);

struct query
{
    int nod, p, ans;
};
query queries[N];


VI path;
void Dfs(int x)
{
    path.pb(x);

    for(auto i : v[x])
    {
        int k = queries[i].p;
        if(k + 1 > path.size())queries[i].ans = 0;
        else queries[i].ans = path[path.size() - (k + 1)];
    }

    for(auto y : G[x])
        Dfs(y);

    path.pop_back();
}

int main()
{
    fin >> n >> m;

    FOR(i, 1, n)
    {
        fin >> t[i];
        if(t[i])G[t[i]].pb(i);
    }

    int nod, p;
    FOR(i, 1, m)
    {
        fin >> queries[i].nod >> queries[i].p;
        queries[i].ans = -1;

        v[queries[i].nod].pb(i);
    }

    FOR(i, 1, n)
        if(!t[i])
            Dfs(i);

    FOR(i, 1, m)fout << queries[i].ans << '\n';
    return 0;
}
