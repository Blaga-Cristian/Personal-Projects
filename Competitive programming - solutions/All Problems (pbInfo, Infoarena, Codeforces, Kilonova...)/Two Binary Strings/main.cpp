#include <bits/stdc++.h>

using namespace std;
const int N = 5009;
bool match[N];
string a, b;

void solve()
{
    memset(match, 0, sizeof(match));
    cin >> a >> b;

    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] != b[i])continue;
        for(int j = i; j > 0; --j)
            if(match[j - 1] && a[j] == b[j] && a[j] == a[i])
                match[i] = true;
        if(a[0] == b[0] && a[0] == a[i])
            match[i] = true;
    }

    if(match[a.size() - 1])cout << "YES\n";
    else cout << "NO\n";
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
