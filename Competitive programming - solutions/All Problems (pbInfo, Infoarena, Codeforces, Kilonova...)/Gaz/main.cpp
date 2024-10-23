#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
//#define int long long
#define double long double
using namespace std;

const string TASK("grafscara");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 50009, PT = 64;

typedef array<array<vi, 2>, 2> mat;

int n, base, baza, cifre;

vi tmp;
mat aux;

inline void add(vi& a, vi& b)///a = a + b
{
    int n = max(a.size(), b.size()) + 1;
    a.resize(n), b.resize(n);

    ll t = 0;
    for(int i = 0; i < n; ++i, t /= base)
        a[i] = (t += 0LL + a[i] + b[i]) % base;

    while(!a.empty() && a.back() == 0)a.pop_back();
    while(!b.empty() && b.back() == 0)b.pop_back();
}


void mul(vi const& a, vi const& b, vi& res, int n)///n e marimea unui polinom
{
    if(n <= 64)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                res[i + j] += a[i] * b[j];
    }
    else
    {
        int mid = (n / 2);

        vi atmp(mid), btmp(mid), E(n), r0(n), r2(n);

        for(int i = 0; i < mid; ++i)
        {
            atmp[i] = a[i] + a[i + mid];
            btmp[i] = b[i] + b[i + mid];
        }
        mul(atmp, btmp, E, mid);

        for(int i = 0; i < mid; ++i)
        {
            atmp[i] = a[i];
            btmp[i] = b[i];
        }
        mul(atmp, btmp, r0, mid);

        for(int i = 0; i < mid; ++i)
        {
            atmp[i] = a[i + mid];
            btmp[i] = b[i + mid];
        }
        mul(atmp, btmp, r2, mid);

        for(int i = 0; i < n; ++i)
        {
            res[i] += r0[i];
            res[i + mid] += E[i] - r0[i] - r2[i];
            res[i + 2 * mid] += r2[i];
        }
    }
}


inline void mul(vi& a, vi& b, vi& res)
{
    int n = 1;
    while(n < max(a.size(), b.size()))n <<= 1;
    a.resize(n), b.resize(n);

    res.resize(2 * n);
    for(int i = 0; i < 2 * n; ++i)
        res[i] = 0;

    mul(a, b, res, n);

    ll t = 0;
    for(int i = 0; i < 2 * n; ++i, t /= base)
        res[i] = (t += res[i]) % base;

    while(!res.empty() && res.back() == 0)res.pop_back();
    for(auto i : a)cout << i;cout << " * \n";
    for(auto i : b)cout << i;cout << " = \n";
    for(auto i : res)cout << i;cout << "\n\n";
}

inline void mul(mat& a, mat& b, mat& res)
{
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        {
            res[i][j].resize(1);
            res[i][j][0] = 0;
        }

    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
            {
                mul(a[i][k], b[k][j], tmp);///mul polinoame
                add(res[i][j], tmp);///adunare polinoame
            }
}


inline void afis(vi const& v, int base)
{
    vector<ll> sol;
    ll c = 0, n = v.size();

    for(int i = 0; i + 1 < n; ++i)
    {
        c = v[i];
        for(int j = 1; j <= cifre; ++j)
        {
            sol.pb(c % baza);
            c /= baza;
        }
    }

    c = v.back();
    while(c){sol.pb(c % baza), c /= baza;}
    while(sol.back() == 0)sol.pop_back();

    for(int i = (int)sol.size() - 1; i >= 0; -- i)
        cout << sol[i];
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> base;

    baza = base;
    base = 1;
    while(baza * base < 10000000)
    {
        base *= baza, cifre ++;
    }

    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }

    if(n == 2)
    {
        afis({4}, base);
        cout << '\n';
        return 0;
    }
    n -= 2;


    mat a, b;
    a[0][0].pb(3), a[0][1].pb(1);
    a[1][0].pb(0), a[1][1].pb(0);

    b[0][0].pb(3), b[0][1].pb(1);
    b[1][0].pb(2), b[1][1].pb(1);

    for(; n; n >>= 1)
    {
        if(n & 1)
        {
            mul(a, b, aux);
            a = aux;
        }

        mul(b, b, aux);
        b = aux;
    }

    add(a[0][0], a[0][1]);
    afis(a[0][0], base);
    return 0;
}
