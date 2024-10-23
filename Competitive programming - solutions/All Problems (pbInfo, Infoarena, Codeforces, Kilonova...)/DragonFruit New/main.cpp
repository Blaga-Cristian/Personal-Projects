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
using vvvvi = vector<vvvi>;
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

const string TASK("dragonfruit");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll N = 2, K = 1009, S = 11;

int n, k, s, a[(int)1e5 + 9];

int mn[N][K][S][2];
int ways[N][K][S][2];
/// [0] - paranteza deschisa
/// [1] - paranteza inchisa

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

void solve_testcase()
{
    cin >> n >> k >> s;


    FOR(i, 1, n)cin >> a[i];

    int prv = 0, cur = 1;

    for(int sum = 0; sum <= k; ++sum)
        for(int p = 0; p <= s; ++p)
        {
            mn[0][sum][p][0] = mn[0][sum][p][1] = Inf;
            ways[0][sum][p][0] = ways[0][sum][p][1] = 0;
        }

    mn[0][0][0][1] = 0;
    ways[0][0][0][1] = 1;

    for(int i = 1; i <= n; ++i, swap(prv, cur))
    {
        for(int sum = 0; sum <= k; ++sum)
            for(int p = 0; p <= s; ++p)
            {
                mn[cur][sum][p][0] = mn[cur][sum][p][1] = Inf;
                ways[cur][sum][p][0] = ways[cur][sum][p][1] = 0;
            }

        for(int sum = 0; sum <= k; ++sum)
            for(int p = 0; p <= s; ++p)
            {
                if(sum >= a[i])
                {
                    mn[cur][sum][p][0] = mn[prv][sum - a[i]][p][0] + 1;
                    ways[cur][sum][p][0] = ways[prv][sum - a[i]][p][0];

                    if(p > 0)
                    {
                        if(mn[prv][sum - a[i]][p][0] + 1 > mn[prv][sum - a[i]][p - 1][1] + 1)
                        {
                            mn[cur][sum][p][0] = mn[prv][sum - a[i]][p - 1][1] + 1;
                            ways[cur][sum][p][0] = ways[prv][sum - a[i]][p - 1][1];
                        }
                        else if(mn[prv][sum - a[i]][p][0] + 1 == mn[prv][sum - a[i]][p - 1][1] + 1)
                            ways[cur][sum][p][0] = add(ways[cur][sum][p][0], ways[prv][sum - a[i]][p - 1][1]);
                    }
                }

                mn[cur][sum][p][1] = mn[prv][sum][p][1];///nu fac o noua paranteza
                ways[cur][sum][p][1] = ways[prv][sum][p][1];
                if(mn[prv][sum][p][1] > mn[cur][sum][p][0])
                {
                    mn[cur][sum][p][1] = mn[cur][sum][p][0];
                    ways[cur][sum][p][1] = ways[cur][sum][p][0];
                }
                else if(mn[prv][sum][p][1] == mn[cur][sum][p][0])
                    ways[cur][sum][p][1] = add(ways[cur][sum][p][1], ways[cur][sum][p][0]);
            }
    }

    int ans = Inf, cnt = 0;
    for(int p = 0; p <= s; ++p)
        if(ans > mn[prv][k][p][1])
        {
            ans = mn[prv][k][p][1];
            cnt = ways[prv][k][p][1];
        }
        else if(ans == mn[prv][k][p][1])
            cnt = add(cnt, ways[prv][k][p][1]);

    if(ans == Inf)cout << "0 0\n";
    else cout << ans << ' ' << cnt << '\n';
}

/// Check for interruption of input!!

int main() {
    fastio();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
