#include <bits/stdc++.h>
#define ll long long
using namespace std;
const string TASK("maxxor2");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9, LG = 63;

int n;

ll sz = 0, basis[LG];
void insert_vector(ll x)
{
    for(int i = LG - 1; i >= 0; --i)
        if(x & (1LL << i))
        {
            if(!basis[i])
            {
                basis[i] = x;
                break;
            }

            x ^= basis[i];
        }
}

ll get_max()
{
    ll ret = 0;
    for(int i = LG - 1; i >= 0; --i)
        if(!(ret & (1LL << i)))
            ret ^= basis[i];
    return ret;
}

int main()
{
    cin >> n;

    ll x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        insert_vector(x);
    }

    cout << get_max() << '\n';
    return 0;
}
