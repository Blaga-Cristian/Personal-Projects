#include <fstream>

using namespace std;
ifstream cin("order.in");
ofstream cout("order.out");
const int Nmax = 30009;
int aib[Nmax]; /// un sir care tine nr de termeni pe care ii are inainte
int n,N;
void Update(int poz,int val)
{
    for(int i = poz; i <= N; i+=i&-i)
        aib[i]+=val;
}
int Sum(int poz)
{
    int sum = 0;
    for(int i = poz; i>0;i-=i&-i)
        sum+=aib[i];
    return sum;
}
int Cbinary(int poz)
{
    int st = 1, dr = N,mid = 0,nr = 0 ,mini = 0x3f3f3f3f;
    while(st<=dr)
    {
        mid = (st+dr)>>1;
        nr = Sum(mid);
        if(nr == poz && mid < mini)
            mini = mid;
        if(nr<poz)
            st = mid+1;
        else
            dr = mid-1;
    }
    return mini;
}
int main()
{
    cin>>n;
    N = n;
    for(int i=1;i<=n;++i)
        Update(i,1);
    int poz = 2;
    for(int i=1;i<=N;++i)
    {
        int p = Cbinary(poz);
        Update(p,-1);
        cout<<p<<' ';
        poz+=i;
        n--;

        if(n)
            poz = ((poz%n==0)? n : poz%n);
    }
    return 0;
}
