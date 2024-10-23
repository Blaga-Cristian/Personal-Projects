#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const int N = 100;

bitset<N> v[N];

int main()
{
    int n;
    cin >> n;
    FOR(i, 0, n - 1)v[i][i] = 1;

    FOR(i, 0, 160)
    {
        FOR(i, 0, n)cout << v[0][i] << ' ';
        cout << '\n';
        FOR(i, 0, n - 1)v[i] ^= v[i + 1];
    }
    return 0;
}
