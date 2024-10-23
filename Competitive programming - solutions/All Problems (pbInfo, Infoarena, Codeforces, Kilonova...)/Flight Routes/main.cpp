#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2509;
const ll Inf = LLONG_MAX >> 1;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;

int n, m, a, b, c;
VVPI G;
vector<ll> d;
bool bucla = false;

void Bellman()
{
    queue<int> q;
    bitset<N + 1> inq;
    vector<int> cnt(n + 1);
    vector<int> dinit(n + 1, Inf);

    q.push(1);
    d[1] = 0;
    dinit[1] = 0;
    inq[1] = true;
    cnt[1] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        inq[x] = false;

        for(auto i : G[x])
        {
            int y = i.F,
            w = i.S;

            if(d[y] >= d[x] + w || cnt[y] == n)continue;

            d[y] = d[x] + w;
            if(!inq[y])
            {
                q.push(y);
                inq[y] = true;
            }
            if(cnt[y] < n)cnt[y]++;
            if(cnt[y] == 1)dinit[y] = d[y];

            if(cnt[y] == n && d[y] > dinit[y])
                d[y] = Inf;
        }
    }

    bucla = d[n] >= Inf;
}

int main()
{
    cin >> n >> m;
    G = VVPI(n + 1);
    d = vector<ll>(n + 1, -Inf);

    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    int mx = 0;
    for(auto [y, c] : G[1])
        if(y == 1)
            mx = max(mx, c);

    if(mx > 0)
    {
        cout << "-1\n";
        return 0;
    }

    Bellman();

    if(bucla)
        cout << "-1";
    else
        cout << d[n];
    return 0;
}
