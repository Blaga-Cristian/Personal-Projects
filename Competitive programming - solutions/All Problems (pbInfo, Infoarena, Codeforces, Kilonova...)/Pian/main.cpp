#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
ifstream fin("pian.in");
ofstream fout("pian.out");
const int N = 1e5 + 9;

int c, n, t[N], g, ST[N][20];
VI moves;
PI seg;

int gcd(int a, int b)
{
    int aux;
    while(b)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

void Bfs(int x)
{
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        x = q.front();
        q.pop();

        if(x >= 2 && t[x - 1] != g)
        {
            t[x - 1] = g;
            q.push(x - 1);
            moves.pb(x - 1);
        }
        if(x <= n - 1 && t[x + 1] != g)
        {
            t[x + 1] = g;
            q.push(x + 1);
            moves.pb(x);
        }
    }
}

void Precalc()
{
    FOR(i, 1, n)
        ST[i][0] = t[i];

    for(int k = 1; (1 << k) <= n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
            ST[i][k] = gcd(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
}
int query(int st, int dr)
{
    int k = log2(dr - st + 1);
    return gcd(ST[st][k], ST[dr - (1 << k) + 1][k]);
}

int get_len()
{
    int len = INT_MAX;
    for(int i = 1, j = 2; i <= n; ++i)
    {
        if(i == j) ++j;

        while(j <= n && query(i, j) != g) ++j;

        if(j <= n && query(i, j) == g && j - i + 1 < len)
        {
            len = j - i + 1;
            seg = {i, j};
        }
    }

    return len;
}

int main()
{
    fin >> c;

    fin >> n;

    FOR(i, 1, n)fin >> t[i];

    g = t[1];
        FOR(i, 2, n)
            g = gcd(g, t[i]);

    if(c == 1)
    {
        fout << 1LL * n * g;
        return 0;
    }

    Precalc();

    int len = get_len();

    if(len == 2)
        FOR(i, 1, n - 1)
        {
            if(gcd(t[i], t[i + 1]) == g && t[i] != g && t[i + 1] != g)
            {
                t[i] = t[i + 1] = g;
                moves.pb(i);
            }
        }
    else
        FOR(i, seg.F, seg.S - 1)
        {
            t[i] = t[i + 1] = gcd(t[i], t[i + 1]);
            moves.pb(i);
        }


    FOR(i, 1, n)
        if(t[i] == g)
            Bfs(i);

    fout << moves.size() << '\n';
    for(auto i : moves)fout << i << ' ';
    return 0;
}
