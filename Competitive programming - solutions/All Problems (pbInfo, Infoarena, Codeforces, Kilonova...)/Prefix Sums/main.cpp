#include <bits/stdc++.h>
//#include <bits/extc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long
#define double long double
#define eb emplace_back
#define lo(x) (2 * (x) - 1)
#define up(x) (2 * (x))
#define int long long
using namespace std;
//using namespace __gnu_pbds;

const int N = 2e5 + 9, M = 10;
using matrix = array<array<int, M>, M>;

int n, k, sz;
vi v;

matrix mul(matrix const& a, matrix const&  b)
{
    matrix c;
    FOR(i, 0, M - 1)FOR(j, 0, M - 1)c[i][j] = 0;

    FOR(i, 0, M - 1)
        FOR(j, 0, M - 1)
            FOR(l, 0, M - 1)
            {
                int add = 0;
                if(b[l][j] && a[i][l] > k / b[l][j])add = k;
                else add = a[i][l] * b[l][j];

                c[i][j] = min(k, c[i][j] + add);
            }

    return c;
}

bool solve(int x)
{
    matrix vec;
    FOR(i, 0, M - 1)FOR(j, 0, M - 1)vec[i][j] = 0;
    FOR(i, 0, sz - 1)vec[0][i] = v[i];


    matrix mat;
    FOR(i, 0, M - 1)FOR(j, 0, M - 1)mat[i][j] = 0;
    FOR(i, 0, sz - 1)FOR(j, i, sz - 1)mat[i][j] = 1;

    for(; x; x >>= 1, mat = mul(mat, mat))
        if(x & 1)
            vec = mul(vec, mat);

    FOR(i, 0, sz - 1)if(vec[0][i] >= k)return true;
    return false;
}

signed main()
{
    cin >> n >> k;

    v.resize(n);
    FOR(i, 0, n - 1)cin >> v[i];

    auto it = v.begin();
    for(; *it == 0; ++it);
    v.erase(v.begin(), it);

    for(auto i : v)
        if(i >= k)
        {
            cout << "0\n";
            return 0;
        }

    sz = v.size();

    if(v.size() > M)
    {
        for(int nr_it = 1; true; ++nr_it)
        {
            FOR(i, 0, sz - 1)
            {
                if(i > 0)v[i] = min(k, v[i - 1] + v[i]);
                if(v[i] >= k)
                {
                    cout << nr_it << '\n';
                    return 0;
                }
            }
        }
    }

    int st = 0, dr = 1e18 + 9, m, pos;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        if(solve(m))
        {
            pos = m;
            dr = m - 1;
        }
        else st = m + 1;
    }

    cout << pos << '\n';
    return 0;
}
