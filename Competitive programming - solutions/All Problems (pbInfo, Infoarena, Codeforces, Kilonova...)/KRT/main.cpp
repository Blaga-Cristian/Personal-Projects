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

mt19937 rnd();

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

template<typename T, int Mod = 1e9 + 7> struct SegmentProd{
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

template <typename T, int Mod = 1e9 + 7> struct SegmentSum{
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

//#define int long long
const string TASK("trie");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll N = 3e5 + 9, LG = 19, Mod = 1e9 + 7;

int n, q, x;
pii s[N];

struct edge
{
    int x, y, c;

    bool operator < (edge const& oth)
    {
        return c < oth.c;
    }
};
vector<edge> edges;

int dsu[N], id;
int find(int x){return dsu[x] == 0 ? x : dsu[x] = find(dsu[x]);}
void unite(int x, int y)
{
    x = find(x), y = find(y);

    ++id;
    if(x == y)return;
    dsu[x] = dsu[y] = id;
    s[id] = {x, y};
}

int t[N], j[N], dep[N], in[N], out[N], idx;
void Dfs(int x = find(1), int p = 0)
{
    dep[x] = dep[p] + 1;
    t[x] = p;
    if(dep[j[t[x]]] - dep[t[x]] == dep[j[j[t[x]]]] - dep[j[t[x]]])
        j[x] = j[j[t[x]]];
    else j[x] = t[x];

    if(x <= n)
    {
        in[x] = ++idx;
        out[x] = ++idx;
        return;
    }

    if(s[x].ff)Dfs(s[x].ff, x);
    if(s[x].ss)Dfs(s[x].ss, x);

    in[x] = in[s[x].ff], out[x] = out[s[x].ss];
}

pii tr[4 * N];
int lz[4 * N];
pii operator + (pii const& a, pii const& b)
{
    if(a.ff == b.ff)return {a.ff, a.ss + b.ss};
    else if(a.ff < b.ff)return a;
    return b;
}
void Build(int nod = 1, int st = 1, int dr = idx)
{
    tr[nod] = {0, dr - st + 1};
    lz[nod] = 0;
    if(st == dr)return;
    int m = (st + dr) / 2;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
}
void Push(int nod, int st, int dr)
{
    if(st == dr || lz[nod] == 0)return;
    int l = lz[nod];
    lz[nod] = 0;

    tr[nod << 1].ff += l;
    lz[nod << 1] += l;

    tr[nod << 1 | 1].ff += l;
    lz[nod << 1 | 1] += l;
}
void Update(int l, int r, int v, int nod = 1, int st = 1, int dr = idx)
{
    if(l <= st && dr <= r)
    {
        tr[nod].ff += v;
        lz[nod] += v;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) / 2;
    if(l <= m)Update(l, r, v, nod << 1, st, m);
    if(r > m)Update(l, r, v, nod << 1 | 1, m + 1, dr);
    tr[nod] = tr[nod << 1] + tr[nod << 1 | 1];
}
pii Query(int l, int r, int nod = 1, int st = 1, int dr = idx)
{
    if(l <= st && dr <= r)return tr[nod];
    Push(nod, st, dr);
    int m = (st + dr) / 2;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return Query(l, r, nod << 1, st, m) + Query(l, r, nod << 1 | 1, m + 1, dr);
}

void solve_testcase()
{
    cin >> n;

    id = n;
    idx = 0;
    FOR(i, 1, 2 * n)
    {
        t[i] = j[i] = dsu[i] =
        dep[i] = in[i] = out[i] = 0;
        s[i] = {0, 0};
    }

    edges.resize(n - 1);
    for(auto& e : edges)
        cin >> e.x >> e.y >> e.c;

    sort(edges.begin(), edges.end());

    for(auto e : edges)
        unite(e.x, e.y);

    Dfs();
    Build();

    cin >> q >> x;
    int d, u, k;
    queue<pii> upds;
    FOR(i, 1, q)
    {
        cin >> d >> u >> k;

//        FOR(i, 1, n)cout << " { " << in[i] << " , " << out[i] << " } ";

        while(!upds.empty() && upds.front().ff <= d)
        {
            auto [_, v] = upds.front();
            upds.pop();
            Update(in[v], out[v], -1);
        }

        for(; t[u] && edges[t[u] - n - 1].c <= k;)
            if(j[u] && edges[j[u] - n - 1].c <= k)
                u = j[u];
            else u = t[u];

        auto r = Query(in[u], out[u]);
        cout << (r.ff == 0) * r.ss / 2 << '\n';
        Update(in[u], out[u], 1);
        upds.push({d + x, u});
    }
}

/// Check for interruption of input!!

signed main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
