#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("ssce.in");
ofstream cout("ssce.out");
const int COD = 5555, N = 10009;
int n,b,k,mx,t,u,p,mn,r;
int v[4],w[4],P[] = {1,10,100,1000,10000,100000};
int x[N],y[N];
int d[5555],e[5555];
void nrcif(int x,int v[4])
{
    memset(v,0,16);
    if(x==0)
    {
        v[0] = 1;
        return;
    }
    while(x)
    {
        v[x%10] ++;
        x/=10;
    }
}
bool verif(int v[4])
{
    int i;
    bool ok = 0;
    for(i=0;i<b;++i)
    {
        if(v[i]==0)
            ok = 1;
        for(int j=0;j<i;++j)
            if(v[i] - v[j] > k || v[j] - v[i] > k)
                return 0;
    }
    return ok;
}
bool normalizare(int v[4])
{
    int mn = 99999;
    for(int i=0;i<b;++i)
        mn = min(mn,v[i]);
    for(int i=0;i<b;++i)
    {
        v[i]-=mn;
        if(v[i] > k)return 0;
    }
    return 1;
}
int cod(int v[4])
{
    int i = 0;
    mn = v[0];
    for(int i=1;i<b;++i)
        mn = min(mn,v[i]);

    r = 0;
    for(int i=0;i<b;++i)
        r += (v[i]-mn)*P[i];

    return r;
}
int main()
{
    cin>>n>>b>>k;
    for(int i=1;i<=n;++i)
        cin>>x[i];

    mx = 0;
    for(int i=1;i<=b;++i)
        mx = mx*10 + k;

    for(int i=0; i <= mx; ++i)
    {
        t = i;
        for(int j=0;j<b;++j)
            v[j] = t%10,
            t = t/10;
        if(verif(v))
            y[++u] = i;
    }

    d[0] = e[0] = 1;

    for(int i=1;i<=n;++i)
    {
        memcpy(d,e,sizeof(d));
        nrcif(x[i],w);
        for(int j=1;j<=u;++j)
        {
            if(d[y[j]] == 0)
                continue;
            memcpy(v,w,16);

            t = y[j];
            p = 0;
            while(t)
            {
                v[p++] = t%10;
                t /= 10;
            }

            if(normalizare(v))
            {
                int c = cod(v);
                e[c] = max(e[c],d[y[j]] + 1);
            }
        }
    }
    cout<<e[0]-1;
    return 0;
}
