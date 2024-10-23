#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 9;

int n, d;
vector<int> res, v;



const int mod = 998244353;
const int root = 3;
const int root_1 = 332748118;
const int root_pw = mod - 1;

#define ll long long
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = base * base % mod)
        if(exp & 1)
            ret = ret * base % mod;
    return ret;
}
int inverse(int n, int m){return PtLg(n, m - 2);}

void fft(vector<int> & a, bool invert) {
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
        int wlen = PtLg(invert ? root_1 : root, (mod - 1) / len);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b)
{
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; ++i)
        fa[i] = 1LL * fa[i] * fb[i] % mod;
    fft(fa, true);

    return fa;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    if(n == 0)
    {
        cout << 1;
        return 0;
    }

    for(int i = 0; i < n; ++i)
    {
        cin >> d;

        v.resize(d + 1);
        for(int j = 0; j <= d; ++j)
            cin >> v[j];

        if(res.empty())swap(res, v);
        else res = multiply(res, v);
        while(!res.back())res.pop_back();
    }
    for(auto i : res)cout << i << ' ';

    return 0;
}
