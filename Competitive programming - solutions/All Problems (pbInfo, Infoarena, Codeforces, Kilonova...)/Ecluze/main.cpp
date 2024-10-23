#include <fstream>

using namespace std;
ifstream cin("ecluze.in");
ofstream cout("ecluze.out");
const int N = 100009, Inf = 0x3f3f3f3f;
int n,v[N];
int Min[N],last[N],urm[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i],
        Min[i] = Inf;

    for(int i=n;i>0;--i)
        if(last[v[i]] == 0)last[v[i]] = i;
        else
            urm[i] = last[v[i]],
            last[v[i]] = i;

    Min[1] = 0;
    for(int i=1;i<=n;++i)
    {
        if(i>1) Min[i] = min(Min[i],Min[i-1] + 1);
        if(urm[i])Min[urm[i]] = min(Min[urm[i]], Min[i] + (urm[i] - i - 1));
    }
    cout<<Min[n];
    return 0;
}
