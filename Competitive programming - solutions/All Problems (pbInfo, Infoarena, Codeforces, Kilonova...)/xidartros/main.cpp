#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 9;

int n, b, k;
int poz[N];
int perm[N];
int nrs[N];
ull ans[N];
ull putere[N];
bool possible;

void solve()
{
    cin >> n >> b >> k;

    possible = true;
    for(int i = 1; i <= n; ++i)
    {
        poz[i] = i;
        perm[i] = nrs[i] = 0;
        ans[i] = 0;
    }

    putere[0] = 1;
    for(int i = 1; i < k; ++i)putere[i] = putere[i - 1] * b;



    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cin >> perm[j];

        nrs[perm[n]] = b - 1;
        int prv = b - 1;

        for(int j = n - 1; j >= 1; --j)
            if(poz[perm[j]] < poz[perm[j + 1]])
                nrs[perm[j]] = prv;
            else
                nrs[perm[j]] = -- prv;

        if(nrs[perm[1]] < 0)
            possible = false;

        int dif = nrs[perm[1]];
        for(int j = 1; j <= n; ++j)
            ans[j] += putere[i - 1] * (nrs[j] - dif);

        for(int j = 1; j <= n; ++j)poz[perm[j]] = j;
    }


    if(!possible)
        cout << "-1";
    else
    {
        for(int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
    }

    cout << '\n';
}

int main()
{
    freopen("xidartros.in", "r", stdin);
    freopen("xidartros.out", "w", stdout);


    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
