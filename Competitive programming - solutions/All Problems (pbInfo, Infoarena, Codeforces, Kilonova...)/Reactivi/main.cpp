#include <bits/stdc++.h>

using namespace std;
const int N = 8009;

int n;
struct info
{
    int l, r;

    bool operator < (info const& a)
    {
        return l == a.l ? r < a.r : l < a.l;
    }

    info operator - (info const& a)
    {
        if(l < a.l)
        {
            if(r < a.l)return {-999, -999};
            return {a.l, min(a.r, r)};
        }
        else
        {
            if(a.r < l)return {-999, -999};
            return {l, min(a.r, r)};
        }
    }
}v[N];

bool cut[N];

int main()
{
    freopen("reactivi.in", "r", stdin);
    freopen("reactivi.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> v[i].l >> v[i].r;

    sort(v + 1, v + n + 1);

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(cut[i])continue;

        int j = i + 1;
        while(j <= n && (v[i] - v[j]).l != -999)
        {
            v[i] = v[i] - v[j];
            j ++;
        }

        ++ans;
        for(int k = i; k < j; ++k)cut[k] = true;
    }

    cout << ans;
    return 0;
}
