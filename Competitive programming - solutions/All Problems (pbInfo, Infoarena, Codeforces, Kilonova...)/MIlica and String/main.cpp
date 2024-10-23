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

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
const string TASK("trie");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
int di[]={0,0,-1,1},dj[]={-1,1,0,0};
int d8i[]={-1,-1,-1,0,0,1,1,1},d8j[]={-1,0,1,-1,1,-1,0,1};
const int Inf = 0x3f3f3f3f;
bool testCase = true;
const ll N = 1009;

int n, m;
pii start;
bool blocked[N][N];
char s[N];

int d[N][N];

int cntviz[N][N], sumdist[N][N], dist[N][N];
pii lastviz[N][N];

bool inmat(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void solve_testcase()
{
    cin >> n >> m;

    start = {0, 0};
    FOR(i, 1, n)
        FOR(j, 1, m)
            blocked[i][j] = false;

    int cnt_blocks = 0;
    FOR(i, 1, n)
    {
        cin >> (s + 1);
        FOR(j, 1, m)
            if(s[j] == 'V')
                start = {i, j};
            else if(s[j] == '#')
            {
                blocked[i][j] = true;
                cnt_blocks ++;
            }
    }


    FOR(i, 1, n)
        FOR(j, 1, m)
            d[i][j] = Inf;
    queue<pii> q;
    q.push(start);
    d[start.ff][start.ss] = 1;
    while(!q.empty())
    {
        int x = q.front().ff, y = q.front().ss;
        q.pop();

        for(int k = 0; k < 4; ++k)
        {
            int nx = x + di[k], ny = y + dj[k];

            if(!inmat(nx, ny) || blocked[nx][ny])continue;

            if(d[nx][ny] > d[x][y] + 1)
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int cnt_escapes = 0;
    FOR(j, 1, m)cnt_escapes += (d[1][j] != Inf) + (d[n][j] != Inf);
    FOR(i, 2, n - 1)cnt_escapes += (d[i][1] != Inf) + (d[i][m] != Inf);


    if(cnt_escapes == 0)
    {
        cout << n * m - cnt_blocks - 1 << '\n';
    }
    else if(cnt_escapes == 1)
    {
        int dmin = Inf;
        FOR(j, 1, m)dmin = min(dmin, min(d[1][j], d[n][j]));
        FOR(i, 2, n - 1)dmin = min(dmin, min(d[i][1], d[i][m]));

        cout << n * m - cnt_blocks - dmin << '\n';
    }
    else
    {
        queue<pii> q;
        FOR(j, 1, m)
        {
            if(d[1][j] != Inf)
            {
                cntviz[1][j] = 1;
                lastviz[1][j] = {1, j};
                q.push({1, j});
            }
            if(d[n][j] != Inf)
            {
                cntviz[n][j] = 1;
                lastviz[n][j] = {n, j};
                q.push({n, j});
            }
        }
        FOR(i, 2, n - 1)
        {
            if(d[i][1] != Inf)
            {
                cntviz[i][1] = 1;
                lastviz[i][1] = {i, 1};
                q.push({i, 1});
            }
            if(d[i][m] != Inf)
            {
                cntviz[i][m] = 1;
                lastviz[i][m] = {i, m};
                q.push({i, m});
            }
        }

        while(!q.empty())
        {
            int x = q.front().ff, y = q.front().ss;
            q.pop();

            for(int k = 0; k < 4; ++k)
            {
                int nx = x + di[k], ny = y + dj[k];

                if(!inmat(nx, ny) || blocked[nx][ny] || cntviz[nx][ny] == 2 || lastviz[nx][ny] == mp(x, y))continue;

                cntviz[nx][ny] ++;
                lastviz[nx][ny] = {x, y};
                sumdist[nx][ny] += d[x][y] + 1;
                dist[nx][ny] = dist[x][y] + 1;

                q.push({nx, ny});
            }
        }

        int ans = 0;
        FOR(i, 1, n)
            FOR(j, 1, m)
                if(!blocked[i][j])
                    ans = max(ans, n * m - cnt_blocks - d[i][j] - sumdist[i][j]);

        FOR(i, 1, n)
            FOR(j, 1, m)
            {
                cout << i << ' ' << j << " has sumdist " << sumdist[i][j] << '\n';
                cout << '\n';
            }

        cout << ans << '\n';
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
