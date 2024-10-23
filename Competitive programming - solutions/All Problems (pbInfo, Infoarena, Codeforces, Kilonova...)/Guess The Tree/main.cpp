#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int N = 1009;

int n;
bool seen[N];
vector<pii> ans;

void Get_Path(int x, int y)
{
    seen[x] = seen[y] = true;

    cout << "? " << y << ' ' << x << endl;

    int a;
    cin >> a;

    if(a == y)
    {
        ans.push_back({x, y});
        return;
    }

    if(!seen[a])Get_Path(x, a);
    Get_Path(a, y);
}

void solve()
{
    cin >> n;

    ans.clear();
    seen[1] = true;
    for(int i = 2; i <= n; ++i)seen[i] = false;

    for(int i = 2; i <= n; ++i)
        if(!seen[i])
            Get_Path(1, i);

    cout << '!';
    for(auto [a, b] : ans)
        cout << ' ' << a << ' ' << b;
    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
