#include <bits/stdc++.h>
#define dd long double
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 1e5 + 9;

const string TASK("aria");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

using pct = pair<dd, dd>;
#define x first
#define y second

int n;
pct v[N];

dd det(pct a, pct b)
{
    return a.x * b.y - b.x * a.y;
}

int main()
{
    cin >> n;
    FOR(i, 1, n)cin >> v[i].x >> v[i].y;

    v[n + 1] = v[1];
    dd ans = 0;
    FOR(i, 1, n)ans += det(v[i], v[i + 1]);

    cout << fixed << setprecision(6) << abs(ans / 2.0) << '\n';
    return 0;
}