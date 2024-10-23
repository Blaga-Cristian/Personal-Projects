#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 2e5 + 9;

int k, n, m;

using cd = complex<double>;
double PI = acos(-1);

void fft(vector<cd>& a, bool inverse = false)
{
    int n = a.size();

    for(int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len *= 2)
    {
        double angle = 2 * PI / len * (inverse ? -1 : 1);
        cd wlen = cd(cos(angle), sin(angle));

        for(int i = 0; i < n; i += len)
        {
            cd w(1);
            for(int j = 0; j < len / 2; ++j)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(inverse)
        for(auto& x : a)
            x /= n;
}

vector<int> multiply(vector<int> const& a, vector<int> const& b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);
    for(int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> res(n);
    for(int i = 0; i < n; ++i)
        res[i] = round(fa[i].real());
    return res;
}

signed main()
{
    cin >> k >> n >> m;

    vector<int> a(k + 1), b(k + 1);

    int x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        a[x] ++;
    }
    for(int j = 1; j <= m; ++j)
    {
        cin >> x;
        b[x] ++;
    }

    auto res = multiply(a, b);
    for(int i = 2; i <= 2 * k; ++i)
        cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
