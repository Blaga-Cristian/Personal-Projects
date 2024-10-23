#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream cin("farfurii.in");
ofstream cout("farfurii.out");
ull n,k;
///O abordare greedy
ull comb(ull x)
{return x*(x-1)/2;}
ull bsearch2(ull x,ull n)
{
    int st = 1,dr = n,mij;
    while(st<dr)
    {
        mij = (st+dr)>>1;
        if(comb(mij) < x)
            st = mij+1;
        else
            dr = mij;
    }
    mij = (st+dr)>>1;
    if(comb(mij)<x)
        ++mij;
    return mij;
}
void solve(ull base,ull n,ull k)
{
    if(k==0)
    {
        for(int j=1;j<=n;++j)
            cout<<base+j<<' ';
        return;
    }
    int i = bsearch2(k,n);
    for(int j=1; j <= n - i; ++j)
        cout<<base + j<<' ';
    solve(base + n - i + 1,i-1,k-(i-1));
    cout<<base + n - i + 1 <<' ';
}
int main()
{
    cin>>n>>k;
    solve(0,n,k);
    return 0;
}
