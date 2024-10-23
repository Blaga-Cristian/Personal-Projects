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

mt19937 rnd;

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
using vvpi = vector<vpi>;
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

ll Mod = 1999999973;

template <int MOD=998'244'353>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

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

#define int long long
const string TASK("biconex");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
//const int Inf = 0x3f3f3f3f;
const int Inf = LLONG_MAX;
bool testCase = false;
const ll N = 1e5 + 9, K = 11, LG = 21, M = 997689977;

int n, q, a[N];
vvi G(N);


struct node
{
    int v;///maintain sum
    node *l, *r;
};
node *root[N];

void Build(node* nod, int st = 1, int dr = 2 * n)
{
    nod -> v = 0;
    if(st == dr)return;
    int m = (st + dr) >> 1;
    Build(nod -> l = new node(), st, m);
    Build(nod -> r = new node(), m + 1, dr);
}

node* Update(int p, int v, node* nod, int st = 1, int dr = 2 * n)
{
    node* nnod = new node(*nod);
    if(st == dr)
    {
        nnod -> v = v;
        return nnod;
    }
    int m = (st + dr) >> 1;
    if(p <= m)nnod -> l = Update(p, v, nod -> l, st, m);
    else nnod -> r = Update(p, v, nod -> r, m + 1, dr);
    nnod -> v = (nnod -> l -> v + nnod -> r -> v) % M;
    return nnod;
}

int Query(int l, int r, node* nod, int st = 1, int dr = 2 * n)
{
    if(l <= st && dr <= r)return nod -> v;
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod -> l, st, m);
    else if(l > m)return Query(l, r, nod -> r, m + 1, dr);
    return (Query(l, r, nod -> l, st, m) + Query(l, r, nod -> r, m + 1, dr)) % M;
}

int ST[2 * N][LG], t[N], dep[N], tour[2 * N], sz, fst[N], lst[N];///need diff tour
int stour[2 * N], first[N], idx;
void Dfs(int x = 1, int p = 0)
{
    t[x] = p;
    dep[x] = dep[p] + 1;

    first[x] = ++idx;
    stour[idx] = x;

    fst[x] = ++sz;
    tour[sz] = x;

    for(auto y : G[x])
        if(y != p)
        {
            Dfs(y, x);
            stour[++ idx] = x;
        }

    lst[x] = ++sz;
    tour[sz] = x;
}

void Precalc()
{
    FOR(i, 1, 2 * n)ST[i][0] = stour[i];

    for(int k = 1; (1 << k) <= 2 * n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= 2 * n; ++i)
        {
            ST[i][k] = ST[i][k - 1];
            if(dep[ST[i][k - 1]] > dep[ST[i + (1 << (k - 1))][k - 1]])
                ST[i][k] = ST[i + (1 << (k - 1))][k - 1];
        }
}

int get_lca(int x, int y)
{
    x = first[x], y = first[y];
    int k = log2(y - x + 1);
    return dep[ST[x][k]] < dep[ST[y - (1 << k) + 1][k]] ? ST[x][k] : ST[y - (1 << k) + 1][k];
}

map<int, vi> hrt;

///NEED FAST LCA
int get_hsh(int u, int v, int lca, int val)///calcule
{
    int ret = (Query(1, fst[u], root[val]) + Query(1, fst[v], root[val])) % M;
    ret = (ret - Query(1, fst[lca], root[val]) + M) % M;
    if(lca == 1)return ret;
    lca = t[lca];
    ret = (ret - Query(1, fst[lca], root[val]) + M) % M;
    return ret;
}

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        hrt[a[i]].pb(i);
    }

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs();
    Precalc();
    root[0] = new node();
    Build(root[0]);
    FOR(i, 1, N - 1)
    {
        root[i] = root[i - 1];

        int hsh = i + (rnd() % M);
        for(auto x : hrt[i])
        {
            root[i] = Update(fst[x], hsh, root[i]);
            root[i] = Update(lst[x], - hsh, root[i]);
        }
    }

    cin >> q;

    vi ans;
    int u1, v1, u2, v2, k, lca1, lca2;
    FOR(i, 1, q)
    {
        cin >> u1 >> v1 >> u2 >> v2 >> k;
        lca1 = get_lca(u1, v1), lca2 = get_lca(u2, v2);

        ans.clear();
        for(int i = 1, v = 1, add = 0; i <= k && v < N; ++i)
        {
            int st = v, dr = N - 1, m, pos = -1;
            while(st <= dr)
            {
                m = (st + dr) >> 1;

                if((get_hsh(u1, v1, lca1, m) + add) % M != get_hsh(u2, v2, lca2, m))
                {
                    pos = m;
                    dr = m - 1;
                }
                else st = m + 1;
            }

            if(pos == -1)break;
            ans.pb(pos);
            v = pos + 1;
            add = (get_hsh(u2, v2, lca2, pos) - get_hsh(u1, v1, lca1, pos) + M) % M;
        }

        cout << ans.size() << ' ';
        for(auto x : ans)cout << x << ' ';
        cout << '\n';
    }

    return;
}

/// Check for interruption of input!!

signed main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
