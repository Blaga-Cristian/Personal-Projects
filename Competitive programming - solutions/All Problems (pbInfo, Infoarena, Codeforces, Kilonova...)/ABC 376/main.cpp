#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;
const int N = 2e5 + 9;
const bool test_cases = false;

long double x[N], alf;

void solve()
{
    cin >> x[1] >> x[2] >> alf;

    FOR(i, 3, 20)
    {
        x[i] = alf * x[i - 1] + (1 - alf) * x[i - 2];

        cout << x[i] << ' ';
    }
    cout << '\n';

    cout << ((1 - alf) * x[1] + x[2]) / (1 - alf / 2) / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
