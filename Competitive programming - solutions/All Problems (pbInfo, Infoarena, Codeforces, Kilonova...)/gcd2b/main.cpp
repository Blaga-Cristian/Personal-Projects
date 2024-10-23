#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("gcd2.in");
ofstream cout("gcd2.out");
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 9;

int n,v[N],ST[N][21],ind,nxt;
ull ans;
inline int gcd(int a,int b)
{
    while(a)
    {
        int aux = a;
        a = b%a;
        b = aux;
    }
    return b;
}
void precalc()
{
    for(int i = 1; i <= n; ++i)
        ST[i][0] = v[i];

    for(int k = 1; 1 << k <= n; ++k)
        for(int i = 1; i + (1<<k) - 1 <= n; ++i)
            ST[i][k] = gcd(ST[i][k-1],ST[i + (1<<(k-1))][k-1]);
}
int getgcd(int a,int b)
{
    int lg = log2(b-a+1);
    return gcd(ST[a][lg],ST[b-(1<<lg)+1][lg]);
}
int cb(int i,int x)
{
    int st = i, dr = n, poz = n + 1,mj;
    while(st <= dr)
    {
        mj = (st+dr)>>1;
        if(getgcd(i,mj) < x)
        {
            poz = mj;
            dr = mj - 1;
        }
        else
            st = mj + 1;
    }
    return poz;
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    precalc();

    for(int i = 1; i <= n; ++i)
    {
        ind = i;
        while(ind <= n)
        {
            nxt = cb(i,getgcd(i,ind));
            ans += 1LL * (nxt - ind) * getgcd(i,ind);
            ind = nxt;
        }
    }

    cout<<ans;
    return 0;
}
