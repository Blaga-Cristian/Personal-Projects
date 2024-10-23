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
bool testCase = true;
const ll N = 3009;

int n, k;
char s[N];
int lo[N][N]; ///dp[lf][x] = lungimea maxima a unui sir de oaks daca folosesc x actiuni
int ro[N][N]; ///dp[r][x] = lungimea maxima a unui sir de oaks daca folosesc x actiunui
int dp[N]; /// dp[len] = nr substr maxim de oaks pe care-l pot aveam ,stiind ca am un sir de first de lungime len

int spo[N];
int get(int l, int r)
{
    return spo[r] - spo[l - 1];
}

void solve_testcase()
{
    cin >> n >> k;
    cin >> (s + 1);

    FOR(i, 0, n + 1)
    {
        dp[i] = spo[i] = 0;
        FOR(j, 0, k + 1)
            lo[i][j] = ro[i][j] = 0;
    }

    FOR(i, 1, n)
        spo[i] = spo[i - 1] + (s[i] == '0');

    FOR(i, 1, n)
        FOR(j, 0, k)
            if(s[i] == '0')
                lo[i][j] = lo[i - 1][j] + 1;
            else if(j > 0)
                lo[i][j] = lo[i - 1][j - 1] + 1;

    FOR(i, 1, n)
        FOR(j, 0, k)
        {
            lo[i][j] = max(lo[i][j], lo[i][j - 1]);
            lo[i][j] = max(lo[i][j], lo[i - 1][j]);
        }

    FORR(i, n, 1)
        FOR(j, 0, k)
            if(s[i] == '0')
                ro[i][j] = ro[i + 1][j] + 1;
            else if(j > 0)
                ro[i][j] = ro[i + 1][j - 1] + 1;

    FORR(i, n, 1)
        FOR(j, 0, k)
        {
            ro[i][j] = max(ro[i][j], ro[i][j - 1]);
            ro[i][j] = max(ro[i][j], ro[i + 1][j]);
        }


    FOR(len, 0, n)
    {
        dp[len] = -1;
        FOR(i, len, n)
        {
            int s = get(i - len + 1, i);
            if(s <= k)dp[len] = max(dp[len], max(lo[i - len][k - s], ro[i + 1][k - s]));
        }
    }

    FOR(j, 1, n)
    {
        ll ans = 0;
        FOR(i, 0, n)if(dp[i] != -1)ans = max(ans, 1LL * dp[i] * j + i);
        cout << ans << ' ';
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