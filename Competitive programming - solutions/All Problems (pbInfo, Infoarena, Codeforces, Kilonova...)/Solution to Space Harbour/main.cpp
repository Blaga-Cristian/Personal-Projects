#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<typename T>
//using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};
//
//struct custom_hash_pair {
//	static uint64_t splitmix64(uint64_t x) {
//		x += 0x9e3779b97f4a7c15;
//		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//		return x ^ (x >> 31);
//	}
//
//	size_t operator()(pair<uint64_t,uint64_t> x) const {
//		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
//	}
//};

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

ll Mod = 1e9 + 7;

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
bool testCase = false;
const ll N = 3e5 + 9;

int n, m, q;

int p[N], v[N];

multiset<pii> myset;

int hleft(int x)
{
    return (*(--myset.lower_bound({x, Inf}))).ss;
}
int hright(int x)
{
    return (*(myset.lower_bound({x, -1}))).ss;
}

struct nod
{
    ll sum;
    ll v, sumd;
    ll lv, lsumd;
};

nod tree[4 * N];

void Push(int nod, int st, int dr)///TREBUIE SA STIU CE QUERIURI TREBE SA FAC PRIMA DATA
{
    if(st == dr || (tree[nod].lsumd == 0 && tree[nod].lv == 0))return;

    int m = (st + dr) >> 1;

    tree[nod << 1].sumd += (m - st + 1) * tree[nod].lsumd;
    tree[nod << 1].lsumd += tree[nod].lsumd;
    tree[nod << 1].v += tree[nod].lv;
    tree[nod << 1].lv += tree[nod].lv;
    tree[nod << 1].sum = tree[nod << 1].v * tree[nod << 1].sumd;

    tree[nod << 1 | 1].sumd += (dr - m) * tree[nod].lsumd;
    tree[nod << 1 | 1].lsumd += tree[nod].lsumd;
    tree[nod << 1 | 1].v += tree[nod].lv;
    tree[nod << 1 | 1].lv += tree[nod].lv;
    tree[nod << 1 | 1].sum = tree[nod << 1 | 1].v * tree[nod << 1 | 1].sumd;


    tree[nod].lsumd = tree[nod].lv = 0;
}

void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        tree[nod].v = v[hleft(st)];
        tree[nod].sumd = p[hright(st)] - st;
        tree[nod].sum = tree[nod].v * tree[nod].sumd;
        return;
    }

    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);

    tree[nod].sum = tree[nod << 1].sum + tree[nod << 1 | 1].sum;
    tree[nod].v = tree[nod << 1].v;
    tree[nod].sumd = tree[nod << 1].sumd + tree[nod << 1 | 1].sumd;
}

void Update1(int l, int r, int val, int nod = 1, int st = 1, int dr = n) ///modific distanta
{
    if(l <= st && dr <= r)
    {
        tree[nod].sumd += (dr - st + 1) * val;
        tree[nod].lsumd += val;
        tree[nod].sum = tree[nod].v * tree[nod].sumd;
        return;
    }

    Push(nod, st, dr);

    int m = (st + dr) >> 1;
    if(l <= m)Update1(l, r, val, nod << 1, st, m);
    if(r > m)Update1(l, r, val, nod << 1 | 1, m + 1, dr);

    tree[nod].sum = tree[nod << 1].sum + tree[nod << 1 | 1].sum;
    tree[nod].v = tree[nod << 1].v;
    tree[nod].sumd = tree[nod << 1].sumd + tree[nod << 1 | 1].sumd;
}

void Update2(int l, int r, int val, int nod = 1, int st = 1, int dr = n) ///modific inmultirea
{
    if(l <= st && dr <= r)
    {
        tree[nod].v += val;
        tree[nod].lv += val;
        tree[nod].sum = tree[nod].v * tree[nod].sumd;
        return;
    }

    Push(nod, st, dr);

    int m = (st + dr) >> 1;
    if(l <= m)Update2(l, r, val, nod << 1, st, m);
    if(r > m)Update2(l, r, val, nod << 1 | 1, m + 1, dr);

    tree[nod].sum = tree[nod << 1].sum + tree[nod << 1 | 1].sum;
    tree[nod].v = tree[nod << 1].v;
    tree[nod].sumd = tree[nod << 1].sumd + tree[nod << 1 | 1].sumd;
}

int Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return tree[nod].sum;

    Push(nod, st, dr);

    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return Query(l, r, nod << 1, st, m) + Query(l, r, nod << 1 | 1, m + 1, dr);
}

void solve_testcase()
{
    cin >> n >> m >> q;

    FOR(i, 1, m)cin >> p[i];
    FOR(i, 1, m)cin >> v[i];

    FOR(i, 1, m)myset.insert({p[i], i});

//    FOR(i, 1, n)
//    {
//        cout << (*(--myset.lower_bound({i, 99}))).ss << '\n'; - leftmost
//        cout << (*(myset.lower_bound({i, -1}))).ss << '\n'; - rightmost
//    }

    Build();

    int op, a, b;
    FOR(i, 1, q)
    {
        cin >> op >> a >> b;
        if(op == 1)
        {
            int i = hleft(a), j = hright(a);
            Update1(p[i] + 1, a, a - p[j]);
            Update2(a + 1, p[j], b - v[i]);

            ++ m;
            p[m] = a;
            v[m] = b;
            myset.insert({p[m], m});
        }
        else cout << Query(a, b) << '\n';
    }
}

/// Check for interruption of input!!

int main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
