#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Mod;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

template <typename T>
struct CompressedSegmentTreeSum
{
    vector<T> t;
    vector<T> d; /// l = lazy;
    int h, n;

    CompressedSegmentTreeSum(int n = 0) : n(n), h(sizeof(int) * 8 - __builtin_clz(n)),
    t(vector<T>(2 * n, T())), d(n, T())
    {}

    void clear()
    {
        h = n = 0;
        t.clear();
        d.clear();
    }

    void build(vector<T> const& vec)
    {
        for(int i = 0; i < n; ++i)t[i + n] = vec[i];
        for(int i = n - 1; i > 0; --i)t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void build(T* arr)
    {
        for(int i = 0; i < n; ++i)t[i + n] = arr[i];
        for(int i = n - 1; i > 0; --i)t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void apply(int p, T value)
    {
        t[p] += value;
        if(p < n)d[p] += value;
    }

    void build(int p)
    {
        while(p > 1) p >>= 1, t[p] = t[p << 1] + t[p << 1 | 1] + d[p];
    }

    void push(int p)
    {
        for(int s = h; s > 0; --s)
        {
            int i = p >> s;
            if(d[i] != 0)
            {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }

    void update_intern(int l, int r, T value)
    {
        l += n, r += n;
        int l0 = l, r0 = r;
        for(; l < r; l >>= 1, r >>= 1)
        {
            if(l&1)apply(l ++, value);
            if(r&1)apply(-- r, value);
        }
        build(l0);
        build(r0 - 1);
    }

    T query_intern(int l, int r)
    {
        l += n, r += n;
        push(l);
        push(r - 1);
        T res = (T)0;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l&1) res += t[l ++];
            if (r&1) res += t[-- r];
        }
        return res;
    }

    void update(int l, int r, T value){update_intern(l - 1, r, value);}

    T query(int l, int r){return query_intern(l - 1, r);}

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


const ll N = 2e5 + 9;

int n, q, a[N];

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];
    CompressedSegmentTreeSum<int> s(n);
    s.build(a + 1);

//    q = 99;
//    int op, l, r, val;
//    while(q --)
//    {
//        cin >> op >> l >> r;
//        if(op == 1)///Query
//            cout << s.query(l, r) << '\n';
//        else
//        {
//            cin >> val;
//            s.update(l, r, val);
//        }
//    }

    FOR(i, 0, 2 * n - 1)cout << s.t[i] << ' ';
    cout << '\n';

    s.update(1, 3, 3);

    FOR(i, 0, 2 * n - 1)cout << s.t[i] << ' ';
    cout << '\n';
}

/// Check for interruption of input!!

int main() {
    int t=1;
    while (t--) solve_testcase();
      return 0;
}
