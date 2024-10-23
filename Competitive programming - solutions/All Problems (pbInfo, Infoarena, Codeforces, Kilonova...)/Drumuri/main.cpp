#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>

using namespace std;
const int N = 5009;

int n, m, id[N];
int gr[N];
vvi G(N);

int main()
{
    cin >> n >> m;

    FOR(i, 1, n)
    {
        id[i] = i;
        G[i].pb(i);
    }

    int x, y;
    FOR(i, 1, n)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;

            if(id[x] != id[y] && gr[x] == 1 && gr[y] == 1)
            {
                if(x == id[x] && y == id[y])
                {
                    reverse(G[id[x]].begin(), G[id[x]].end());
                    for(auto)
                }
            }
        }
    }
    return 0;
}
