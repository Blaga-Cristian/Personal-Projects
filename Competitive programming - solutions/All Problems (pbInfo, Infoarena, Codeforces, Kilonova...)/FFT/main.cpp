#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;


//void mul(const int* a, const int* b, int* res, int n)
//{
//    if(n <= 64)
//    {
//        for(int i = 0; i < n; ++i)
//            for(int j = 0; j < n; ++j)
//                res[i + j] += a[i] * b[j];
//    }
//    else
//    {
//        int mid = n / 2;
//        int atmp[n], E[n] = {};
//        auto btmp = atmp + mid;
//
//        for(int i = 0; i < mid; ++i)
//        {
//            atmp[i] = a[i] + a[i + mid];
//            btmp[i] = b[i] + b[i + mid];
//        }
//
//        mul(atmp, btmp, E, mid);
//        mul(a, b, res, mid);
//        mul(a + mid, b + mid, res + n, mid);
//
//        for(int i = 0; i < mid; ++i)
//        {
//            int tmp = res[i + mid];
//            res[i + mid] += E[i] - res[i] - res[i + 2 * mid];
//            res[i + 2 * mid] += E[i + mid] - tmp - res[i + 3 * mid];
//        }
//    }
//}

void mul(vi const& a, vi const& b, vi& res, int n)
{
    if(n <= 2)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                res[i + j] += a[i] * b[j];
    }
    else
    {
        int mid = (n / 2);

        vi atmp(mid), btmp(n - mid), E(n), r0(n), r2(n);

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

using cd = complex<double>;

const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

void mul(vi& a, vi& b, vi& res)
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
    for(int i = 0, t = 0; i < n; ++i, t /= 10)
        res[i] = (t += round(fa[i].real())) % 10;
}

//void normalize(int* a, int n)
//{
//    int t = 0;
//    for(int i = 0; i < n; ++i, t /= 10)
//        a[i] = (t += a[i]) % 10;
////    while(t)a[n ++] = t, t /= 10;
//}

int main()
{
    int x, y, n;
    cin >> x >> y;

//    int a[n];
//    for(int i = 0; i < n; ++i, x /= 10)a[i] = x % 10;
//    int b[n];
//    for(int i = 0; i < n; ++i, y /= 10)b[i] = y % 10;
//    int res[2 * n];
//    for(int i = 0; i < 2 * n; ++i)res[i] = 0;
//
//
//    mul(a, b, res, n);
//    normalize(res, 2 * n);
//
//    for(int i = 0; i < 2 * n; ++i)cout << res[i] << '\n';

    vi a(n);
    for(int i = 0; i < n; ++i, x /= 10)a[i] = x % 10;
    vi b(n);
    for(int i = 0; i < n; ++i, y /= 10)b[i] = y % 10;
    vi res;

    mul(a, b, res);

    for(int i = 0; i < res.size(); ++i)cout << res[i] << '\n';
    return 0;
}
