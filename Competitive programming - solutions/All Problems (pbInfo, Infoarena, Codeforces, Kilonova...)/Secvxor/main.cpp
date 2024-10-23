#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define PI pair<int, int>
#define F first
#define S second
#define ll long long

using namespace std;
ifstream fin("secvxor.in");
ofstream fout("secvxor.out");

const int N = 1e5 + 9, V = 1e6 + 9;

ll n, v[N], ds[N], dd[N];
ll cnt[V];


ll c[V]; /// c[x] = cel mai mare factor prin din descompunerea lui x
void Ciur()
{
    c[1] = 1;
    for(int i = 2; i < V; ++i)
        if(!c[i])
            for(int j = i; j < V; j += i)
                c[j] = i;
}

ll get_divs(int x, int nr = 1, int nr_fact = 0)
{
    if(x == 1)
    {
        if(nr == 1)return 0;
        if(nr_fact % 2 == 1)return cnt[nr];
        return - cnt[nr];
    }

    int div = c[x];
    for(; x % div == 0; x /= div);

    return get_divs(x, nr, nr_fact) + get_divs(x, nr * div, nr_fact + 1);
}

void mark(int x, int nr = 1)
{
    if(x == 1)
    {
        cnt[nr] ++;
        return;
    }

    int div = c[x];
    for(; x % div == 0; x /= div);

    mark(x, nr);
    mark(x, nr * div);
}

int main()
{
    Ciur();
    fin >> n;

    FOR(i, 1, n)fin >> v[i];

    FOR(i, 1, n)
    {
        ds[i] = ds[i - 1] + get_divs(v[i]);
        mark(v[i]);
    }

    FOR(i, 1, V - 1)cnt[i] = 0;
    FORR(i, n, 1)
    {
        dd[i] += dd[i + 1] + get_divs(v[i]);
        mark(v[i]);
    }


    ll ans = 0;
    FOR(i, 1, n)
        if((ds[n] - ds[i - 1] - dd[i + 1]) % 2 == 1)
            ans ^= v[i];

    fout << ans;
    return 0;
}
