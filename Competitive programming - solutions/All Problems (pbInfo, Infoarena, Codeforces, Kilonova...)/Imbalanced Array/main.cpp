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

const int N = 1e6 + 9, LG = 20, V = 1e9 + 9, Mod = 998244353;

int n;

struct node
{
    int c, ls;
    bool sw;
    ///sw se efectueaza mereu primul

    node()
    {
        c = 0;
        ls = -1;
        sw = 0;
    }

    node *l, *r;
};

node* root = new node();

void Push(node* t, int st, int dr)
{
    if(t == NULL)
    {
        cout << "FOUND ERROR\n";
        return;
    }

    if(st == dr)return;
    int m = (st + dr) >> 1;

    if(!(t -> l))t -> l = new node();
    if(!(t -> r))t -> r = new node();

    if(t -> sw)
    {
        t -> l -> c = m - st + 1 - t -> l -> c;
        if(t -> l -> ls != -1)t -> l -> ls ^= 1;
        t -> l -> sw ^= 1;

        t -> r -> c = dr - m - t -> r -> c;
        if(t -> r -> ls != -1)t -> r -> ls ^= 1;
        t -> r -> sw ^= 1;

        t -> sw = 0;
    }

    if(t -> ls != -1)
    {
        if(t -> ls == 1)
        {
            t -> l -> c = m - st + 1;
            t -> l -> ls = 1;
            t -> r -> c = dr - m;
            t -> r -> ls = 1;
        }
        else
        {
            t -> l -> c = 0;
            t -> l -> ls = 0;
            t -> r -> c = 0;
            t -> r -> ls = 0;
        }

        t -> ls = -1;
    }
}

void Update_Set(int l, int r, int v, node* t = root, int st = 1, int dr = V)
{
    if(l <= st && dr <= r)
    {
        t -> ls = v;
        if(v == 1)t -> c = dr - st + 1;
        else t -> c = 0;
        return;
    }
    Push(t, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update_Set(l, r, v, t -> l, st, m);
    if(r > m)Update_Set(l, r, v, t -> r, m + 1, dr);
    t -> c = t -> l -> c + t -> r -> c;
}
void Update_Swap(int l, int r, node* t = root, int st = 1, int dr = V)
{
    if(l <= st && dr <= r)
    {
        t -> c = dr - st + 1 - t -> c;
        if(t -> ls != -1)t -> ls ^= 1;
        t -> sw ^= 1;
        return;
    }
    Push(t, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update_Swap(l, r, t -> l, st, m);
    if(r > m)Update_Swap(l, r, t -> r, m + 1, dr);
    t -> c = t -> l -> c + t -> r -> c;
}
int Query(node* t = root, int st = 1, int dr = V)
{
    if(st == dr)return st;
    Push(t, st, dr);
    int m = (st + dr) >> 1;
    if(t -> l -> c != m - st + 1)return Query(t -> l, st, m);
    return Query(t -> r, m + 1, dr);
}

int main()
{
    cin >> n;

    int t, l, r;
    FOR(i, 1, n)
    {
        cin >> t >> l >> r;

        if(t == 1)Update_Set(l, r, 1);
        else if(t == 2)Update_Set(l, r, 0);
        else Update_Swap(l, r);

        if(root -> c == V)cout << V + 1 << '\n';
        else cout << Query() << '\n';
    }
    return 0;
}
