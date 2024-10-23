#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("treasurehunt.in");
ofstream cout("treasurehunt.out");
const int N = 1e4 + 9;
int z,n,m,d,a,b,x,y;
int a[N],punct[N],urm[N];
struct element
{
    int x,y,h,p;
}v[N];
double dist(element x, element y)
{
    return sqrt(pow((x.x - y.x),2) + pow((x.y - y.y),2));
}
int main()
{
    cin>>z;
    cin>>n>>m>>d;
    for(int i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y>>v[i].h>>v[i].p;
    if(z==1)
    {
        double e = 0;
        double maxi = 0;
        for(int i=1;i<n;++i)
        {
            double dst = dist(v[i],v[i+1]);
            maxi = max(maxi,dst);
            if(v[i].h < v[i+1].h)
                e += dst + dst * (v[i+1].h - v[i].h) / 10;
            else
                e += dst + dst * (v[i].h - v[i+1].h) / 50;
        }
        int aux = maxi*100;
        cout<<aux/(100.0)<<'\n';
        aux = e*100;
        cout<<aux/(100.0);
    }
    else
    {
        a[n] = 0;
        punct[n] = 0;
        urm[n] = 0;
        int maxt = v[n-1].p;
        a[n-1] = 1;
        punct[n-1] = v[n-1].p;
        urm[n-1] = n;
        for(int i = n-2;i>1;--i)
        {
            for(int j = i+1;j<n;++j)
            {
                if(dist(v[i],v[j])>=d)
                {
                    a[i] = a[j] + 1;
                    punct[i] = punct[j] + v[i].p;
                    urm[i] = j;
                }
            }
        }
    }
    return 0;
}
