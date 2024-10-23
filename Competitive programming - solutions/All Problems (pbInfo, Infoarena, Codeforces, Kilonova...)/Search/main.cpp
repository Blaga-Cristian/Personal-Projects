#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define all(v) (v).begin(), (v).end()
#define ll long long


using namespace std;
const string TASK("search");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 109, Ms = 200009, L = 5009, P = 211, M = 1e9 + 123, Al = 26;

int n, m;
char s[N][L], op[Ms], sir[Ms], sz;
int nxt[N][L][30];
int ans, p[N];

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= M)x -= M;
    if(x < 0)x += M;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * y) % M;
}

ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

int main()
{
    cin >> n >> m;

    FOR(i, 1, n)cin >> s[i];
    FOR(i, 1, m)cin >> op[i];

    FOR(i, 1, n)
    {
        int l = strlen(s[i]);
        FORR(j, l - 2, 0)
            FOR(k, 0, 25)
            {
                nxt[i][j][k] = nxt[i][j + 1][k];
                if(s[i][j + 1] - 'a' == k)nxt[i][j][k] = j + 1;
            }
    }

    int ans = 0;
    char c;
    stack<pii> stk;
    stack<int> aux;
    aux.push(0);

    FOR(i, 1, n)
    {
        p[i] = -1;
        if(s[i][0] == op[1])p[i] = 0;
        else if(nxt[i][0][op[1] - 'a'])p[i] = nxt[i][0][op[1] - 'a'];

        if(p[i] != -1)ans ++;
    }

    cout << ans << '\n';
    FOR(i, 2, m)
    {
        if(op[i] == '-')
        {
            int sz = aux.top();
            aux.pop();

            while(stk.size() != sz)
            {
                int ind = stk.top().ff, v = stk.top().ss;
                if(p[ind] == -1)ans ++;
                p[ind] = v;
                stk.pop();
            }
        }
        else
        {
            int sz = stk.size();
            aux.push(sz);

            FOR(j, 1, n)
            {
                if(p[j] == -1)continue;

                if(nxt[j][p[j]][op[i] - 'a'])
                {
                    stk.push({j, p[j]});
                    p[j] = nxt[j][p[j]][op[i] - 'a'];
                }
                else
                {
                    stk.push({j, p[j]});
                    ans --;
                    p[j] = -1;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
