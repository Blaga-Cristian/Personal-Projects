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
using vvpi = vector<vector<pii>>;
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
//#define cin fin
//#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll N = 10009;

int n;
vvpi G(N);
vvi chain;
int ind[N], pos[N];
int t[N], w[N], cost[N], head[N], dep[N];
char s[20];

void GetString();
int GetInt();

struct Edge
{
    int a, b, c;
};
vector<Edge> edges;

struct SegTree
{
    int n;
    vi tree;

    SegTree(int n) : n(n), tree(vi(2 * n)) {}
    SegTree(vi& v)
    {
        n = v.size();
        tree = vi(2 * n);
        for(int p = 0; p < n; ++p)tree[p + n] = v[p];
        for(int p = n - 1; p; --p)tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }

    void clear()
    {
        n = 0;
        tree.clear();
    }

    void Update(int pos, int val)///indexat de la 0
    {
        for(tree[pos += n] = val; pos > 1; pos >>= 1)tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }

    int query(int l, int r)///indexat de la 0
    {
        int res = INT_MIN;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1)
        {
            if(l & 1)res = max(res, tree[l++]);
            if(!(r & 1))res = max(res, tree[r--]);
        }

        return res;
    }
};
vector<SegTree> st;

void Dfs(int x)
{
    w[x] = 1;

    if(G[x].size() == 1 && dep[x] > 0)
    {
        head[chain.size()] = x;
        ind[x] = chain.size();
        pos[x] = 0;
        chain.pb(vi(1, cost[x]));
        return;
    }

    int son = -1;

    for(auto [y, c] : G[x])
    {
        if(y == t[x])continue;

        t[y] = x;
        cost[y] = c;
        dep[y] = dep[x] + 1;

        Dfs(y);

        w[x] += w[y];
        if(son == -1 || w[son] < w[y])
            son = y;
    }

    head[ind[son]] = x;
    ind[x] = ind[son];
    pos[x] = pos[son] + 1;
    chain[ind[son]].pb(cost[x]);
}

int Query(int a, int b)
{
    int res = INT_MIN;

    while(ind[a] != ind[b])
    {
        if(dep[head[a]] < dep[head[b]])swap(a, b);

        res = max(res, st[ind[a]].query(pos[a], chain[ind[a]].size() - 1));
        a = t[head[a]];
    }

    if(pos[a] > pos[b])swap(a, b);
    if(pos[a] > pos[b])res = max(res, st[ind[a]].query(pos[a], pos[b] - 1));

    return res;
}


void solve_testcase()
{
    cin >> n;

    for(int i = 0; i < st.size(); ++i)st[i].clear();
    st.clear();
    edges.clear();
    chain.clear();
    FOR(i, 1, n)
    {
        G[i].clear();
        ind[i] = pos[i] = t[i] = w[i] = cost[i] = dep[i] = 0;
    }

    int a, b, c;
    FOR(i, 2, n)
    {
        cin >> a >> b >> c;
        G[a].eb(b, c);
        G[b].eb(a, c);
        edges.pb({a, b, c});
    }

    Dfs(1);
    for(auto& i : chain)st.eb(SegTree(i));

    int i, ti;
    while(true)
    {
        GetString();

        if(s[0] == 'D')break;
        else if(s[0] == 'C')
        {
            i = GetInt(), ti = GetInt();
            a = edges[i - 1].a, b = edges[i - 1].b;
            if(t[a] == b)swap(a, b);
            st[ind[b]].Update(pos[b], ti);
        }
        else
        {
            a = GetInt(), b = GetInt();
            cout << Query(a, b) << '\n';
        }
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


const int LIM = 1 << 17;
char buff[LIM];
int idx = LIM - 1;

void GetString()
{
    int nr = 0;
    while (!isalpha(buff[idx]))
        if (++idx >= LIM)
        {
            idx = 0;
            fread(buff, 1, LIM, stdin);
        }

    while (isalpha(buff[idx]))
    {
        s[nr++] = buff[idx];
        if (++idx >= LIM)
        {
            idx = 0;
            fread(buff, 1, LIM, stdin);
        }
    }
    s[nr] = 0;
}

int GetInt()
{
    int nr = 0;
    while (!isdigit(buff[idx]))
        if (++idx >= LIM)
        {
            idx = 0;
            fread(buff, 1, LIM, stdin);
        }

    while (isdigit(buff[idx]))
    {
        nr = nr * 10 + (buff[idx] - '0');
        if (++idx >= LIM)
        {
            idx = 0;
            fread(buff, 1, LIM, stdin);
        }
    }
    return nr;
}
