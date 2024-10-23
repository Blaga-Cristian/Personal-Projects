#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<typename T>
//using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define ull unsigned long long
//#define cin fin
//#define cout fout
//int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
int di[] = {-1, -1, 1, 1}, dj[] = {-1, 1, 1, -1};
const int Inf = 0x3f3f3f3f;
bool testCase = false;
const ll Nmax = 2e5 + 9, LG = 20;

int n, q;
vvi G(Nmax);

int tour[2 * Nmax], in[Nmax], out[Nmax], idx, dep[Nmax];
void Dfs(int x = 1, int p = 0)
{
    in[x] = ++idx;
    tour[idx] = x;

    for(auto y : G[x])
        if(y != p)
        {
            dep[y] = dep[x] + 1;
            Dfs(y, x);
        }

    out[x] = ++idx;
    tour[idx] = x;
}

struct nod
{
    int mx, lazy;

    nod() : mx(INT_MIN), lazy(0)
    {}

};
nod tree[8 * Nmax]; /// max pe int, update pe int
void Push(int nod, int st, int dr)
{
    if(st == dr || tree[nod].lazy == 0)return;

    int val = tree[nod].lazy;
    tree[nod << 1].mx += val;
    tree[nod << 1].lazy += val;
    tree[nod << 1 | 1].mx += val;
    tree[nod << 1 | 1].lazy += val;

    tree[nod].lazy = 0;
}
void Build(int nod = 1, int st = 1, int dr = 2 * n)
{
    if(st == dr)
    {
        tree[nod].mx = dep[tour[st]];
        return;
    }

    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);

    tree[nod].mx = max(tree[nod << 1].mx, tree[nod << 1 | 1].mx);
}
void Update(int a, int b, int val, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(a <= st && dr <= b)
    {
        tree[nod].mx += val;
        tree[nod].lazy += val;
        return;
    }

    Push(nod, st, dr);

    int m = (st + dr) >> 1;
    if(a <= m)Update(a, b, val, nod << 1, st, m);
    if(b > m)Update(a, b, val, nod << 1 | 1, m + 1, dr);

    tree[nod].mx = max(tree[nod << 1].mx, tree[nod << 1 | 1].mx);
}
int Query(int a, int b, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(a <= st && dr <= b)
        return tree[nod].mx;

    Push(nod, st, dr);

    int m = (st + dr) >> 1;
    if(b <= m)return Query(a, b, nod << 1, st, m);
    else if(a > m)return Query(a, b, nod << 1 | 1, m + 1, dr);
    return max(Query(a, b, nod << 1, st, m), Query(a, b, nod << 1 | 1, m + 1, dr));
}


struct info
{
    int nod, ans;
    vi v;

    info() : nod(0), ans(-1), v()
    {}
};
info queries[Nmax];
vvi inds(Nmax);

bool is_ancestor(int a, int b)
{
    return (in[a] <= in[b] && out[b] <= out[a]);
}
int get_son(int a, int b)
{
    int st = 0, dr = G[a].size() - 1, m, poz = -1;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        if(in[G[a][m]] <= in[b])
        {
            poz = m;
            st = m + 1;
        }
        else dr = m - 1;
    }

    if(poz == -1)return -1;
    return G[a][poz];
}

void Solve(int x = 1, int p = 0)
{
//    cout << "At node " << x << "  ";
//    FOR(i, 1, 2 * n)cout << Query(i, i) << ' ';
//    cout << '\n';

    for(auto ind : inds[x])
    {
        set<pii> bad_segm;
        for(auto i : queries[ind].v)
            if(is_ancestor(i, x))
            {
                int s = get_son(i, x);
                bad_segm.insert({1, in[s] - 1});
                bad_segm.insert({out[s] + 1, 2 * n});
            }
            else bad_segm.insert({in[i], out[i]});

        int p = 1;
        for(auto i : bad_segm)
        {
            if(p < i.ff)queries[ind].ans = max(queries[ind].ans, Query(p, i.ff - 1));
            p = max(p, i.ss + 1);
        }
        if(p <= 2 * n)queries[ind].ans = max(queries[ind].ans, Query(p, 2 * n));
    }


    for(auto y : G[x])
    {
        if(y == p)continue;

        ///Rerooting
        if(in[y] > 1)Update(1, in[y] - 1, 1);
        Update(in[y], out[y], -1);
        if(out[y] < 2 * n)Update(out[y] + 1, 2 * n, 1);

        Solve(y, x);

        ///Anti-Rerooting
        if(in[y] > 1)Update(1, in[y] - 1, -1);
        Update(in[y], out[y], 1);
        if(out[y] < 2 * n)Update(out[y] + 1, 2 * n, -1);
    }
}

void solve_testcase()
{
    cin >> n >> q;

    int u, v;
    FOR(i, 2, n)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    int x, k;
    FOR(i, 1, q)
    {
        cin >> x >> k;
        queries[i].nod = x;
        inds[x].pb(i);

        int a;
        FOR(j, 1, k)
        {
            cin >> a;
            queries[i].v.pb(a);
        }
    }

    Dfs();
    FOR(i, 1, n)sort(all(G[i]), [](int a, int b){return in[a] < in[b];});
    Build();

//    cout << "           ";
//    FOR(i, 1, 2 * n)cout << tour[i] << ' ';
//    cout << '\n';

    Solve();

    FOR(i, 1, q)cout << queries[i].ans << '\n';
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
