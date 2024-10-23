#include <fstream>
#define ull unsigned long long
#define ll long long
#define Nmax 1000001
#define M 666013
using namespace std;
ifstream cin("nmult.in");
ofstream cout("nmult.out");
int n,k,w,s=0;
char v[Nmax];
int p[Nmax/10],nr=0,desc[Nmax/10];
void ciur(int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            p[++nr]=i;
            for(j=i+i;j<=n;j+=i)v[j]=1;
        }
    }
}
void dsc(int x,int op)
{
    ll i,s=0,pp,ok;
    for(i=1;i<=nr;i++)
    {
        s=0;
        pp=p[i];
        ok=1;
        while(ok)
        {
            s=s+x/pp;
            if(x/pp==0)ok=0;
            else pp=pp*p[i];
        }
        if(op==1)desc[i]+=s;
        else desc[i]-=s;
    }
}
int mdl()
{
    ll i,j,pp=1,r=1;
    for(i=1;i<=nr;i++)
    {
        pp=1;
        for(j=1;j<=desc[i];j++)
        {
            pp=(pp*p[i])%M;
        }
        r=(r*pp)%M;
    }
    return r;
}
int main()
{
    cin>>n>>k>>w;
    ciur(n-(k-1)*(w-1));
    dsc(n-(k-1)*(w-1),1);
    dsc(k,0);
    dsc(n-(k-1)*(w-1)-k,0);
    if(n-(k-1)*(w-1)<k)cout<<"0"<<" ";
    else cout<<mdl();
    return 0;
}
