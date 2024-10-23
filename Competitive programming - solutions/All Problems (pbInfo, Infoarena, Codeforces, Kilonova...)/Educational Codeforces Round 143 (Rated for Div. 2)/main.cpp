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
const ll N = 3e5 + 9, V = 1e6 + N, LG = 31, Mod = 998244353;

int n;
ll a[N], b[N], l[N], r[N];

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}
ll mul(ll x, ll y){return (x * y) % Mod;}
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}
ll fact[N], inv[N];
void Precalc()
{
    fact[0] = 1;
    FOR(i, 1, N - 1)fact[i] = mul(i, fact[i - 1]);

    inv[N - 1] = PtLg(fact[N - 1], Mod - 2);
    FORR(i, N - 2, 1)inv[i] = mul(i + 1, inv[i + 1]);
}
ll comb(ll n, ll k)
{
    if(n < k || n < 0 || k < 0)return 0;
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

//int t[4 * V], ld[4 * V], ls[4 * V];
//void Build(int nod = 1, int st = 1, int dr = V)
//{
//    t[nod] = ld[nod] = ls[nod] = 0;
//    if(st == dr)return;
//    int m = (st + dr) / 2;
//    Build(nod << 1, st, m);
//    Build(nod << 1 | 1, m + 1, dr);
//}
//void Push(int nod, int st, int dr)
//{
//    if(st == dr || (ld[nod] == 0 && ls[nod] == 0))return;
//    int m = (st + dr) / 2, d = ld[nod], s = ls[nod];
//    ld[nod] = ls[nod] = 0;
//
//    t[nod << 1] += (m - st + 1) * (d + (dr - m) * s) +
//                (m - st + 1) * (m - st) / 2 * s;
//    ld[nod << 1] += d + (dr - m) * s;
//    ls[nod << 1] += s;
//
//    t[nod << 1 | 1] += (dr - m) * d +
//                (dr - m) * (dr - m - 1) / 2 * s
//    ld[nod << 1 | 1] += d;
//    ls[nod << 1 | 1] += s;
//}
//void Update_Add(int l, int r, int v, int nod = 1, int st = 1, int dr = V)
//{
//    if(l <= st && dr <= r)
//    {
//        t[nod] += (dr - st + 1) * v;
//        ld[nod] += v;
//        return;
//    }
//    Push(nod, st, dr);
//    int m = (st + dr) / 2;
//    if(l <= m)Update_Add(l, r, v, nod << 1, st, m);
//    if(r > m)Update_Add(l, r, v, nod << 1 | 1, m + 1, dr);
//    t[nod] = t[nod << 1] + t[nod << 1 | 1];
//}
//void Update_Delta()

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    FOR(i, 0, n + 1)l[i] = r[i] = 0;

    FOR(i, 1, n)b[i] = a[i] - i;

    deque<pair<ll, ll>> stk;
    int tot = 0;
    ///pair <value, count>

    FOR(i, 1, n)
    {
        ll c = 0, s = 0;
        while(!stk.empty() && stk.back().ff > b[i])
        {
            c += stk.back().ss;
            s += stk.back().ff * stk.back().ss;
            stk.pop_back();
        }

        l[i] += l[i - 1] + s - c * b[i];
        stk.pb({b[i], c + 1});
        tot ++;

        while(!stk.empty() && b[i] - stk.front().ff + tot - 1 >= a[i])
        {
            l[i] -= b[i] - stk.front().ff + tot - 1 - a[i];
            pii p = stk.front();
            stk.pop_front();
            if(--p.ss)stk.push_front(p);
            tot --;
        }
    }

    FOR(i, 1, n)b[i] = a[i] - (n - i + 1);
    stk = deque<pair<ll, ll>>();
    tot = 0;

    FORR(i, n, 1)
    {
        ll c = 0, s = 0;
        while(!stk.empty() && stk.back().ff > b[i])
        {
            c += stk.back().ss;
            s += stk.back().ff * stk.back().ss;
            stk.pop_back();
        }

        r[i] += r[i + 1] + s - c * b[i];
        stk.pb({b[i], c + 1});
        tot ++;

        while(!stk.empty() && b[i] - stk.front().ff + tot - 1 >= a[i])
        {
            r[i] -= b[i] - stk.front().ff + tot - 1 - a[i];
            pii p = stk.front();
            stk.pop_front();
            if(--p.ss)stk.push_front(p);
            tot --;
        }
    }


    ll mn = 0;
    FOR(i, 1, n)mn += a[i];
    FOR(i, 1, n)mn = min(mn,l[i] + a[i] + r[i]);

    cout << mn << '\n';
}

/// Check for interruption of input!!

signed main() {
    fastio();
    Precalc();
    int t=1;
    if (testCase) cin >> t;
    while (t--) solve_testcase();
      return 0;
}
