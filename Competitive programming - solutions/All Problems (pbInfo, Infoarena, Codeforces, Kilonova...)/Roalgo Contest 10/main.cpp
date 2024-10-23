//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define allg(x) (x).begin(), (x).end(), greater<int>()
using ull = unsigned long long;
using ll =  long long;
using ld = double;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using si = set<int>;
using ssi = set<si>;
using sl = set<ll>;
using ssl = set<sl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define umap unordered_map
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define ar array

bool testCase = false;
const int N = 1e5 + 9, Mod = 998244353;

int k, n, q;
char a[N], s[N];

void Next();
void get_char(char&);
void get_int(int&);

struct query
{
    int l, r, ind, ans;
};
vector<query> qs;

//int add(int x, int y)
//{
//    int res = x + y;
//    if(res > Mod)res -= Mod;
//    if(res < 0)res += Mod;
//    return res;
//}

int pos[30];
int dp[30][30];

inline void AddF(int i)
{
    int p = pos[s[i - 1] - 'a'];
    dp[p][p] ++;
    if(dp[p][p] == Mod)dp[p][p] -= Mod;
    for(int i = 0; i < p; ++i)
    {
        dp[i][p] += dp[i][p - 1];
        if(dp[i][p] >= Mod)dp[i][p] -= Mod;
    }
}
inline void RemF(int i)
{
    int p = pos[s[i - 1] - 'a'];
    dp[p][p] --;
    if(dp[p][p] < 0)dp[p][p] += Mod;
    for(int i = 1; i < p; ++i)
    {
        dp[i][p] -= dp[i][p - 1];
        if(dp[i][p] < 0)dp[i][p] += Mod;
    }
}
inline void AddB(int i)
{
    int p = pos[s[i - 1] - 'a'];
    dp[p][p] ++;
    if(dp[p][p] >= Mod)dp[p][p] -= Mod;
    for(int i = p + 1; i <= k; ++i)
    {
        dp[p][i] += dp[p + 1][i];
        if(dp[p][i] >= Mod)dp[p][i] -= Mod;
    }
}
inline void RemB(int i)
{
    int p = pos[s[i - 1] - 'a'];
    dp[p][p] --;
    if(dp[p][p] < 0)dp[p][p] += Mod;
    for(int i = p + 1; i <= k; ++i)
    {
        dp[p][i] -= dp[p + 1][i];
        if(dp[p][i] < 0)dp[p][i] += Mod;
    }
}

void solve_testcase()
{
    Next();

    get_int(k), get_int(n);
    FOR(i, 0, k - 1)get_char(a[i]);
    FOR(i, 0, n - 1)get_char(s[i]);

    FOR(i, 0, k - 1)pos[a[i] - 'a'] = i + 1;

    get_int(q);
    qs.resize(q);
    FOR(i, 0, q - 1)
    {
        get_int(qs[i].l), get_int(qs[i].r);
        qs[i].ind = i;
        qs[i].ans = -1;
    }

    int BLOCK = sqrt(n);
    sort(qs.begin(), qs.end(), [&](query a, query b)
         {
             return (a.l / BLOCK == b.l / BLOCK) ? a.r < b.r : a.l < b.l;
         });


    int st = 1, dr = 0;
    for(auto& e : qs)
    {
        while(dr < e.r)AddF(++ dr);
        while(st > e.l)AddB(-- st);
        while(dr > e.r)RemF(dr --);
        while(st < e.l)RemB(st ++);

        e.ans = dp[1][k];
    }

    sort(qs.begin(), qs.end(), [](query a, query b)
         {
             return a.ind < b.ind;
         });

    for(auto e : qs)cout << e.ans << '\n';
}

/// Check for interruption of input!!

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//     cout.tie(0);
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}


const int Lim = 1e6;
char buff[Lim];
int p = Lim - 1;

void Next()
{
    if(++ p == Lim)
    {
        fread(buff, 1, Lim, stdin);
        p = 0;
    }
}
void get_char(char& c)
{
    while(!isalpha(buff[p]))Next();
    c = buff[p];
    Next();
}
void get_int(int& x)
{
    while(buff[p] < '0' || buff[p] > '9')Next();

    for(x = 0; buff[p] >= '0' && buff[p] <= '9'; Next())
        x = x * 10 + buff[p] - '0';
}
