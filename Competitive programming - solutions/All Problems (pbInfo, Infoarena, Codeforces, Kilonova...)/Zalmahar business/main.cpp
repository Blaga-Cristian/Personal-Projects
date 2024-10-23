#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back

using namespace std;
const int N = 2e5 + 9;
const bool test_cases = false;

int n, a[N];

void solve()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    ll sum = 0;
    map<ll, int> mp[2];///mp[i] = incepe pe o pozitie para sau impara
    mp[0][0] = 0;

    FOR(i, 1, n)
    {
        sum += (1 - 2 * (i % 2)) * a[i];

        if(mp.count(sum))
        {
            cout << mp[sum] + 1 << ' ' << i << '\n';
            return;
        }

        if(!mp.count(sum))mp[sum] = i;
    }

    cout << "-1\n";
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
