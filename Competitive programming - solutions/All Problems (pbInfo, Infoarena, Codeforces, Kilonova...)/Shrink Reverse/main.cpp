#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

#define int long long
using namespace std;
const int N = 5e5 + 9, Mod = 1e9 + 7, P = 127, M = 1e9 + 123;

int n, k, pt2[N], u[N], pt[N], hsh[N];
string s, a, b;

bool cmp(int l1, int r1, int l2, int r2)///x < y
{
    int st = 0, dr = min(r1 - l1, r2 - l2), m, pos = -1;
    while(st <= dr)
    {
        m = (st + dr) >> 1;

        int hash1 = hsh[l1 + m - 1];
        if(l1 > 0)hash1 = (hash1 - (hsh[l1 - 1] * pt[m]) % M + M) % M;

        int hash2 = hsh[l2 + m - 1];
        if(l2 > 0)hash2 = (hash2 - (hsh[l2 - 1] * pt[m]) % M + M) % M;

        if(hash1 != hash2)
        {
            pos = m;
            dr = m - 1;
        }
        else st = m + 1;
    }

    if(pos == -1)return false;
    return b[l1 + pos - 1] < b[l2 + pos - 1];
}

bool compare(int l1, int r1, int l2, int r2)///operator <
{
    FOR(i, 1, r1 - l1 + 1)
    {
        if(a[l1 + i - 1] == b[l2 + i - 1])continue;
        return a[l1 + i - 1] < b[l2 + i - 1];
    }
    return false;
}

signed main()
{
    cin >> n >> k;
    cin >> s;

    pt2[0] = 1;
    FOR(i, 1, N - 1)pt2[i] = (pt2[i - 1] * 2) % Mod;

    ///CAZUL 1
    a = s;
    int p1 = 0, p0 = n - 1;
    FOR(i, 1, k)
    {
        while(p1 < p0 && a[p1] != '1')++ p1;
        while(p0 > p1 && a[p0] != '0')-- p0;

        if(p0 != p1)swap(a[p0], a[p1]);
    }

    ///CAZUL 2, minimizez lexicografic pe s
    b = s;
    reverse(b.begin(), b.end());

    int nr1 = 0;
    FOR(i, 0, n - 1)nr1 += (b[i] == '1');

    int r = 0, cntout = nr1 - (b[0] == '1');
    FOR(l, 0, n - 1)
    {
        while(r + 1 < n && (r - l + 1 < nr1 || cntout > k - 1))
        {
            ++ r;
            if(b[r] == '1')cntout --;
        }

        if(r < n && r - l + 1 >= nr1 && cntout <= k - 1)
            u[l] = r;
        else
            u[l] = -1;

        if(b[l] == '1')cntout ++;
    }

    pt[0] = 1;
    FOR(i, 1, N - 1)pt[i] = (pt[i - 1] * P) % M;

    hsh[0] = b[0];
    FOR(i, 1, n - 1)hsh[i] = (hsh[i - 1] * P + b[i]) % M;

    int opt = 0;
    FOR(i, 1, n - 1)
        if(u[i] != -1)
        {
            if(u[opt] - opt > u[i] - i)
                opt = i;
            else if(u[opt] - opt == u[i] - i && cmp(i, u[i], opt, u[opt]))
                opt = i;
        }

//    cout << b << '\n';

    int nrout = 0;
    FOR(i, 0, opt - 1)if(b[i] == '1')nrout ++;
    FOR(i, u[opt] + 1, n - 1)if(b[i] == '1')nrout ++;

    FORR(i, u[opt], opt)
        if(b[i] == '0' && nrout)
        {
            b[i] = '1';
            nrout --;
        }

//    cout << opt << ' ' << u[opt] << '\n';
//    cout << b << '\n';

    int l = n; r = n - 1;
    FOR(i, 0, n - 1)
        if(a[i] == '1')
        {
            l = i;
            break;
        }

    int ans = 0;
    if(r - l < u[opt] - opt || (r - l == u[opt] - opt && compare(l, r, opt, u[opt])))
    {
        FOR(i, l, r)
            if(a[i] == '1')
                ans = (ans + pt2[r - i]) % Mod;

        cout << ans << '\n';
    }
    else
    {
        FOR(i, opt, u[opt])
            if(b[i] == '1')
                ans = (ans + pt2[u[opt] - i]) % Mod;

        cout << ans << '\n';
    }
    return 0;
}
