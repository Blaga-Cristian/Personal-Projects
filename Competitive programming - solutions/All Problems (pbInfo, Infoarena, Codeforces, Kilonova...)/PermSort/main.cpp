#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, n) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll

using namespace std;
ifstream fin("permsort.in");
ofstream fout("permsort.out");
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
int query(int a, int b)
{
    if(a > b)return 0;
    return query(b) - query(a - 1);
}

int main()
{
    fin >> n;
    FOR(i, 1, n)
    {
        fin >> v[i];
        poz[v[i]] = i;
    }

    ull ans = 0;
    ans += poz[1];
    update(poz[1]);

    FOR(i, 2, n)
    {
        if(poz[i] > poz[i - 1])
            ans += poz[i] - poz[i - 1] - query(poz[i - 1], poz[i]) + 1;
        else
            ans += n - poz[i - 1] - query(poz[i - 1], n) + 1 + poz[i] - query(1, poz[i]);

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
