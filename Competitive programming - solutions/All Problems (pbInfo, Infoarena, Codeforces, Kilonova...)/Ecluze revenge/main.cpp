#include <fstream>

using namespace std;
ifstream cin("ecluze.in");
ofstream cout("ecluze.out");
int n,x,h[1009];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        h[x]--;
    }
    int ans = 0x3f3f3f3f;
    for(int i=1;i<=1000;++i)
        ans = min(ans,h[i]);
    cout<<ans+n;
    return 0;
}
