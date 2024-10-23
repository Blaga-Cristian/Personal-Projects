//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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



const int N = 2e5 + 9, Mod = 998244353;

int n;

struct rect
{
    int a, b, c, d, ind;
};
vector<rect> v;

inline bool divide(vector<rect>& a)
{
    if(a.size() <= 2)return true;

    int init = a.size();

    int n = a.size();

    unordered_map<int, bool> erased;

    vector<rect> aux;
    multiset<int> er;

    sort(a.begin(), a.end(), [](rect x, rect y){return x.a < y.a;});

    er.insert(a[0].c);
    for(auto it = a.begin() + 1; it != a.end(); ++it)
    {
        while(!er.empty() && *er.begin() <= it -> a)
            er.erase(er.begin());

        if(er.empty() && distance(a.begin(), it) <= n / 2)
        {
            vector<rect> nxt;
            int p;
            for(p = distance(a.begin(), it); p >= 0 && !erased[a[p].ind]; --p)
            {
                nxt.pb(a[p]);
                erased[a[p].ind] = true;
            }
            if(!divide(nxt))
            {
                for(++ p; p <= distance(a.begin(), it); ++p)
                    erased[a[p].ind] = false;
            }
        }

        er.insert(it -> c);
    }

    aux.clear();
    for(auto e : a)if(!erased[e.ind])aux.pb(e);
    swap(a, aux);

    n = a.size();
    if(n <= 2)return true;

    sort(a.begin(), a.end(), [](rect x, rect y){return x.c > y.c;});

    er.clear();
    er.insert(a[0].a);
    for(auto it = a.begin() + 1; it != a.end(); ++it)
    {
        while(!er.empty() && *er.begin() >= it -> c)
            er.erase(er.begin());

        if(er.empty() && distance(a.begin(), it) <= n / 2)
        {
            vector<rect> nxt;
            int p;
            for(p = distance(a.begin(), it); p >= 0 && !erased[a[p].ind]; --p)
            {
                nxt.pb(a[p]);
                erased[a[p].ind] = true;
            }
            if(!divide(nxt))
            {
                for(++ p; p <= distance(a.begin(), it); ++p)
                    erased[a[p].ind] = false;
            }
        }

        er.insert(it -> a);
    }

    aux.clear();
    for(auto e : a)if(!erased[e.ind])aux.pb(e);
    swap(a, aux);

    n = a.size();
    if(n <= 2)return true;

    sort(a.begin(), a.end(), [](rect x, rect y){return x.b < y.b;});

    er.clear();
    er.insert(a[0].d);
    for(auto it = a.begin() + 1; it != a.end(); ++it)
    {
        while(!er.empty() && *er.begin() <= it -> b)
            er.erase(er.begin());

        if(er.empty() && distance(a.begin(), it) <= n / 2)
        {
            vector<rect> nxt;
            int p;
            for(p = distance(a.begin(), it); p >= 0 && !erased[a[p].ind]; --p)
            {
                nxt.pb(a[p]);
                erased[a[p].ind] = true;
            }
            if(!divide(nxt))
            {
                for(++ p; p <= distance(a.begin(), it); ++p)
                    erased[a[p].ind] = false;
            }
        }

        er.insert(it -> d);
    }

    aux.clear();
    for(auto e : a)if(!erased[e.ind])aux.pb(e);
    swap(a, aux);

    n = a.size();
    if(n <= 2)return true;

    sort(a.begin(), a.end(), [](rect x, rect y){return x.d > y.d;});

    er.clear();
    er.insert(a[0].b);
    for(auto it = a.begin() + 1; it != a.end(); ++it)
    {
        while(!er.empty() && *er.begin() >= it -> d)
            er.erase(er.begin());

        if(er.empty() && distance(a.begin(), it) <= n / 2)
        {
            vector<rect> nxt;
            int p;
            for(p = distance(a.begin(), it); p >= 0 && !erased[a[p].ind]; --p)
            {
                nxt.pb(a[p]);
                erased[a[p].ind] = true;
            }

            if(!divide(nxt))
            {
                for(++ p; p <= distance(a.begin(), it); ++p)
                    erased[a[p].ind] = false;
            }
        }

        er.insert(it -> b);
    }

    aux.clear();
    for(auto e : a)if(!erased[e.ind])aux.pb(e);
    swap(a, aux);

    if(a.size() == init)return false;
    return divide(a);
}

int main()
{
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
        v[i].ind = i;
    }

    if(divide(v))cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
