#include <fstream>
#include <tuple>
using namespace std;
ifstream cin ("ssm.in");
ofstream cout("ssm.out");
const int N = 6000005;
int n,st,dr,ans,s,smin,imin;
int v[N];
tuple<int,int,int> divetimp(int st,int dr)
{
    if(st==dr)
    {
        tuple<int,int,int> a;
        get<0>(a) = v[st];
        get<1>(a) = st;
        get<2>(a) = dr;
        return a;
    }
    int mij = (st+dr)>>1;

    auto a = divetimp(st,mij);
    auto b = divetimp(mij+1,dr);

    if(get<0>(a)>0 && get<0>(b)>0)
    {
        get<0>(a) += get<0>(b)>0;
        get<1>(a) = get<1>(a);
        get<2>(a) = get<2>(b);
    }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    auto ans = divetimp(1,n);
    cout<<get<0>(ans)<<' '<<get<1>(ans)<<' '<<get<2>(ans);
    return 0;
}
