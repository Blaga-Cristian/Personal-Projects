#include <fstream>
#include <vector>
using namespace std;
ifstream f("pluricex1.in");
ofstream g("pluricex1.out");
int n,k,d,mask[23],b[23];
vector<int> v[23];
void afisare()
{
    for(int i=1;i<=k;++i)g<<b[i]<<" ";
    g<<'\n';
}
void backt(int x,int ist,int sum)
{
    if(x==k+1&&sum==(1<<d)-1)afisare();
    else
    {
        for(int i=ist;i<=n;++i)
        {
           b[x]=i;
           backt(x+1,i+1,(sum|mask[i]));
        }
    }
}
int main()
{
    int nr,x;
    f>>n>>k>>d;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        for(int j=1;j<=nr;++j)
        {
            f>>x;
            v[i].push_back(x);
            mask[i]+=1<<(x-1);
        }
    }
    backt(1,1,0);
    return 0;
}
