//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const string TASK("dulciuri");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
#define cout fout
auto in = fopen("dulciuri.in", "r");

void next();
void get(int&);

const int N = 1e6 + 9;

int q;

ll aibx[N], aiby[N];
void Update(int p, int val, ll* aib)
{
    for(; p < N; p += p & -p)
        aib[p] += val;
}
ll Query(int p, ll* aib)
{
    ll ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}
ll Query(int l, int r, ll* aib)
{
    if(l > r)swap(l, r);
    return Query(r, aib) - Query(l - 1, aib);
}

int main()
{
    next();
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    get(q);

    cout << fixed << setprecision(12);

    int op, x, y, v, x1, y1, x2, y2;
    for(int i = 1; i <= q; ++i)
    {
        get(op);
        if(op == 1)
        {
            get(x), get(v);
            ++ x;
            Update(x, v, aibx);
        }
        else if(op == 2)
        {
            get(y), get(v);
            ++ y;
            Update(y, v, aiby);
        }
        else
        {
            get(x1), get(y1), get(x2), get(y2);
            ++ x1, ++ y1, ++ x2, ++ y2;
            if(x1 > x2)swap(x1, x2);
            if(y1 > y2)swap(y1, y2);

            long double ans = 0;

            if(x1 == x2)ans += 1.0 * Query(x2, x2, aibx);
            else ans += 1.0 * Query(x1, x2 - 1, aibx) / (x2 - x1);

            if(y1 == y2)ans += 1.0 * Query(y2, y2, aiby);
            else ans += 1.0 * Query(y1, y2 - 1, aiby) / (y2 - y1);

            cout << ans << '\n';
        }
    }

    return 0;
}


const int Lim = 1e6;
char s[Lim];
int p = Lim - 1;

void next()
{
    if(++ p == Lim)
    {
        p = 0;
        fread(s, 1, Lim, in);
    }
}

void get(int& x)
{
    while(s[p] != '-' && !isdigit(s[p]))next();

    int sign = 1;
    if(s[p] == '-')sign = -1, next();

    for(x = 0; isdigit(s[p]); next())
        x = x * 10 + s[p] - '0';
}
