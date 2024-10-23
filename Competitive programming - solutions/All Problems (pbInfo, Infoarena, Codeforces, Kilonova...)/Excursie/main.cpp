#include <bits/stdc++.h>

using namespace std;
ifstream cin("excursie.in");
ofstream cout("excursie.out");


const int N = 2e5 + 9, LG = 19;

int n, q, l, r;
char s[N];

struct info
{
    int cost, cntL, cntR;

    info operator + (info const& b)
    {
        info a;

        a.cost = min(cost + b.cntR, min(b.cost + cntL, cntL + b.cntR));
        a.cntL = cntL + b.cntL;
        a.cntR = cntR + b.cntR;

        return a;
    }
}ST[N][LG];

void Precalc()
{
    for(int i = 1; i <= n; ++i)
        ST[i][0] = {0, s[i] == 'L', s[i] == 'R'};

    for(int k = 1; 1 << k <= n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
            ST[i][k] = ST[i][k - 1] + ST[i + (1 << (k - 1))][k - 1];
}
int query(int l, int r)
{
    info ans = ST[l][0];

    for(int i = LG - 1; i >= 0; --i)
        if(l + (1 << i) <= r)
        {
            ans = ans + ST[l + 1][i];
            l += (1 << i);
        }

    return ans.cost;
}

int main()
{
    //freopen("excursie.in", "r", stdin);
    //freopen("excursie.out", "w", stdout);

    cin >> n;
    cin.get();
    cin.get(s + 1, N);

    Precalc();

    cin >> q;
    while(q --)
    {
        cin >> l >> r;
        if(l > r)swap(l, r);

        cout << query(l, r) << '\n';
    }
    return 0;
}
