#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int N = 1e5 + 9;

int n, m, v[N], l, r, ST[2][N][20];
int unic[N];

void Precalc()
{
    FOR(i, 1, n)
        ST[0][i][0] = ST[1][i][0] = v[i];

    for(int k = 1; (1 << k) <= n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
        {
            ST[0][i][k] = min(ST[0][i][k - 1], ST[0][i + (1 << (k - 1))][k - 1]);
            ST[1][i][k] = max(ST[1][i][k - 1], ST[1][i + (1 << (k - 1))][k - 1]);
        }
}
int QueryMin(int st, int dr)
{
    int k = log2(dr - st + 1);
    return min(ST[0][st][k], ST[0][dr - (1 << k) + 1][k]);
}
int QueryMax(int st, int dr)
{
    int k = log2(dr - st + 1);
    return max(ST[1][st][k], ST[1][dr - (1 << k) + 1][k]);
}

int main()
{
    FAST_IN_OUT

    cin >> n;

    FOR(i, 1, n)cin >> v[i];
    Precalc();

    set<int> myst;
    multiset<int> mymst;

    int st = 1;
    FOR(i, 1, n)
    {
        mymst.insert(v[i]);
        myst.insert(v[i]);

        while(st <= i && mymst.size() != myst.size())
        {
            mymst.erase(mymst.find(v[st]));
            if(mymst.count(v[st]) == 0)myst.erase(v[st]);
            st++;
        }

        unic[i] = st;
    }


    cin >> m;
    FOR(i, 1, m)
    {
        cin >> l >> r;
        if(l >= unic[r] && QueryMax(l, r) - QueryMin(l, r) + 1 == r - l + 1)cout << 1;
        else cout << 0;
    }
    return 0;
}
