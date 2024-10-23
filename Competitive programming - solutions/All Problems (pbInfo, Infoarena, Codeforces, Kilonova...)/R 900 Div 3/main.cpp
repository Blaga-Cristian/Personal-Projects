#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct custom_hash_pair {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(pair<uint64_t,uint64_t> x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};

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
using vvvi = vector<vvi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define FORN(i, n) for(int i = 0; i < n; ++i)
#define umap unordered_map
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define ar array
inline void yn(bool b)
{
    if(b==true)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
  inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

ll Mod;

template <typename T> struct Fenwick {
    vector<T> a;
    int n;
    Fenwick(): a(),n(0) {}
    Fenwick(int _n){
        n = _n;
        a = vector<T>(n, T());
    }
    void clear(){
    a = vector<T>(n,T());
    }
    void add(int p, T x){
    for(;p < n ; p |= p+1)
        a[p] += x;
    }
    T get(int p){
    if(p < 0 ) return T();
    p = min(p,n-1);
    T res = T();
    for(;p >= 0 ; p  = (p & (p+1)) - 1)
        res += a[p];
    return res;
    }
    T getSum(int l,int r){
    return get(r-1) - get(l-1);
    }
};

template<typename T> struct SegmentProd{
    vector<T> adi;
    int n;
    SegmentProd(): adi(), n(0) {}
    SegmentProd(int _n){
        n=_n;
        adi = vector<T>(4*n, (T)1);
    }
    void clear(){
    adi = vector<T>(4*n,(T)1);
    }
    void update(int poz,ll val){
        updateintern(1,1,n,poz,val);
    }
    ll query(int st,int dr){
        return (queryintern(1,1,n,st,dr) % Mod);
    }

    ll queryintern(int nod,int st,int dr,int ST,int DR)
    {
        if(st>=ST && dr<=DR) return adi[nod] % Mod;
        int mij = (st+dr)/2;
        ll a=1,b=1;
        if(mij >= ST)
            a = queryintern(2*nod,st,mij,ST,DR);
        if(mij<DR)
            b = queryintern(2*nod+1,mij+1,dr,ST,DR);
        return (a*b)%Mod;
    }

    void updateintern(int nod,int st,int dr,int poz,ll val)
    {
        if(st==dr)
            {adi[nod] = val;
            return;}
        ll mij = (st+dr)/2;
        if(poz <= mij)
            updateintern(2*nod,st,mij,poz,val);
        else updateintern(2*nod+1,mij+1,dr,poz,val);
        if(st!=dr)
        adi[nod] = (adi[2*nod] * adi[2*nod+1]) % Mod;
    }
};

template <typename T> struct SegmentSum{
    vector<T> adi;
    int n;
    SegmentSum(): adi(), n(0) {}
    SegmentSum(int _n){
    n = _n;
    adi = vector<T>(4*n,(T)0);
    }
    void clear(){
    adi = vector<T>(4*n,0);
    }
    void update(int poz,int val){
    updateintern(1,1,n,poz,val);
    }
    void updateintern(int nod,int st,int dr,int poz,int val)
    {
        if(st==dr){
            adi[nod] = val;
            return;
        }
        int mij = (st+dr)/2;
        if(poz<=mij)
            updateintern(2*nod,st,mij,poz,val);
        else updateintern(2*nod+1,mij+1,dr,poz,val);
        if(st!=dr)
        adi[nod] = (adi[2*nod] + adi[2*nod+1]) % Mod;
    }
    ll query(int st,int dr){
    return queryintern(1,1,n,st,dr);
    }
    ll queryintern(int nod,int st,int dr,int ST,int DR){
    if(st>=ST && dr<=DR) return adi[nod];
    ll a = 0, b = 0;
    ll mij = (st+dr)/2;
    if(mij >= ST) a = queryintern(2*nod,st,mij,ST,DR);
    if(mij < DR) b = queryintern(2*nod+1,mij+1,dr,ST,DR);
    return a+b;
    }
};

const string TASK("trie");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll Nmax = 2e5+9;
int LN = 20, LV = 30;

int n, q;
vvi G(Nmax);

vi a, dep;
vvi t, bor, first;
vvvi last;

//int t[Nmax][LN], bor[Nmax][LN], first[Nmax][LV], last[Nmax][LN][LV], dep[Nmax];
/// last[x][k][bit] = dep ultimului nod pe care se afla bitul bit
/// first[x][bit] = prima poz pe care apare bit

void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;

    t[x][0] = p;
    bor[x][0] = a[x];
    FOR(bit, 0, LV - 1)if(a[x] & (1 << bit))last[x][0][bit] = dep[x];
    FOR(bit, 0, LV - 1)if(a[x] & (1 << bit))first[x][bit] = dep[x];

    FOR(k, 1, min(LN - 1, (int)log2(dep[x])))
    {
        t[x][k] = t[t[x][k - 1]][k - 1];
        bor[x][k] = bor[x][k - 1] | bor[t[x][k - 1]][k - 1];
        FOR(bit, 0, LV - 1)last[x][k][bit] = min(last[x][k - 1][bit], last[t[x][k - 1]][k - 1][bit]);
        FOR(bit, 0, LV - 1)first[x][bit] = max(first[x][bit], first[t[x][k - 1]][bit]);
    }

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);
}

