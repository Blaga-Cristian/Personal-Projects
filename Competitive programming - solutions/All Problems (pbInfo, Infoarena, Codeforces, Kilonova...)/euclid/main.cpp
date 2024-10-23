#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
using ull = unsigned long long;
ull cmmdc(ull a,ull b)
{
    while(b)
    {
        ull r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ull a,b;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
