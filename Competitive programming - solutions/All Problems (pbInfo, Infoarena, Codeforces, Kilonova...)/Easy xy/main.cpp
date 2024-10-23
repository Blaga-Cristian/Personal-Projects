#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("easyxy.in");
ofstream cout("easyxy.out");
const int N = 1e5 + 9;
int n,m,x,y,p,block;
int v[N],aux[N];
struct queri
{
    int ind,x,y,p,ans;
};
inline bool cmp(queri a, queri b)
{
    if(a.x / block == b.x / block)
        return a.y < b.y;
    return a.x < b.x;
}
inline bool cmp2(const queri& a,const queri& b){return a.ind < b.ind;}
vector<queri> queries;
int aib[N];
void update(int x,int val)
{
    for(;x <= n; x += x&-x)
        aib[x] += val;
}
int query(int x)
{
    int ret = 0;
    for(;x; x -= x&-x)
        ret += aib[x];
    return ret;
}
int blift(int s)
{
    int pos = 0, sum = 0;
    int step = 1;
    for(;step < n; step <<= 1);
    for(;step; step >>= 1)
        if(pos + step <= n && sum + aib[pos + step] < s)
        {
            sum += aib[pos+step];
            pos += step;
        }
    return pos + 1;
}
void Add(int i){update(v[i],1);}
void Del(int i){update(v[i],-1);}
int main()
{
    cin>>n>>m;
    block = sqrt(n);
    for(int i = 1; i <= n; ++i)
        cin>>v[i],aux[i] = v[i];

    ///NORMALIZARE
    sort(aux + 1,aux+n+1);
    int sf = unique(aux+1,aux+n+1) - aux;
    for(int i=1;i<=n;++i)
        v[i] = lower_bound(aux+1,aux+sf,v[i]) - aux;

    for(int i = 1; i <= m; ++i)
    {
        cin>>x>>y>>p;
        queries.push_back({i,x,y,p,0});
    }

    sort(queries.begin(),queries.end(),cmp);

    int st = 1,dr = 0;
    for(auto& i : queries)
    {
        int s = i.x, d = i.y;

        while(st > s)Add(--st);
        while(dr < d)Add(++dr);
        while(st < s)Del(st++);
        while(dr > d)Del(dr--);

        i.ans = aux[blift(i.p - s + 1)];
    }

    sort(queries.begin(),queries.end(),cmp2);

    for(auto i : queries)
        cout<<i.ans<<'\n';
    return 0;
}
