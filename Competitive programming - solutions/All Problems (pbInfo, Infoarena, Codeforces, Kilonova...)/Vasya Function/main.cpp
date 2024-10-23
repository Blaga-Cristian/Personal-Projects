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

using namespace std;


int gcd(int a, int b)
{
    int aux;
    while(b)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}


int f(int a, int b)
{
    int g = gcd(a, b);
    if(g != 1)return f(a / g, b / g);
    if(a == 1)return b;
    if(b == 1)return 1;

    int mx = 0;
    for(int d = 1; d * d <= a; ++d)
        if(a % d == 0)
        {
            if(b % d != 0)mx = max(mx, b - (b % d));
            if(d != a / d && b % (a / d) != 0)mx = max(mx, b - (b % (a / d)));
        }

    return b - mx + f(a, mx);
}

signed main()
{
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
    return 0;
}
