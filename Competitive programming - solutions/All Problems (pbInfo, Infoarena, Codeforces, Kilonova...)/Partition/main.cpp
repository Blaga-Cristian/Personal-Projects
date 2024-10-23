#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define int long long
using namespace std;

const string TASK("partition");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout


const int N = 2e3 + 9;

int n, m, a[N];

int sp[N];
int get_sum(int l, int r)
{
    if(l > r)return 0;
    return sp[r] - sp[l - 1];
}

struct node
{
    int sum, l1, r1, v1, l2, r2, v2;

    node() : sum(0), l1(-1), r1(-1), v1(-1), l2(-1), r2(-1), v2(-1) {}

    friend node operator + (node a, node b)
    {
        node c;

        if(a.l1 == -1)///nu e grup in a
        {
            c.l1 = b.l1;
            c.r1 = b.r1;
            c.v1 = b.v1;

            c.l2 = b.l2;
            c.r2 = b.r2;
            c.v2 = b.v2;

            c.sum = a.sum + b.sum;
        }
        else if(b.l1 == -1)///nu e grup in b
        {
            c.l1 = a.l1;
            c.r1 = a.r1;
            c.v1 = a.v1;

            c.l2 = a.l2;
            c.r2 = a.r2;
            c.v2 = a.v2;

            c.sum = a.sum + b.sum;
        }
        else///abele au cel putin un grup
        {
            if(a.v2 + get_sum(a.r2 + 1, b.l1 - 1) + b.v1 <= min(a.v2, b.v1))
            {
                if(a.l1 == a.l2)///a are un singur grup
                {
                    c.l1 = a.l2;
                    c.r1 = b.r1;
                    c.v1 = min(a.v1, b.v1);
                }
                else
                {
                    c.l1 = a.l1;
                    c.r1 = a.r1;
                    c.v1 = a.v1;
                }

                if(b.l1 == b.l2)///b are un singur grup
                {
                    c.l2 = a.l2;
                    c.r2 = b.r2;
                    c.v2 = min(a.v2, b.v2);
                }
                else
                {
                    c.l2 = b.l2;
                    c.r2 = b.r2;
                    c.v2 = b.v2;
                }

                c.sum = a.sum + b.sum
                - (a.v2 + get_sum(a.r2 + 1, b.l1 - 1) + b.v1)
                + min(a.v2, b.v1);
            }
            else
            {
                c.l1 = a.l1;
                c.r1 = a.r1;
                c.v1 = a.v1;

                c.l2 = b.l2;
                c.r2 = b.r2;
                c.v2 = b.v2;

                c.sum = a.sum + b.sum;
            }
        }

        return c;
    }
};

node t[4 * N];
void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        if(a[st] < 0)
        {
            t[nod].l1 = t[nod].r1 = t[nod].l2 = t[nod].r2 = st;
            t[nod].v1 = t[nod].v2 = a[st];
        }

        t[nod].sum = a[st];

        return;
    }

    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);

    t[nod] = t[nod << 1] + t[nod << 1 | 1];
}

node Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return t[nod];
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return Query(l, r, nod << 1, st, m) + Query(l, r, nod << 1 | 1, m + 1, dr);
}

int ans[N][N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
//     >> m;

//    FOR(i, 1, n)cin >> a[i];

    srand(time(NULL));
    const int L = -1000, R = 1000;
    FOR(i, 1, n)a[i] = (rand() % (R - L + 1)) + L;

    FOR(i, 1, n)cout << a[i] << ' ';
    cout << '\n';


    vector<int> v;
    FOR(i, 1, n)
    {
        if(v.empty())v.pb(i);
        else if(v.back() <= 0 && a[i] <= 0)v.back() += a[i];
        else if(v.back() > 0 && a[i] > 0)v.back() += a[i];
        else v.push_back(a[i]);
    }

    FOR(i, 0, v.size() - 1)
        a[i + 1] = v[i];
    n = v.size();

    sp[0] = 0;
    FOR(i, 1, n)sp[i] = sp[i - 1] + a[i];

    FOR(i, 1, n)FOR(j, 1, n)ans[i][j] = LLONG_MIN >> 2;
    FOR(i, 1, n)
    {
        ans[i][i] = a[i];
        FOR(j, i + 1, n)
        {
            int mn = a[j];
            FORR(k, j - 1, i)
            {
                ans[i][j] = max(ans[i][j], ans[i][k] + mn);
                mn = min(mn, a[k]);
            }

            ans[i][j] = max(ans[i][j], mn);
        }
    }

    Build();

//    node a, b;
//    a.l1 = a.l2 = 4;
//    a.r1 = a.r2 = 5;
//    a.v1 = a.v2 = -4;
//    a.sum = -4;
//
//    b.l1 = b.l2 = b.r1 = b.r2 = 7;
//    b.v1 = b.v2 = -2;
//    b.sum = -1;
//
//
//    node res = a + b;
//    cout << res.sum << '\n';

    FOR(i, 1, n)
        FOR(j, i, n)
        {
            if(ans[i][j] != Query(i, j).sum)
            {
                cout << "Error at [" << i <<  ' ' << j << "] " << ans[i][j] << " != " << Query(i, j).sum << '\n';
                return 0;
            }
        }

//    cout << ans[1][3] << '\n';
//    cout << ans[1][4] << '\n';
//    int x, y;
//    FOR(i, 1, m)
//    {
//        cin >> x >> y;
//        ++ x, ++ y;
//
//        cout << ans[x][y] << '\n';
//        cout << Query(x, y).sum << '\n';
//    }
    return 0;
}