int get_lca(int x, int y)
{
    if(x == y)return x;

    if(dep[x] < dep[y])swap(x, y);

    for(int k = min(LN - 1, (int)log2(dep[x])); k >= 0; --k)
        if(dep[x] - (1 << k) >= dep[y])
            x = t[x][k];

    if(x == y)return x;

    for(int k = min(LN - 1, (int)log2(dep[x])); k >= 0; --k)
        if(t[x][k] != t[y][k])
        {
            x = t[x][k];
            y = t[y][k];
        }

    return t[x][0];
}

vpi v;
void operations(int x, int y, int lca, int& ret)
{
    v.clear();

    int ory = 0;
    for(int k = min(LN - 1, (int)log2(dep[y])), nod = y; k >= 0; --k)
        if(dep[nod] - (1 << k) >= dep[lca])
        {
            ory |= bor[nod][k];
            nod = t[nod][k];
        }

    for(int bit = 0; bit < LV; ++bit)
        if(first[x][bit] >= dep[lca])
            v.pb({first[x][bit], 1});

    for(int bit = 0; bit < LV; ++bit)
    {
        if((ory & (1 << bit)) != 0)continue;

        int p = Inf;
        for(int k = min(LN - 1, (int)log2(dep[x])), nod = x; k >= 0; --k)
            if(dep[nod] - (1 << k) >= dep[lca])
            {
                p = min(p, last[nod][k][bit]);
                nod = t[nod][k];
            }
        if(a[lca] & (1 << bit))p = dep[lca];
        if(p != Inf)
        {
            ory |= (1 << bit);
            v.pb({p - 1, -1});
        }
    }

    sort(all(v), greater<pii>());
    int nr = __builtin_popcount(ory);

    ret = max(ret, nr);

    for(int i = 0; i < v.size();)
    {
        int j = i;
        while(j < v.size() && v[i].ff == v[j].ff)nr += v[j++].ss;
        i = j;

        ret = max(ret, nr);
    }
}

int query(int x, int y)
{
    int lca = get_lca(x, y);
    int ret = -Inf;

    operations(x, y, lca, ret);
    operations(y, x, lca, ret);

    return ret;
}

void solve_testcase()
{
    cin >> n;

    a = vi(n + 1);
    FOR(i, 1, n)cin >> a[i];

    FOR(i, 0, n)G[i].clear();
    int u, v;
    FOR(i, 2, n)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    LN = log2(n) + 1;
    int mx = 0;FOR(i, 1, n)mx = max(mx, a[i]);
    LV = log2(mx) + 1;

    dep = vi(n + 1, 0);
    t = bor = vvi(n + 1, vi(LN + 2));
    first = vvi(n + 1, vi(LN + 2, -Inf));
    last = vvvi(n + 1, vvi(LN + 2, vi(LV + 2, Inf)));
    Dfs();


    cin >> q;
    int x, y;
    while(q --)
    {
        cin >> x >> y;
        cout << query(x, y) << ' ';
    }

    cout << '\n';
}

/// Check for interruption of input!!

int main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
