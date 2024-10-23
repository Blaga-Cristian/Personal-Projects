//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const int N = 4109, B = 20;

int n, m, k, cor[300];
char a[N][N];

typedef array<int, B> num;
num operator ^ (num const& a, num const& b)
{
    num c;
    for(int i = 0; i < B; ++i)
    {
        c[i] = a[i] + b[i];
        if(c[i] >= k)c[i] -= k;
    }
    return c;
}
ostream& operator << (ostream& os, num const& a)
{
    for(int i = 0; i < B; ++i)
        os << a[i];
    return os;
}
void reset(num& a)
{
    for(int i = 0; i < B; ++i)
        a[i] = 0;
}

mt19937 rng(42069);

int cmp(int l1, int l2)
{
    int cnt = 0;
    for(int i = 1; i <= m; ++i)
        if(a[l1][i] != a[l2][i])
            cnt ++;
    return cnt;
}

num xr[4];

typedef array<int, B + 1> num2;
num2 operator ^ (num2 const& a, num2 const& b)
{
    num2 c;
    for(int i = 0; i < B; ++i)
    {
        c[i] = a[i] + b[i];
        if(c[i] >= k + 1)c[i] -= k + 1;
    }
    return c;
}
bool operator == (num2 const& a, num2 const& b)
{
    for(int i = 0; i < B; ++i)
        if(a[i] != b[i])
            return false;
    return true;
}
ostream& operator << (ostream& os, num2 const& a)
{
    for(int i = 0; i < B; ++i)
        os << a[i];
    return os;
}
void reset(num2& a)
{
    for(int i = 0; i < B; ++i)
        a[i] = 0;
}

num2 xr2[4];

vector<num> hsh, fnl;
vector<num2> hsh2, fnl2;

int check(int a, int b)
{
    for(int i = 0; i < B; ++i)
        if((fnl2[a][i] + hsh2[b][i]) != k + 1)
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    hsh = fnl = vector<num>(n + 1);
    hsh2 = fnl2 = vector<num2>(n + 1);
    cor['A'] = 0;
    cor['C'] = 1;
    cor['G'] = 2;
    cor['T'] = 3;

    FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

    FOR(i, 1, n)FOR(j, 0, B - 1)
    {
        hsh[i][j] = rng() % k;
        hsh2[i][j] = rng() % (k + 1);
    }

//    FOR(i, 1, n)cout << fnl[i] << '\n';


    FOR(j, 1, m)
    {
        FOR(i, 0, 3)
        {
            reset(xr[i]);
            reset(xr2[i]);
        }

        FOR(i, 1, n)
        {
            xr[cor[a[i][j]]] = xr[cor[a[i][j]]] ^ hsh[i];
            xr2[cor[a[i][j]]] = xr2[cor[a[i][j]]] ^ hsh2[i];
        }

        FOR(i, 1, n)
            FOR(l, 0, 3)
                if(cor[a[i][j]] != l)
                {
                    fnl[i] = fnl[i] ^ xr[l];
                    fnl2[i] = fnl2[i] ^ xr2[l];
                }
    }

    num2 all;
    reset(all);
    FOR(i, 1, n)all = all ^ hsh2[i];

    reset(xr[0]);

//    cout << (fnl2[4] ^ all) << '\n';
//    cout << hsh2[4] << '\n';
//    cout << fnl[4] << '\n';

    FOR(i, 1, n)
        if(fnl[i] == xr[0])
        {
            fnl2[i] = fnl2[i] ^ all;
            if(fnl2[i] == hsh2[i])
                cout << i << '\n';
        }
    return 0;
}
