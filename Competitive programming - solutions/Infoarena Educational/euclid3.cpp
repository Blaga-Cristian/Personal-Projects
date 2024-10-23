#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>

using namespace std;
string TASK("euclid3");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
bool test_case = true;

pii euclid(int a, int b)
{
    if(!b)return {1, 0};
    auto [x, y] = euclid(b, a % b);
    return {y, x - (a / b) * y};
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int g = __gcd(a, b);
    if(c % g != 0)
    {
        cout << "0 0\n";
        return;
    }
    c /= g;

    auto r = euclid(a, b);
    cout << c * r.ff << ' ' << c * r.ss << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    if(test_case)cin >> t;
    while(t --)
        solve();
    return 0;
}