#include <bits/stdc++.h>
#define dd long double
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int N = 2e6 + 9;

const string TASK("strmatch");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

int n, m;
string a, b, s;


int main()
{
    cin >> a >> b;
    n = a.size(), m = b.size();

    s.resize(n + m + 1);
    FOR(i, 0, n - 1)s[i] = a[i];
    s[n] = '$';
    FOR(i, 0, m - 1)s[i + n + 1] = b[i];

    vi z(n + m + 1);
    int l = 0, r = 0;
    FOR(i, 1, n + m)
    {
        if(i < r)z[i] = min(z[i - l], r - i);
        while(i + z[i] < n + m + 1 && s[i + z[i]] == s[z[i]])++ z[i];
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    vi ans;int nr = 0;
    FOR(i, 1, n + m)
        if(z[i] == n)
        {
            if(ans.size() < 1000)ans.pb(i);
            nr ++;
        }

    cout << nr << '\n';
    for(auto i : ans)cout << i - n - 1 << ' ';
    return 0;
}
