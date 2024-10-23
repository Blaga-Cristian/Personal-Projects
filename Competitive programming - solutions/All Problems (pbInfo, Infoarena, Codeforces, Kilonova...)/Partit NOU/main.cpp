#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pi pair<int, int>
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vpi vector<pi>
#define vvpi vector<vpi>
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;
const string TASK("partit");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 10009;

ll c, n, k;

int main()
{
    cin >> c >> n;

    if(c == 1)
    {
        cin >> k;

        k --;

        vl ans;
        ll sum = n;

        while(sum > 60)ans.pb(1), sum--;

        while(sum > 0)
        {
            ll a = 0;

            for(int i = 1; i <= sum; ++i)
            {
                ll nr = ((1ULL << (sum - 1)) - 1) ^ ((1ULL << (sum - i)) - 1);

                if(nr <= k)a = i;
                else break;
            }

            k -= ((1ULL << (sum - 1)) - 1) ^ ((1ULL << (sum - a)) - 1);
            sum -= a;
            ans.pb(a);
        }

        for(auto i : ans)cout << i << ' ';
        cout << '\n';
    }
    else
    {
        vl p;
        ll sum = 0, x;
        while(sum < n)
        {
            cin >> x;
            p.pb(x);
            sum += x;
        }

        ll ord = 0;
        for(auto i : p)
        {
            ll nr = ((1LL << (sum - 1)) - 1) ^ ((1LL << (sum - i)) - 1);
            sum -= i;
            ord += nr;
        }

        cout << ord + 1 << '\n';
    }
    return 0;
}
