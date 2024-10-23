#include <fstream>
#define mod
using namespace std;

ifstream f("transport.in");
ofstream g("transport.out");
const nmax=200005;
int x[nmax],d[nmax];
ll vec[2*nmax];
int main()
{
    int i;
    f>>t>>n>>c;
    for(i=0;i<n;i++)
    {
        f>>x[i]>>d[i];
    }
    if(t==1)
    {
        for(i=0;i<n;i++)
        {
            vec[2*i]=c*x[i]+d[i];
            vec[2*i+1]=c*x[i]-d[i];
        }
        for()
    }
    return 0;
}
