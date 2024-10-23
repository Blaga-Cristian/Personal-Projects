#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define ull unsigned ll
#define VL vector<ll>
using namespace std;
const bool has_test_cases = true;
const int N = 1009, V = 12, Mod = 998244353, Inf = 0x3f3f3f3f;

int n, m;
char s[V];
VL d;
struct edge{int cst, rem, add;} muchii[N];

int next_state(int nod, edge m)
{
    nod = nod - (nod & m.rem);
    nod = nod | m.add;
    return nod;
}

void Dijkstra(int source)
{
    priority_queue<PI, vector<PI>, greater<PI>> q;
    d = VL((1 << n), Inf);
    d[source] = 0;
    q.push({0, source});

    while(!q.empty())
    {
        int dx = q.top().F, x = q.top().S;
        q.pop();

        if(dx > d[x])continue;

        FOR(i, 1, m)
        {
            int y = next_state(x, muchii[i]), c = muchii[i].cst;

            if(d[y] > d[x] + c)
                q.push({d[y] = d[x] + c, y});
        }
    }

    if(d[0] == Inf)cout << "-1\n";
    else cout << d[0] << '\n';

    d.clear();
}

void solve()
{
    cin >> n >> m;
    cin.get();
    FOR(i, 1, m)muchii[i] = {0, 0, 0};
    cin.get(s, V);
    cin.get();

    int start = 0;
    FOR(i, 0, n - 1)
        start += (s[i] == '1') * (1 << (n - i - 1));

    FOR(i, 1, m)
    {
        cin >> muchii[i].cst;
        cin.get();

        cin.get(s, V);
        cin.get();

        FOR(j, 0, n - 1)
            muchii[i].rem += (s[j] == '1') * (1 << (n - j - 1));

        cin.get(s, V);
        cin.get();

        FOR(j, 0, n - 1)
            muchii[i].add += (s[j] == '1') * (1 << (n - j - 1));
    }


    Dijkstra(start);
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
