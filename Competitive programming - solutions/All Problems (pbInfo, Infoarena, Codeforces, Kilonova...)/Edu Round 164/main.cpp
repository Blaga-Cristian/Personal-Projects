#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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
using vvpi = vector<vpi>;
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



//#define int long long
const string TASK("trie");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const ll N = 1e5 + 1, BUCKET = N;

int n, a[N];
vvpi upd(N);

int block[N / BUCKET + 1], act[N];
void Update(int p, int v)
{
    int l = act[p - 1], r = act[p + 1], id = p / BUCKET;
    if((p - 1) / BUCKET != p / BUCKET)l = 0;
    if((p + 1) / BUCKET != p / BUCKET)r = 0;

    if(l < act[p])block[id] -= act[p] - l;
    if(act[p] < r)block[id] -= r - act[p];

    act[p] = v;
    if(l < act[p])block[id] += act[p] - l;
    if(act[p] < r)block[id] += r - act[p];
}

int Query()
{
    int ans = block[0];
    for(int i = BUCKET; i <= n; i += BUCKET)
    {
        ans += block[i / BUCKET];
        ans -= act[i];
        if(act[i - 1] < act[i])ans += act[i] - act[i - 1];
    }
    return ans;
}

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    ///DECOMPUNERE IN RADICAL

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1, la; j <= a[i]; j = la + 1)
        {
            la = a[i] / (a[i] / j);

            if(a[i] % la == 0)
            {
                upd[la].pb({i, a[i] / la});///el de pe poz 1 ia val a[i] / la
                if(j != la)upd[j].pb({i, (a[i] + j - 1) / j});
            }
            else upd[j].pb({i, (a[i] + j - 1) / j});
        }
    }

//    for(int i = 0; i < upd.size(); ++i)
//    {
//        if(upd[i].size())
//        {
//            cout << "In vector " << i << ": ";
//            for(auto j : upd[i])cout << j.ff << ',' << j.ss << ' ';
//            cout << '\n';
//        }
//    }

    int mx = 0;
    FOR(i, 1, n)mx = max(mx, a[i]);

    for(int i = 1; i <= mx; ++i)
    {
        for(auto [p, v] : upd[i])
            Update(p, v);

        cout << Query() << ' ';
    }
    cout << '\n';
}

/// Check for interruption of input!!

signed main() {
    int t=1;
    if (false) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
