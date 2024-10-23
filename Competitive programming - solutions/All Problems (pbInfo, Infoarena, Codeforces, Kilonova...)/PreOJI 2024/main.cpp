#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

using namespace std;
const string TASK("morcovi");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const ll Inf = 0x3f3f3f3f;
const int N = 3e5 + 9;
const bool test_cases = true;

ll n, k;
ll ans = 0;

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
void get(int div)
{
    int tar = 1 + (k / div);
    for(int i = 1; i * i <= tar; ++i)
    {
        if(tar % i == 0 && (tar / i) <= n / div && gcd(i, tar / i) == 1)ans ++;
    }
}

void solve()
{
    cin >> n >> k;

    ans = 0;
    for(int i = 1; i * i <= k; ++i)
    {
        if(k % i == 0)
        {
            get(i);
            if(i * i != k)get(k / i);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
