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
const ll N = 1e5 + 9, K = 11, LG = 21;
const int M1 = 1e9 + 7;
const int M2 = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(20, 10000);

int n, q, a[N];
vvi G(N);


struct node
{
    int v1, v2;///maintain sum
    node *l, *r;
};
node *root[N];

void Build(node* nod, int st = 1, int dr = N - 1)
{
    nod -> v1 = 0;
    nod -> v2 = 0;
    if(st == dr)return;
    int m = (st + dr) >> 1;
    Build(nod -> l = new node(), st, m);
    Build(nod -> r = new node(), m + 1, dr);
}

node* Update(int p, pii v, node* nod, int st = 1, int dr = N - 1)
{
    node* nnod = new node(*nod);
    if(st == dr)
    {
        nnod -> v1 = (nnod -> v1 + v.ff) % M1;
        nnod -> v2 = (nnod -> v2 + v.ss) % M2;
        return nnod;
    }
    int m = (st + dr) >> 1;
    if(p <= m)nnod -> l = Update(p, v, nod -> l, st, m);
    else nnod -> r = Update(p, v, nod -> r, m + 1, dr);
    nnod -> v1 = (nnod -> l -> v1 + nnod -> r -> v1) % M1;
    nnod -> v2 = (nnod -> l -> v2 + nnod -> r -> v2) % M2;
    return nnod;
}

//int Query(int l, int r, node* nod, int st = 1, int dr = N - 1)
//{
//    if(l <= st && dr <= r)return nod -> v;
//    int m = (st + dr) >> 1;
//    if(r <= m)return Query(l, r, nod -> l, st, m);
//    else if(l > m)return Query(l, r, nod -> r, m + 1, dr);
//    return (Query(l, r, nod -> l, st, m) + Query(l, r, nod -> r, m + 1, dr)) % M;
//}

int t[N][LG], dep[N], tour[2 * N], sz, fst[N], lst[N];
void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;
    t[x][0] = p;
    FOR(i, 1, LG - 1)t[x][i] = t[t[x][i - 1]][i - 1];

    fst[x] = ++sz;
    tour[sz] = x;

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    lst[x] = ++sz;
    tour[sz] = x;
}

int get_lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);

    FORR(i, LG - 1, 0)
        if(dep[x] - (1 << i) >= dep[y])
            x = t[x][i];

    if(x == y)return x;

    FORR(i, LG - 1, 0)
        if(t[x][i] != t[y][i])
        {
            x = t[x][i];
            y = t[y][i];
        }

    return t[x][0];
}


int hash_value1[N], hash_value2[N];

///NEED FAST LCA
int get_hsh1(node* u, node* v, node* lca, node* tlca)///calcule
{
    int ret = (u -> v1 + v -> v1) % M1;
    ret = (ret - lca -> v1 + M1) % M1;
    ret = (ret - tlca -> v1 + M1) % M1;
    return ret;
}

int get_hsh2(node* u, node* v, node* lca, node* tlca)///calcule
{
    int ret = (u -> v2 + v -> v2) % M2;
    ret = (ret - lca -> v2 + M2) % M2;
    ret = (ret - tlca -> v2 + M2) % M2;
    return ret;
}

void S_Dfs(int x = 1, int p = 0)
{
    root[x] = Update(a[x], {hash_value1[a[x]], hash_value2[a[x]]}, root[p]);

    for(auto y : G[x])
        if(y != p)
            S_Dfs(y, x);
}

vi ans;
int k;

void Dfs_Search(node* u1, node* v1, node* l1, node* tl1,
                node* u2, node* v2, node* l2, node* tl2,
                int st = 1, int dr = N - 1)///TREBUIE MODIFICATE CONDITIILE
{
    if(st == dr)
    {
        ans.pb(st);
        return;
    }
    int m = (st + dr) >> 1;

    if(get_hsh1(u1 -> l, v1 -> l, l1 -> l, tl1 -> l) !=
       get_hsh1(u2 -> l, v2 -> l, l2 -> l, tl2 -> l) &&
       get_hsh2(u1 -> l, v1 -> l, l1 -> l, tl1 -> l) !=
       get_hsh2(u2 -> l, v2 -> l, l2 -> l, tl2 -> l)
       && ans.size() < k)
        Dfs_Search(u1 -> l, v1 -> l, l1 -> l, tl1 -> l,
                   u2 -> l, v2 -> l, l2 -> l, tl2 -> l, st, m);

    if(get_hsh1(u1 -> r, v1 -> r, l1 -> r, tl1 -> r) !=
       get_hsh1(u2 -> r, v2 -> r, l2 -> r, tl2 -> r) &&
       get_hsh2(u1 -> r, v1 -> r, l1 -> r, tl1 -> r) !=
       get_hsh2(u2 -> r, v2 -> r, l2 -> r, tl2 -> r)
       && ans.size() < k)
        Dfs_Search(u1 -> r, v1 -> r, l1 -> r, tl1 -> r,
                   u2 -> r, v2 -> r, l2 -> r, tl2 -> r, m + 1, dr);
}

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs();
    root[0] = new node();
    Build(root[0]);
    FOR(i, 0, N - 1)hash_value1[i] = (i + rng() % M2) % M2;
    FOR(i, 0, N - 1)hash_value2[i] = (i + rng() % M2) % M2;
    S_Dfs();

    cin >> q;

    int u1, v1, u2, v2, lca1, lca2;
    FOR(i, 1, q)
    {
        cin >> u1 >> v1 >> u2 >> v2 >> k;
        lca1 = get_lca(u1, v1), lca2 = get_lca(u2, v2);

        ans.clear();

        Dfs_Search(root[u1], root[v1], root[lca1], root[t[lca1][0]],
                   root[u2], root[v2], root[lca2], root[t[lca2][0]]);

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
