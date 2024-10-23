#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define pb push_back
#define pll pair<ll, ll>
#define vpl vector<pll>
using namespace std;
const int N = 1e5 + 9, V = 1e6 + 1, M = 21, Mod = 1e9 + 7;

ll n, a[N], sum;

vi primes;
bool p[V];
void Precalc()
{
    p[0] = p[1] = true;
    for(int i = 2; i < V; ++i)
        if(!p[i]){
            primes.pb(i);
            for(int j = 2 * i; j < V; j += i)
                p[j] = true;
        }
}
vpl fact;

map<ll, int> ans;
void Back(int p, ll d, int sp)
{
    if(p == fact.size())
    {
        if(d != sum)ans[d] += ans[d * fact[sp].ff];
        return;
    }

    for(int i = 1; i <= fact[p].ss; ++i)d *= fact[p].ff;
    for(int i = 1; i <= fact[p].ss; ++i)
    {
        Back(p + 1, d, sp);
        d /= fact[p].ff;
    }
    Back(p + 1, d, sp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Precalc();

    cin >> n;

    sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }


    ll nr = sum;
    for(int i = 0; i < primes.size() && nr != 1; ++i)
    {
        ll exp = 0;
        while(nr % primes[i] == 0)
        {
            nr /= primes[i];
            exp ++;
        }

        if(exp)fact.pb({primes[i], exp});
    }

    ///nr could be prime, or prod of two primes

    ll cur = 0;
    for(int i = 0; i < n; ++i)
    {
        cur += a[i];

        if(nr != 1 && cur != 1 && cur != sum && sum % cur == 0)///found a divisor
        {
            for(auto [e, _] : fact)
                while(cur % e == 0)
                    cur /= e;

            if(cur > V)
            {
                nr /= cur;

                if(nr == 1)fact.pb({cur, 1});
                else if(nr == cur)fact.pb({nr, 2});
                else if(nr < cur)
                {
                    fact.pb({nr, 1});
                    fact.pb({cur, 1});
                }
                else
                {
                    fact.pb({cur, 1});
                    fact.pb({nr, 1});
                }

                nr = 1;
            }
        }
    }

    cur = 0;
    for(int i = 0; i < n; ++i)
    {
        cur += a[i];

        ll x = cur;
        for(auto [d, _] : fact)
            while(x % d == 0)
                x /= d;
        ans[cur / x] ++;
    }

    for(int i = (int)fact.size() - 1; i >= 0; --i)
        Back(0, 1, i);

    ll x, q;
    cin >> q;
    while(q --)
    {
        cin >> x;

        if(sum % x != 0)
        {
            cout << "-1\n";
            continue;
        }

        cout << sum / x + n - 2 * ans[x] << '\n';
    }
    return 0;
}
