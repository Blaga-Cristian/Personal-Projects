#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define pii pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const string TASK("inversmodular");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int N = 4e5 + 9;
const ll Inf = LLONG_MAX >> 1;
const bool test_cases = true;
const int BASE = 1e8;

int n, a[N];
string s;

void solve()
{
    cin >> n;
    cin >> s;

    reverse(s.begin(), s.end());

    a[n] = 0;
    FORR(i, n - 1, 0)a[i] = a[i + 1] + s[i] - '0';

    string res;
    int c = 0;
    FOR(i, 0, n - 1)
    {
        c += a[i];
        res += char(c % 10 + '0');
        c /= 10;
    }
    res += char(c + '0');
    while(res.back() == '0')res.pop_back();

    reverse(res.begin(), res.end());
    cout << res << '\n';
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
