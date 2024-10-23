#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("euro2.in");
ofstream cout("euro2.out");
const int N = 10009;
int n;
double aux[N];
int v[N],c[N];
int p1[N],p2[N],len;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>aux[i];
        v[i] = (aux[i] - 3) * 10000;
    }

    for(int i = 1; i <= n; ++i)
    {
        int pz = lower_bound(c,c+len,v[i]) - c;
        len += (pz == len);
        c[len] = v[i];
        p1[i] = pz + 1;
    }

    memset(c,0,sizeof(c));
    len = 0;

    for(int i = n; i >= 1; --i)
    {
        int pz = lower_bound(c,c+len,v[i]) - c;
        len += (pz == len);
        c[len] = v[i];
        p2[i] = pz + 1;
    }

    int ans = -7;
    for(int i = 1; i <= n; ++i)
        if(p1[i] > 1 && p2[i] > 1)
            ans = max(ans,p1[i] + p2[i] - 1);

    cout<<ans;
    return 0;
}
