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
bool testCase = false;
const ll Nmax=2e5+1;
int BUCK = 1009;

class BucketDecomposition
{
    int n, bucket_size;
    vi values, bucket, bucket_values;

public:

    BucketDecomposition(int n, int bucket_size) : n(n), bucket_size(bucket_size)
    {
        values = vi(n, Inf);
        bucket = vi(n, 0);

        int current_bucket = 0;
        for(int i = 0; i < n; i += bucket_size, ++current_bucket)
            for(int j = i; j < n && j < i + bucket_size; ++j)
                bucket[j] = current_bucket;

        bucket_values = vi(current_bucket, Inf);
    }

    void Update(int pos, int value)
    {
        values[pos] = value;
        bucket_values[bucket[pos]] = min(bucket_values[bucket[pos]], value);
    }

    int Query(int r)
    {
        r --;
        int ans = Inf;

        for(int i = 0; i < bucket[r]; ++i)
            ans = min(ans, bucket_values[i]);

        for(int i = r; i >= 0 && bucket[i] == bucket[r]; --i)
            ans = min(ans, values[i]);

        return ans;
    }
};

struct query_t
{
    int l, r, ans, idx;

    query_t() : l(0), r(0), ans(-1), idx(0) {}
};

int n, q;

void solve_testcase()
{
    cin >> n;

    BUCK = sqrt(n);

    vi v(n);
    for(int i = 0; i < n; ++i)cin >> v[i];

    vi prefix_sums(n + 1, 0);
    vpi normalizare;

    normalizare.push_back({prefix_sums[0], 0});
    for(int i = 0; i < n; ++i)
    {
        prefix_sums[i + 1] = prefix_sums[i] ^ v[i];
        normalizare.pb({prefix_sums[i + 1], i + 1});
    }

    sort(all(normalizare));

    int last = 0;
    for(int i = 0; i < (int)normalizare.size(); ++i)
    {
        if(i > 0 && normalizare[i].ff != normalizare[i - 1].ff)last ++;
        prefix_sums[normalizare[i].ss] = last;
    }

    normalizare.clear();

    vi frecv(last + 1, 0);
    for(int i = 0; i < (int)prefix_sums.size(); ++i)
        frecv[prefix_sums[i]] ++;


    cin >> q;

    vector<query_t> queries(q);
    for(int i = 0; i < q; ++i)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l ++, queries[i].r ++;
        queries[i].ans = Inf;
        queries[i].idx = i;
    }

    vi nxt(n + 1, -1);
    vi prv(n + 1, -1);

    for(int value = 0; value <= last; ++value)
        if(frecv[value] > BUCK)
        {
            for(int i = 0; i <= n; ++i)
                prv[i] = (prefix_sums[i] == value) ? i : (i > 0 ? prv[i - 1] : -1);
            for(int i = n; i >= 0; --i)
                nxt[i] = (prefix_sums[i] == value) ? i : (i < n ? nxt[i + 1] : -1);

            for(auto& it : queries)
                if(prv[it.l - 1] != -1 && nxt[it.r] != -1)
                    it.ans = min(it.ans, nxt[it.r] - prv[it.l - 1]);
        }


    vvi positions(last + 1, vi());
    for(int i = 0; i <= n; ++i)
        positions[prefix_sums[i]].pb(i);

    sort(all(queries), [](query_t a, query_t b){return a.r > b.r;});

    BucketDecomposition batog(n + 1, BUCK);
    int idx = n;

    for(auto& it : queries)
    {
        while(idx >= it.r)
        {
            if(frecv[prefix_sums[idx]] <= BUCK)
            {
                for(auto i : positions[prefix_sums[idx]])
                {
                    batog.Update(i, idx - i);
                    if(i >= idx)break;
                }
            }
            idx --;
        }

        it.ans = min(it.ans, batog.Query(it.l));
    }

    for(auto& it : queries)
        if(it.ans == Inf)
            it.ans = -1;

    sort(all(queries), [](query_t a, query_t b){return a.idx < b.idx;});

    for(auto i : queries)cout << i.ans << '\n';
}

/// Check for interruption of input!!

int main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
