#include <bits/stdc++.h>

using namespace std;

int n,k;
pair<int,int> v[200006];
int cnt;

int main()
{
    cin >> n >> k;
    multiset<int> q;
    for(int i = 1; i <= k; ++i)
        q.insert(0);

    for(int i = 1; i <= n; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v + 1, v + n + 1, [](pair<int,int> a, pair<int,int> b){return a.second == b.second ? a.first > b.first : a.second < b.second;});

    for(int i = 1; i <= n; ++i)
    {
        if(q.lower_bound(v[i].first + 1) != q.begin())
        {
            auto it = q.lower_bound(v[i].first + 1);
            it--;
            q.erase(it);
            q.insert(v[i].second);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
