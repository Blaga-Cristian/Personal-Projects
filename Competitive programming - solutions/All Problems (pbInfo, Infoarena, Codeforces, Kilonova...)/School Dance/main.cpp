#include <bits/stdc++.h>

using namespace std;
const int N = 509;

int n, m, k, L[N], R[N], a, b;
vector<vector<int>> G;
bitset<N> v;

bool DoMatch(int x)
{
    if(v[x])return false;

    v[x] = true;

    for(auto y : G[x])
        if(!R[y])
        {
            L[x] = y;
            R[y] = x;
            return true;
        }

    for(auto y : G[x])
        if(DoMatch(R[y]))
        {
            L[x] = y;
            R[y] = x;
            return true;
        }

    return false;
}

int MaxMatch()
{
    int ret = 0;
    bool found_path = true;
    do
    {
        found_path = false;
        v.reset();

        for(int i = 1; i <= n; ++i)
            if(!L[i] && DoMatch(i))
            {
                found_path = true;
                ret++;
            }
    }while(found_path);
    return ret;
}




int main()
{
    cin >> n >> m >> k;
    G = vector<vector<int>>(n + 1);
    while(k --)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    cout << MaxMatch() << '\n';
    for(int i = 1; i <= n; ++i)
        if(L[i])
            cout << i << ' ' << L[i] << '\n';
    return 0;
}
