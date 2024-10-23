#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back

#define int long long
using namespace std;
const string TASK("ssnd");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e6 + 9, Mod = 9973;

bool p[N];
vi prime;

void Ciur()
{
    p[0] = p[1] = 1;

    for(int i = 2; i < N; ++i)
        if(!p[i])
    {
        prime.pb(i);
        for(int j = 2 * i; j < N; j += i)
            p[j] = true;
    }
}

int n;
int add(int a, int b)
{
    int x = (a + b) % Mod;
    if(x < 0)return x + Mod;
    return x;
}
int mul(int a, int b)
{
    return (a * b) % Mod;
}

int PtLg(int base, int exp)
{
    int ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Ciur();

    int t;
    cin >> t;

    while(t --)
    {
        cin >> n;
        int nd = 1, sd = 1;

        int exp;
        for(auto p : prime)
        {
            if(p * p > n)break;
            if(n % p)continue;

            for(exp = 0; n % p == 0; exp ++, n /= p);

            nd = mul(nd, exp + 1);
            sd = mul(sd, mul(add(PtLg(p, exp + 1), -1), PtLg(p - 1, Mod - 2)));
        }

        if(n != 1)
        {
            nd = mul(nd, 2);
            sd = mul(sd, n + 1);
        }

        cout << nd << ' ' << sd << '\n';
    }
    return 0;
}