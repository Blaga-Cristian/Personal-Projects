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

ll Mod = 1;

struct intm
{
    int x;

    ll PtLg(ll base, ll exp)
    {
        ll ret = 1;
        for(; exp; exp >>= 1, base = (1LL * base * base) % Mod)
            if(exp & 1)
                ret = (1LL * ret * base) % Mod;
        return ret;
    }

    intm(int x = 0) : x(x % Mod) {}
    intm operator + (intm const& oth){return (x + oth.x) % Mod;}
    intm operator - (intm const& oth){return (x - oth.x + Mod) % Mod;}
    intm operator * (intm const& oth){return (1LL * x * oth.x) % Mod;}
    intm operator / (intm const& oth){return (1LL * x * PtLg(oth.x, Mod - 2)) % Mod;}
    intm operator += (intm const& oth){return *this = x + oth.x;}
    intm operator -= (intm const& oth){return *this = x - oth.x;}
    intm operator *= (intm const& oth){return *this = x * oth.x;}
    intm operator /= (intm const& oth){return *this = x / oth.x;}
    intm operator ++ (int) {intm aux = *this; *this += 1; return aux;}///i++
    intm operator ++ (){return *this += 1;}///++i
    intm operator -- (int) {intm aux = *this; *this -= 1; return aux;}///i--
    intm operator -- (){return *this -= 1;}///--i
    intm operator % (int const& oth){return x % oth;}
    intm operator %= (int const& oth){return x = x % oth;}


    friend ostream& operator << (ostream& os, intm a){return os << a.x;}
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

const string TASK("tricolor");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll N = 5009;

int n, dp[N][N], w[N];
vvi G(N);

int tmp[N];
void merge_states(int x, int y)
{
    FOR(i, 1, w[x] + w[y])tmp[i] = 0;

    FOR(i, 1, w[x])
        FOR(j, 1, w[y])
            tmp[i + j] = max(tmp[i + j], dp[x][i] + dp[y][j] + i * j);

    FOR(i, 1, w[x] + w[y])dp[x][i] = tmp[i];
}

void Dfs(int x = 1, int p = 0)
{
    w[x] = 0;
    int case_1 = 0;

    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);


        merge_states(x, y);
        w[x] += w[y];

        int mx = 0;
        FOR(i, 1, w[y])mx = max(mx, dp[y][i] + i);
        case_1 += mx;
    }

    dp[x][1] = max(dp[x][1], case_1);
    if(w[x] == 0)w[x] = 1;
}

void solve_testcase()
{
    cin >> n;

    FOR(i, 1, n)G[i].clear();
    FOR(i, 0, n)FOR(j, 0, n)dp[i][j] = 0;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs();

    int ans = 0;
    FOR(i, 0, n)ans = max(ans, dp[1][i]);
    cout << ans << '\n';
}

/// Check for interruption of input!!

int main() {
    fastio();
//    Precalc();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
