#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("GCDP.in");
ofstream cout("GCDP.out");

const int N = 100009,L = 17;
long long n,ST[N][L],v[N],sleft[N],sright[N],lef[N],righ[N];
inline long long gcd(long long a,long long b)
{
    while(b)
    {
        long long aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}
void process()
{
    for(int i=1;i<=n;++i)
        ST[i][0] = v[i];
    for(int j = 1; 1<<j <= n;++j)
        for(int i=0;i+(1<<j) - 1 <= n; ++i)
            ST[i][j] = gcd(ST[i][j-1],ST[i + (1<<(j-1))][j-1]);
}
long long Query(int i,int j)
{
    int k = log2(j-i+1);
    return gcd(ST[i][k],ST[j - (1<<k) +1][k]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    process();
    for(int i=1;i<=n;++i)
    {
        int st = 1, dr = i, poz = -1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (Query(mid, i) > 1) {
                dr = mid - 1;
                poz = mid;
            }
            else st = mid + 1;
        }
        if (poz!=-1) lef[i] = i - poz + 1;
        st = i, dr = n, poz = -1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (Query(i, mid) > 1) {
                st = mid + 1;
                poz = mid;
            }
            else dr = mid - 1;
        }
        if (poz!=-1)  righ[i] = poz - i + 1;
    }
    for(int i=1;i<=n;++i)sleft[i] = sleft[i-1] + lef[i];
    for(int i=n;i>=1;--i)sright[i] = sright[i+1] + righ[i];
    for(int i=1;i<=n;++i)
        cout<<sleft[n] - sleft[i-1] - sright[i+1]<<' ';
    return 0;
}
