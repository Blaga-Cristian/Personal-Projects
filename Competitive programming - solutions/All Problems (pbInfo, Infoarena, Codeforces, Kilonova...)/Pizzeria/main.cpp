#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define ll long long
#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const string TASK("sushi");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int N = 2e5 + 9, V = 8009, Inf = 0x3f3f3f3f;
const bool test_cases = false;

int n, q, a[N];

int t_l[4 * N], t_r[4 * N];
void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        t_l[nod] = t_r[nod] = a[st];
        return;
    }
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
    t_l[nod] = min(t_l[nod << 1], t_l[nod << 1 | 1] + (m - st + 1));
    t_r[nod] = min(t_r[nod << 1] + dr - m, t_r[nod << 1 | 1]);
}
void Update(int p, int val, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        t_l[nod] = t_r[nod] = val;
        return;
    }
    int m = (st + dr) >> 1;
    if(p <= m)Update(p, val, nod << 1, st, m);
    else Update(p, val, nod << 1 | 1, m + 1, dr);
    t_l[nod] = min(t_l[nod << 1], t_l[nod << 1 | 1] + (m - st + 1));
    t_r[nod] = min(t_r[nod << 1] + dr - m, t_r[nod << 1 | 1]);
}
int Query_Left(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return t_l[nod] + st - l;
    int m = (st + dr) >> 1;
    if(r <= m)return Query_Left(l, r, nod << 1, st, m);
    else if(l > m)return Query_Left(l, r, nod << 1 | 1, m + 1, dr);
    return min(Query_Left(l, r, nod << 1, st, m), Query_Left(l, r, nod << 1 | 1, m + 1, dr));
}
int Query_Right(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return t_r[nod] + r - dr;
    int m = (st + dr) >> 1;
    if(r <= m)return Query_Right(l, r, nod << 1, st, m);
    else if(l > m)return Query_Right(l, r, nod << 1 | 1, m + 1, dr);
    return min(Query_Right(l, r, nod << 1, st, m), Query_Right(l, r, nod << 1 | 1, m + 1, dr));
}

void solve()
{
    cin >> n >> q;
    FOR(i, 1, n)cin >> a[i];

    Build();

//    cout << Query_Left(4, 6) << '\n';
//    Update(4, 99);
//    cout << Query_Left(4, 6) << '\n';

    int op, p, x;
    FOR(i, 1, q)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> p >> x;
            Update(p, x);
        }
        else
        {
            cin >> p;
            cout << min(Query_Right(1, p), Query_Left(p, n)) << '\n';
        }
    }
}

signed main()
{
    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
