#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

const string TASK("grafscara29_10");
ifstream fin(TASK + ".in");
ofstream fout("test.out");
#define cin fin
#define cout fout

const int N = 50009, PT = 64;

typedef array<array<vi, 2>, 2> mat;

int n, base;

vi tmp;
mat aux;

void add(vi& a, vi& b)///a = a + b
{
    int n = max(a.size(), b.size()) + 1;
    a.resize(n), b.resize(n);

    for(int i = 0, t = 0; i < n; ++i, t /= base)
        a[i] = (t += a[i] + b[i]) % base;

    while(!a.empty() && a.back() == 0)a.pop_back();
    while(!b.empty() && b.back() == 0)b.pop_back();
}

using cd = complex<double>;

const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void mul(vi const& a, vi const& b, vi& res)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size())n <<= 1;
    fa.resize(n), fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for(int i = 0, t = 0; i < n; ++i, t /= base)
        res[i] = (t += round(fa[i].real())) % base;

//    for(auto i : a)cout << i;cout << " * \n";
//    for(auto i : b)cout << i;cout << " = \n";
//    for(auto i : res)cout << i;cout << "\n\n";
}

void mul(mat& a, mat& b, mat& res)
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

void att(mat& a, mat& b)///swap(a, b)
{
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            swap(a[i][j], b[i][j]);
}


void afis(int nr, int base)
{
    if(nr == 0)return;
    afis(nr / base, base);
    cout << nr % base;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> base;

    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }

    if(n == 2)
    {
        afis(4, base);
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
            att(a, aux);
        }

        mul(b, b, aux);
        att(b, aux);
    }

    add(a[0][0], a[0][1]);
    for(int i = (int)a[0][0].size() - 1; i >= 0; --i)cout << a[0][0][i];
    return 0;
}
