#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll


using namespace std;
const int N = 2509;

VI solve(VI v)
{
    int n = v.size();
    VI r;
    VI poz(n);

    FOR(i, 0, n - 1)poz[v[i] - 1] = i;

    FOR(i, 0, n - 1)
        if(poz[i] != i)
        {
            r.pb(i + 1);
            r.pb(poz[i] - i);
            r.pb(n - poz[i]);

            swap(v[i], v[poz[i]]);
            poz[v[poz[i]] - 1] = poz[i];
            poz[i] = i;
        }

    return r;
}

void show_same_parity(VI& v1, VI& v2, int n, int m)
{
    cout << max(v1.size(), v2.size()) << '\n';

    for(int i = 0; i < v1.size() || i < v2.size(); ++i)
    {
        if(i < v1.size() && i < v2.size())cout << v1[i] << ' ' << v2[i] << '\n';
        else if(i < v2.size())
        {
            cout << 1 << ' ' << v2[i] << '\n';
            cout << n << ' ' << v2[i + 1] << '\n';
            ++i;
        }
        else if(i < v1.size())
        {
            cout << v1[i] << ' ' << 1 << '\n';
            cout << v1[i + 1] << ' ' << m << '\n';
            ++i;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    VI a(n), b(m);

    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 0, m - 1) cin >> b[i];

    auto v1 = solve(a);
    auto v2 = solve(b);


    if(v1.size() % 2 == v2.size() % 2)
        show_same_parity(v1, v2, n, m);
    else
    {
        if(n % 2 == 1)
        {
            FOR(i, 0, n - 1)v1.pb(1);
            show_same_parity(v1, v2, n, m);
        }
        else if(m % 2 == 1)
        {
            FOR(i, 0, m - 1)v2.pb(1);
            show_same_parity(v1, v2, n, m);
        }
        else cout << "-1\n";
    }
    return 0;
}
