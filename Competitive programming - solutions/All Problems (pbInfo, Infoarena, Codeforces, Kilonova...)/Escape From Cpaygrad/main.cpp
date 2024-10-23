#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <random>
#include <unordered_set>
#include <chrono>

using namespace std;

#define all(a) a.begin(), a.end()

void solve() {
    int n;
    cin >> n;

    vector<int> ans(n);
    vector<tuple<int, int, int>> events;
    for (int i = 0 ; i < n ; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ans[i] = b;
        events.emplace_back(b, 1, i);
        events.emplace_back(l, -1, i);
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0 ; i < q ; i++) {
        int x;
        cin >> x;
        queries[i] = x;
        events.emplace_back(x, 0, i);
    }

    sort(all(events));
    reverse(all(events));
    multiset<int> s;
    for (auto [x, type, ind] : events) {
        if (type == 1) {
            if (!s.empty()) {
                ans[ind] = *s.rbegin();
            }
            s.insert(ans[ind]);
        } else if (type == 0) {
            if (!s.empty()) {
                queries[ind] = max(queries[ind], *s.rbegin());
            }
        } else {
            s.extract(ans[ind]);
        }
    }

    for (auto el : queries)
        cout << el << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
