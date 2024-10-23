#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pb push_back
#define VL vector<ll>
#define VI vector<int>
#define VVI vector<VI>

using namespace std;
const bool testcase = false;
const int N = 1e5 + 9;

ll t, n;
char s[N];
map<int, bool> is_target;
map<int, int> destf;
map<int, int> dest;
map<int, int> earl; ///earliest time this pos is fired
int v[N];
int l[N][3], r[N][3];
int cnt[N];

void solve()
{
    cin >> t >> n;
    FOR(i, 1, t)
    {
        cin >> v[i];
        is_target[v[i]] = true;
    }
    cin >> (s + 1);

    int posf = 0;
    FOR(i, 1, n)
    {
        cnt[i] = cnt[i - 1];

        if(s[i] == 'L')posf --;
        else if(s[i] == 'R')posf ++;
        else if(is_target[posf])
        {
            if(destf[posf] == 0)cnt[i] ++;
            destf[posf] ++;
        }

        if(s[i] == 'F')earl[posf] = i;
    }

    int ans = cnt[n];

    int pos = posf;
    dest.clear();
    for(auto i : destf)dest[i.F] = i.S;
    FORR(i, n, 1)
    {
        if(s[i] == 'L')pos ++;
        else if(s[i] == 'R')pos --;
        else if(is_target[pos] && dest[pos] != 0)dest[pos] --;

        r[i][1] = r[i + 1][1];
        if(s[i] == 'F' && is_target[pos + 1])
        {
            if(dest[pos + 1] == 0)r[i][1] ++;
            dest[pos + 1] ++;
        }
    }

    pos = posf;
    dest.clear();
    for(auto i : destf)dest[i.F] = i.S;
    FORR(i, n, 1)
    {
        if(s[i] == 'L')pos ++;
        else if(s[i] == 'R')pos --;
        else if(is_target[pos] && dest[pos] != 0)dest[pos] --;

        r[i][2] = r[i + 1][2];
        if(s[i] == 'F' && is_target[pos + 2])
        {
            if(dest[pos + 2] == 0)r[i][2] ++;
            dest[pos + 2] ++;
        }
    }

    pos = posf;
    dest.clear();
    for(auto i : destf)dest[i.F] = i.S;
    FORR(i, n, 1)
    {
        if(s[i] == 'L')pos ++;
        else if(s[i] == 'R')pos --;
        else if(is_target[pos] && dest[pos] != 0)dest[pos] --;

        l[i][1] = l[i + 1][1];
        if(s[i] == 'F' && is_target[pos - 1])
        {
            if(dest[pos - 1] == 0)l[i][1] ++;
            dest[pos - 1] ++;
        }
    }

    pos = posf;
    dest.clear();
    for(auto i : destf)dest[i.F] = i.S;
    FORR(i, n, 1)
    {
        if(s[i] == 'L')pos ++;
        else if(s[i] == 'R')pos --;
        else if(is_target[pos] && dest[pos] != 0)dest[pos] --;

        l[i][2] = l[i + 1][2];
        if(s[i] == 'F' && is_target[pos - 2])
        {
            if(dest[pos - 2] == 0)l[i][2] ++;
            dest[pos - 2] ++;
        }
    }


    pos = 0;
    FOR(i, 1, n)
    {
        if(s[i] == 'L')ans = max(ans, max(cnt[i - 1] + r[i + 1][2], cnt[i - 1] + r[i + 1][1] + (is_target[pos] && (earl[pos] >= i - 1 || earl[pos] == 0) && (earl[pos - 1] <= i + 1 || earl[pos - 1] == 0))));
        else if(s[i] == 'R')ans = max(ans, max(cnt[i - 1] + l[i + 1][2], cnt[i - 1] + l[i + 1][1] + (is_target[pos] && (earl[pos] >= i - 1 || earl[pos] == 0) && (earl[pos + 1] <= i + 1 || earl[pos + 1] == 0))));
        else ans = max(ans, max(cnt[i - 1] + l[i + 1][1], cnt[i - 1] + r[i + 1][1]));


        if(s[i] == 'L')pos ++;
        else if(s[i] == 'R')pos --;
        else if(is_target[pos] && dest[pos] != 0)dest[pos] --;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    if(testcase)cin >> t;
    while(t --)
        solve();
    return 0;
}
