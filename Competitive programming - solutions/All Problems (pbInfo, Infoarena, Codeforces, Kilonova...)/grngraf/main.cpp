#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
ifstream cin("gengraf.in");
ofstream cout("gengraf.out");
bool v[106][106];
int main()
{
    int n;
    cin>>n;
    cout<<pow(2,n)<<'\n';
    for(long long i=0;i<pow(2,n);++i)
    {
        int nr=i;
        int a=2,b=1;
        while(nr!=0)
        {
            if(nr%2==1)
            {
                v[a][b]=v[b][a]=1;
            }
            b++;
            if(b==a)
            {
                    b=1;
                    a++;
            }
            nr>>=1;
        }
        for(int k=1;k<=n;++k)
        {
            for(int p=1;p<=n;++p)
            {
                cout<<v[k][p]<<' ';
            }
            cout<<'\n';
        }
        for(int k=1;k<=n;++k)
        {
            for(int p=1;p<k;++p)
            {
                v[k][p]=v[p][k]=0;
            }
        }
        cout<<'\n';
    }
    return 0;
}
