#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 9;

void next();
void get(int&);

int n, a[N];

void solve()
{
    get(n);
    for(int i = 1; i <= n; ++i)
        get(a[i]);


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("3secv.in", "r", stdin);
    freopen("3secv.out", "w", stdout);

    int t;
    get(t);
    while(t --)
        solve();
    return 0;
}


const int Lim = 1e6 + 9;
char s[Lim];
int p = Lim - 1;

void next()
{
    if(++p == Lim)
    {
        p = 0;
        fread(s, 1, Lim, stdin);
    }
}

void get(int& x)
{
    while(s[p] != '-' && !isdigit(s[p]))next();

    int sign = 1;
    if(s[p] == '-')sign = -1, next();

    for(x = 0; isdigit(s[p]); next())
        x = x * 10 + s[p] - '0';

    x *= sign;
}
