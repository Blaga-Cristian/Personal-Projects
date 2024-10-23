#include <iostream>
#define ll long long
using namespace std;

const ll Inf = 1LL << 62;

const int N = 2 * 1e5 + 9;
ll v[N];
ll n, a, b;
ll ans = -Inf;
ll cursum;
ll nec;
ll prefix;

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    for(int i = 1; i < a; ++i)
        nec += v[i];

    int st = 0, dr = a - 1;
    int lst = 1;
    while(dr < n)
    {
        nec += v[++dr];
        nec -= v[st++];

        if(dr - lst + 1 > b)
            prefix -= v[lst++];

        if(prefix < 0)
            prefix = 0,
            lst = st - 1;

        prefix += v[st - 1];


        if(dr - lst + 1 > b)
            prefix -= v[lst++];

        if(prefix < 0)
            prefix = 0,
            lst = st;

        while(v[lst] <= 0 && lst < st)
            prefix -= v[lst++];


        ans = max(ans, prefix + nec);
    }

    cout << ans;
    return 0;
}
