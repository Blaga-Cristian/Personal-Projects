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
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const bool has_multiple_testcases = false;
const int N = 3e5 + 9, NrPrimes = 30000, Inf = 0x3f3f3f3f;
bool p[N];
VI primes;


int n, a[N], s, t;
VVI G(N + NrPrimes);

void Ciur()
{
    p[0] = p[1] = 1;

    FOR(i, 2, N - 1)
        if(!p[i])
        {
            primes.pb(i);
            for(int j = 2 * i; j < N; j += i)
                p[j] = 1;
        }
}

int d[N + NrPrimes], parent[N + NrPrimes];
void Bfs(int x)
{
    fill(d, d + N + NrPrimes, Inf);
    queue<int> q;
    q.push(x);
    d[x] = 0;

    while(!q.empty())
    {
        x = q.front();
        q.pop();

        if(x == NrPrimes + t)return;

        for(auto y : G[x])
            if(d[y] == Inf)
            {
                d[y] = d[x] + 1;
                parent[y] = x;
                q.push(y);
            }
    }
}

void solve_testcase()
{
    Ciur();
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i];
    cin >> s >> t;

    FOR(i, 1, n)
        FOR(j, 0, NrPrimes - 1)
        {
            if(primes[j] > a[i])break;
            if(a[i] % primes[j] == 0)
            {
                G[NrPrimes + i].pb(j + 1);
                G[j + 1].pb(NrPrimes + i);
            }
        }



    Bfs(NrPrimes + s);

    if(d[NrPrimes + t] == Inf)
    {
        cout << "-1\n";
        return;
    }

    cout << d[NrPrimes + t] / 2 + 1 << '\n';

    VI stk;
    for(int nod = NrPrimes + t; nod != 0; nod = parent[nod])
        if(nod >= NrPrimes)stk.pb(nod - NrPrimes);

    FORR(i, stk.size() - 1, 0)
        cout << stk[i] << ' ';
}


int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_multiple_testcases) cin >> t;
    while(t --)
        solve_testcase();

    return 0;
}
