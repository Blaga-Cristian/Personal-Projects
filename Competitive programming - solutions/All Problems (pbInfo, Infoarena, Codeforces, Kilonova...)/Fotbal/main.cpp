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
#define vvpi vector<vpi>

using namespace std;
const string TASK("fotbal");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;

int n, m, x[N], y[N];
int scor[N];
bool viz[N], seen[N];
int ans[N];
vvpi G(N);

vi sir;
void Dfs(int x)
{
    seen[x] = true;

    while(!G[x].empty())
    {
        int y = G[x].back().ff, i = G[x].back().ss;
        G[x].pop_back();

        if(!viz[i])
        {
            viz[i] = true;
            ans[i] = x;
            Dfs(y);
        }
    }
    sir.pb(x);
}

map<pii, int> mp;

int main()
{
    cin >> n >> m;

    FOR(i, 1, m)
    {
        cin >> x[i] >> y[i];
        G[x[i]].pb({y[i], i});
        G[y[i]].pb({x[i], i});
//        mp[{x[i], y[i]}] = mp[{x[i], y[i]}] = i;
    }

    int prv = -1, id = m + 1;
    FOR(i, 1, n)
        if(G[i].size() % 2 == 1)
        {
            if(prv == -1)prv = i;
            else
            {
//                mp[{i, prv}] = mp[{prv, i}] = id;
                G[prv].pb({i, id});
                G[i].pb({prv, id ++});
                prv = -1;
            }
        }

    FOR(i, 1, n)
    {
        if(!seen[i])
        {
            sir.clear();
            Dfs(i);
//            for(int i = 0; i + 2 < sir.size(); ++i)
//            {
//                cout << sir[i] << ' ' << sir[i + 1] << ' ' << mp[{sir[i], sir[i + 1]}] << '\n';
//                ans[mp[{sir[i], sir[i + 1]}]] = sir[i];
//            }
        }
    }

    FOR(i, 1, m)
    {
        if(ans[i] == x[i])
        {
            scor[x[i]] ++;
            scor[y[i]] --;
        }
        else
        {
            scor[x[i]] --;
            scor[y[i]] ++;
        }
    }

    int mn = INT_MAX, mx = INT_MIN;
    FOR(i, 1, n)
    {
        mn = min(mn, scor[i]);
        mx = max(mx, scor[i]);
    }

    cout << mx - mn << '\n';
    FOR(i, 1, m)cout << ans[i] << '\n';
    return 0;
}
