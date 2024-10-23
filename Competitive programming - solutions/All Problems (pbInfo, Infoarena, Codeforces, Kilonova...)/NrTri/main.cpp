#include <bits/stdc++.h>

using namespace std;
const int N = 809;

int n, a, b, c, x, y, v[N];
int ans;

multiset<int> s;

int main()
{
    freopen("nrtri.in", "r", stdin);
    freopen("nrtri.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    for(auto it : s)cout << it << ' ';
    cout << '\n';

    for(int i = 1; i <= n; ++i)
    {
        s.erase(s.find(v[i]));
        for(int j = i + 1; j <= n; ++j)
        {
            s.erase(s.find(v[j]));
            a = v[i], b = v[j];

            int idx = distance(s.begin(), --s.lower_bound(a + b));
            int l1 = distance(s.begin(), --s.lower_bound())
            auto it = s.begin();
            for(int k = 1; k <= idx; ++k)it++;
            cout << a << ' ' << b << ' ' << *it << '\n';

            ans += idx;

            s.insert(v[j]);
        }
        s.insert(v[i]);
    }

    cout << ans;
    return 0;
}
