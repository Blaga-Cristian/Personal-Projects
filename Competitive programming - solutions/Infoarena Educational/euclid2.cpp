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
string TASK("euclid2");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
bool test_case = true;

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << '\n';
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