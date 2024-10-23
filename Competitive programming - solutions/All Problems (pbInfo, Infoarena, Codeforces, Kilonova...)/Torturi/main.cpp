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
ifstream fin("torturi.in");
ofstream fout("torturi.out");
const int N = 250009;

int n, m, v[N], poz[N], dp[N];
bool used[N];

int vec[N], len;
int cb(int x)
{
    if(vec[len] >= x)return len + 1;

    int st = 1, dr = len, mj, poz = 0;
    while(st <= dr)
    {
        mj = (st + dr) >> 1;
        if(vec[mj] >= x)
        {
            st = mj + 1;
        }
        else
        {
            poz = mj;
            dr = mj - 1;
        }
    }

    return poz;
}

int get_lis()
{
    FOR(i, 1, n)
    {
        if(used[i])continue;

        int p = cb(v[i]);

        if(p > len){++len, p = len;}
        vec[p] = v[i];

        dp[i] = p + 1;
    }

    int ret = 0;
    FOR(i, 1, n)ret = max(ret, dp[i]);
    return ret;
}

int main()
{
    fin >> n;
    FOR(i, 1, n)fin >> v[i];

    VI q;
    FOR(i, 1, n)
    {
        while(!q.empty() && v[q.back()] < v[i])q.pop_back();
        q.push_back(i);
    }

    for(auto i : q)used[i] = true;

    fout << q.size() + get_lis() << '\n';
    return 0;
}
