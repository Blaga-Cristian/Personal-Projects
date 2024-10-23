#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
using namespace std;
const int N = 100009;
int n,v[N],norm[N],arb[5*N];
char sgn[N];
int dp[N]; ///dp[i] = lungimea sirului care se termina in el de lungime i
map<int,int> mp;
void Update(int nod,int st,int dr,int poz,int val)
{
    if(st==dr)
    {
        arb[nod] = max(arb[nod],val);
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        Update(2*nod,st,mij,poz,val);
    else
        Update(2*nod+1,mij+1,dr,poz,val);

    arb[nod] = max(arb[2*nod],arb[2*nod+1]);
}
int Query(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
        return arb[nod];
    int mij = (st+dr)>>1;
    if(a<=mij&&b>mij)
        return max(Query(2*nod,st,mij,a,b),Query(2*nod+1,mij+1,dr,a,b));
    else if(a>mij)
        return Query(2*nod+1,mij+1,dr,a,b);
    else
        return Query(2*nod,st,mij,a,b);
}
int main()
{
    int ans = 0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i]>>sgn[i],dp[i]=1,norm[i] = v[i];

    ///normalizare
    sort(norm+1,norm+n+1);
    int maxi = 1,nr=norm[1];
    mp[norm[1]] = 1;
    for(int i=1;i<=n;++i)
    {
        if(nr<norm[i])
        {
            nr = norm[i];
            ++maxi;
            mp[nr] = maxi;
        }
    }
    for(int i=1;i<=n;++i)
        v[i] = mp[v[i]];


    for(int i=n;i>=1;--i)
    {
        if(sgn[i]=='>')
            if(v[i]+1<=maxi)
                dp[i] = Query(1,1,n,v[i]+1,maxi)+1;
        if(sgn[i]=='<')
            if(v[i]-1>=1)
                dp[i] = Query(1,1,n,1,v[i]-1)+1;
        Update(1,1,n,v[i],dp[i]);

        ans = max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
