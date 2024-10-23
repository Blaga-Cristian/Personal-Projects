#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back

using namespace std;
string TASK("strmatch");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
const int Inf = 0x3f3f3f3f;
bool test_case = false;

string a, b;

void solve()
{
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = a + "#" + b;

    vi z(n + m + 1);
    int l = 0, r = 0;
    for(int i = 1; i < a.size(); ++i)
    {
        if(i < r)z[i] = min(r - i, z[i - l]);
        while(i + z[i] < a.size() && a[i + z[i]] == a[z[i]])
            ++ z[i];
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    int cnt = 0;
    vi ans;
    for(int i = 1; i < a.size(); ++i)
        if(z[i] == n)
    {
        ++ cnt;
        if(ans.size() < 1000)
            ans.pb(i - n - 1);
    }

    cout << cnt << '\n';
    for(auto e : ans)cout << e << ' ';
    cout << '\n';
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