#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const string TASK("concurs");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e7 + 9;
const ll Mod = 1e9 + 7;
const bool test_cases = true;

int n;
bool p[N];
vector<int> prime;

void Precalc()
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

int desc(int nr, int p)
{
    int ret = 0;

    while(nr >= p)
    {
        nr /= p;
        ret += nr;
    }

    return ret;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int nr1, nr2;
    bool ok = true;
    for(auto p : prime)
    {
        nr1 = desc(b, p) - desc(a - 1, p);
        nr2 = desc(d, p) - desc(c - 1, p);

        if(nr1 > nr2)
        {
            ok = false;
            break;
        }
    }

    if(ok)cout << "DA\n";
    else cout << "NU\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    Precalc();
    if(test_cases)cin >> t;
    while(t --)
        solve();

//    cout << prime.size() << '\n';
    return 0;
}
