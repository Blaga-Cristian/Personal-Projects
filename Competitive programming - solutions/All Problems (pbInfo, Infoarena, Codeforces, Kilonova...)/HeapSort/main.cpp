#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 9;
const int Inf = 1e5;

mt19937 rnd;
int n, a[N];

int get(int p)
{
    if(p > n)return -Inf;
    return a[p];
}

void down(int p)
{
    if(p > n ||
       a[p] >= max(get(2 * p), get(2 * p + 1)))return;

    if(get(2 * p) > get(2 * p + 1))
    {
        swap(a[p], a[2 * p]);
        down(2 * p);
    }
    else
    {
        swap(a[p], a[2 * p + 1]);
        down(2 * p + 1);
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
        a[i] = rnd() % n;

    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n';

    for(int i = n; i >= 1; --i)
        down(i);

    int nr = n;
    while(n > 1)
    {
        swap(a[1], a[n]);
        -- n;
        down(1);
    }

    for(int i = 1; i <= nr; ++i)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
