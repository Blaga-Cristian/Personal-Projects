#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("zapada.in");
ofstream cout("zapada.out");
struct muchie
{
    int x,y,cost;
};
bool f(muchie a,muchie b)
{
    return a.cost<b.cost;
}
muchie v[105];
long long total;
int t[1000],n,m;
bool fol[1000];
int Radacina(int x)
{
    int rad=x,y;
    while(rad != t[rad])rad = t[rad];

    while(t[x]!=rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }

    return rad;

}
void Unire(int rx,int ry)
{
    t[rx] = ry;
}
int main()
{
    int x,k;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>v[i].x>>v[i].y>>v[i].cost;
    }
    for(int i=1;i<=n;++i)t[i]=i;
    sort(v+1,v+m+1,f);
    for(int i=1;i<=m;++i)
    {
        int r1 = Radacina(v[i].x);
        int r2 = Radacina(v[i].y);
        if(r1!=r2)
        {
            total += v[i].cost;
            Unire(r1,r2);
        }
    }
    cout<<total;
    return 0;
}
