#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9, MOD = 777013;

int n, dp[N];

struct matrix
{
    int sz;
    vector<vector<int>> mat;

    matrix() : sz (), mat()
    {}
    matrix(int sz) : sz(sz), mat(vector<vector<int>>(sz, vector<int>(sz)))
    {}

    matrix operator * (matrix const& m)
    {
        matrix a(sz);
        for(int i = 0; i < sz; ++i)
            for(int j = 0; j < sz; ++j)
                for(int k = 0; k < sz; ++k)
                    a.mat[i][j] = (a.mat[i][j] + 1LL * mat[i][k] * m.mat[k][j]) % MOD;

        return a;
    }

    matrix pow(int exp)
    {
        matrix baza = *this, ret(sz);
        for(int i = 0; i < sz; ++i)ret.mat[i][i] = 1;

        while(exp)
        {
            if(exp & 1)
                ret = ret * baza;

            baza = baza * baza;
            exp >>= 1;
        }

        return ret;
    }
};

int main()
{
    cin >> n;

    if(n == 1 || n == 2)
    {
        cout << 1;
        return 0;
    }

    matrix x(3);
    x.mat[0][0] = x.mat[0][1] = x.mat[0][2] = 1;
    x.mat[0][1]++;

    matrix baza(3);
    baza.mat[0][1] = baza.mat[1][0] = baza.mat[1][1] = baza.mat[2][1] = baza.mat[2][2] = 1;

    x = x * baza.pow(n - 2);

    cout << x.mat[0][1];
    return 0;
}
