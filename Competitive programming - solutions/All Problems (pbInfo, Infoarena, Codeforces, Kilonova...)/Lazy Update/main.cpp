#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2 * 1e5 + 9;
int n, q, a, b, u, op, k;
ll t[2 * N];

void Build()
{
    for(int i = 1; i <= n ; ++i)cin >> t[n - 1 + i];
    //for(int i = n - 1; i; --i)tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void Update(int l, int r, int val)
{
    for(l += (n - 1), r += (n - 1); l <= r; l >>= 1, r >>= 1)
    {
        if(l&1)t[l++] += val;
        if(!(r&1))t[r--] += val;
    }
}
ll Query(int poz)
{
    ll ret = 0;
    for(poz += (n - 1); poz; poz >>= 1)
        ret += t[poz];
    return ret;
}


int main()
{
    cin >> n >> q;
    Build();
    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> a >> b >> u;
            Update(a, b, u);
        }
        else
        {
            cin >> k;
            cout << Query(k) << '\n';
        }
    }
    return 0;
}
