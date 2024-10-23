#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 9;

int n;

struct info
{
    int c, t;
    bool operator < (info const& a) const noexcept
    {
        return c < a.c;
    }
}task[N];

int tmax;
priority_queue<info> q;
bool timp[N];

int main()
{
    freopen("credite.in", "r", stdin);
    freopen("credite.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> task[i].c >> task[i].t;
        timp[task[i].t] = true;
        tmax = max(tmax, task[i].t);
    }

    int ans = 0;
    for(int i = tmax; i >= 1; --i)
    {
        if(timp[i])
            for(int j = 1; j <= n; ++j)
                if(task[j].t == i)
                    q.push(task[j]);

        if(!q.empty())
        {
            ans += q.top().c;
            q.pop();
        }
    }

    cout << ans;
    return 0;
}
