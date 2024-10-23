#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
ifstream cin("median_query.in");
ofstream cout("median_query.out");
const int N = 1e5 + 9;
int n,q,l,r,a,b,x,y,v[N],aux[N],block;
int aib[N];
int res[N];
struct query
{
    int st,dr,ind;
};
inline bool cmp(query a, query b)
{
    if(a.st / block == b.st / block)
        return a.dr < b.dr;
    return a.st < b.st;
}
vector<query>queries;
void update(int x,int val)
{
    for(;x <= n; x += x&-x)
        aib[x]+=val;
}
int cbaib(int s)
{
    int sum = 0;
    int pos = 0;
    int step = (1<<17);

    for(;step;step>>=1)
        if(pos + step <= n && sum + aib[pos + step] < s)
    {
        sum += aib[pos + step];
        pos += step;
    }
    return pos + 1;
}
void Add(int x){update(v[x],1);};
void Del(int x){update(v[x],-1);};
int main()
{
    cin>>n>>q;
    block = sqrt(n);
    for(int i=1;i<=n;++i)
        cin>>v[i],aux[i] = v[i];

    ///NORMALIZARE
    sort(aux + 1,aux+n+1);
    int sf = unique(aux+1,aux+n+1) - aux;
    for(int i=1;i<=n;++i)
        v[i] = lower_bound(aux+1,aux+sf,v[i]) - aux;

    for(int i=1;i<=q;++i)
    {
        cin>>a>>b;
        queries.push_back({a,b,i});
    }

    //sort(queries.begin(),queries.end(),cmp);

    int st = 1,dr = 0;
    for(auto i : queries)
    {
        int s = i.st,d = i.dr;

        while(dr < d)Add(++dr);
        while(dr > d)Del(dr--);
        while(st < s)Del(st++);
        while(st > s)Add(--st);

        int med = (d - s + 2)/2;
        res[i.ind] = aux[cbaib(med)];
    }

    for(int i=1;i<=q;++i)
        cout<<res[i]<<'\n';
    return 0;
}
