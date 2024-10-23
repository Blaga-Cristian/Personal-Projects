#include <bits/stdc++.h>
//#include <bits/extc++.h>
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
#define ll long long
#define double long double
#define eb emplace_back
#define lo(x) (2 * (x) - 1)
#define up(x) (2 * (x))
//#define int long long
using namespace std;
//using namespace __gnu_pbds;
const string TASK("ahocorasick");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e6 + 9, M = 10009, Al = 30;

int n, v[N][Al], f[N], NEXT_FREE_INDEX = 1, pd[N], ans[111];
char a[N], s[M];
vi ad[N];

void Add(int poz)
{
    int nod = 0;
    for(int i = 0; s[i]; ++i)
    {
        if(!v[nod][s[i] - 'a'])v[nod][s[i] - 'a'] = NEXT_FREE_INDEX ++;
        nod = v[nod][s[i] - 'a'];
    }
    ad[nod].pb(poz);
}

void BuildSuffix()
{
    queue<int> q;
    for(int i = 0; i < 26; ++i)
        if(v[0][i])
            q.push(v[0][i]);

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        for(int i = 0; i < 26; ++i)
            if(v[nod][i])
            {
                int ant = f[nod];
                while(ant != 0 && v[ant][i] == 0)ant = f[ant];

                if(v[ant][i])
                {
                    f[v[nod][i]] = v[ant][i];
                    for(auto x : ad[v[ant][i]])
                        ad[v[nod][i]].pb(x);
                }

                q.push(v[nod][i]);
            }
    }
}

int main()
{
    cin >> a;
    cin >> n;

    FOR(i, 1, n)
    {
        cin >> s;
        Add(i);
    }

    BuildSuffix();

    int nod = 0;
    for(int i = 0; a[i]; ++i)
    {
        while(nod != 0 && v[nod][a[i] - 'a'] == 0)
            nod = f[nod];
        nod = v[nod][a[i] - 'a'];
        ++ pd[nod];
    }

    for(int nod = 0; nod < NEXT_FREE_INDEX; ++nod)
        if(pd[nod])
            for(auto x : ad[nod])
                ans[x] += pd[nod];

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}