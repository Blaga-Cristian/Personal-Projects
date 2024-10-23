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
#define pb push_back
#define ll long long
#define ull unsigned ll

using namespace std;
ifstream fin("costperm.in");
ofstream fout("costperm.out");
const int N = 1e6 + 9;
void next();
void get(int&);

int n, v[N], poz[N];

int aib[N];
void update(int p)
{
    for(; p <= n; p += p & -p)
        aib[p] ++;
}
int query(int p)
{
    int ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}

int main()
{
    get(n);
    FOR(i, 1, n)
    {
        get(v[i]);
        poz[v[i]] = i;
    }

    ull ans = 0;

    FORR(i, n, 1)
    {
        ans += 1ULL * i * query(poz[i]);
        update(poz[i]);
    }

    fout << ans;
    return 0;
}


const int Lim = 1e6 + 9;
int p = Lim - 1;
char s[Lim + 1];

void next()
{
    if(++p == Lim)
    {
        fin.get(s, Lim + 1, EOF);
        p = 0;
    }
}
void get(int& x)
{
    while(s[p] != '-' && !isdigit(s[p]))next();

    int semn = 1;
    if(s[p] == '-')
    {
        semn = -1;
        next();
    }

    for(x = 0; isdigit(s[p]); next())
        x = x * 10 + s[p] - '0';

    x *= semn;
}
