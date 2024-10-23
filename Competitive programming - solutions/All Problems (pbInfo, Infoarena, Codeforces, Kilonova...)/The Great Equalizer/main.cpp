#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 9, Inf = 0x3f3f3f3f;

int n, q, a[N], x, val;
multiset<int> arr, diffs;

void solve()
{
    diffs.clear();
    arr.clear();

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(i > 1)diffs.insert(a[i] - a[i - 1]);
        arr.insert(a[i]);
    }

    cin >> q;
    while(q --)
    {
        cin >> x >> val;

        auto it = arr.find(a[x]), prv = it, nxt = it;
        prv --, nxt ++;

        if(it == arr.begin())diffs.erase(diffs.find(*nxt - *it));
        else if(it == --arr.end())diffs.erase(diffs.find(*it - *prv));
        else
        {
            diffs.erase(diffs.find(*nxt - *it));
            diffs.erase(diffs.find(*it - *prv));
            diffs.insert(*nxt - *prv);
        }

        arr.erase(it);
        arr.insert(val);

        it = arr.find(val);
        prv = it;
        nxt = it;
        prv --, nxt ++;

        if(it == arr.begin())diffs.insert(*nxt - *it);
        else if(it == --arr.end())diffs.insert(*it - *prv);
        else
        {
            diffs.insert(*nxt - *it);
            diffs.insert(*it - *prv);
            diffs.erase(diffs.find(*nxt - *prv));
        }

        a[x] = val;

        cout << *arr.rbegin() + *diffs.rbegin() << ' ';
    }

    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
