#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const string TASK("virus");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1009, L = 1000009, Al = 2;

int l, n, t[L][Al], f[L], ans[N], dp[L], NEXT_FREE_INDEX = 1;
vi ad[L];
char s[L], a[N];

void Add(int x)
{
    int nod = 0;
    for(int i = 0; a[i]; ++i)
    {
        if(!t[nod][a[i] - '0'])t[nod][a[i] - '0'] = NEXT_FREE_INDEX ++;
        nod = t[nod][a[i] - '0'];
    }
    ad[nod].pb(x);
}

void Build_Suffix()
{
    queue<int> q;
    FOR(i, 0, 1)
        if(t[0][i])
            q.push(t[0][i]);

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        FOR(i, 0, 1)
            if(t[nod][i])
            {
                int ant = f[nod];
                while(ant != 0 && t[ant][i] == 0)ant = f[ant];

                if(t[ant][i])
                {
                    f[t[nod][i]] = t[ant][i];
                    for(auto x : ad[t[ant][i]])
                        ad[t[nod][i]].pb(x);
                }

                q.push(t[nod][i]);
            }
    }
}

int main()
{
    cin >> l >> n;
    cin >> s;

    int x;
    FOR(i, 1, n)
    {
        cin >> x;
        cin >> a;
        Add(i);
    }

    Build_Suffix();

    int nod = 0;
    FOR(i, 0, l - 1)
    {
        while(nod != 0 && t[nod][s[i] - '0'] == 0)nod = f[nod];
        nod = t[nod][s[i] - '0'];
        dp[nod] ++;
    }

    FOR(i, 0, NEXT_FREE_INDEX - 1)
        for(auto x : ad[i])
            ans[x] += dp[i];

    FOR(i, 1, n)cout << ans[i] << '\n';
    return 0;
}
