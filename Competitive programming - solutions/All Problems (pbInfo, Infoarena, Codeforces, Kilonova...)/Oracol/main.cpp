#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("oracol.in");
ofstream cout("oracol.out");
struct edges
{
    int a,b,cost;
};
bool f(edges a, edges b)
{
    return a.cost<b.cost;
}
vector<edges> v;
vector<int> t;
int n;
int Radacina(int x)
{
    int rad = x ,y;
    while(t[rad]!=rad)rad = t[rad];

    while(t[x]!=x)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }

    return rad;
}
void Unire(int rx,int ry)
{
    t[ry] = rx;
}
int main()
{
    int cost=0;
    cin>>n;
    t = vector<int>(n+2);
    for(int i=1;i<=n;++i)t[i]=i;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            cin>>cost;
            v.push_back({i,j,cost});
        }
    sort(v.begin(),v.end(),f);
    cost = 0;
    for(auto i : v)
    {
        int rx = Radacina(i.a);
        int ry = Radacina(i.b);
        if(rx!=ry)
        {
            //cout<<rx<<' '<<ry<<"      "<<i.a<<' '<<i.b<<' '<<i.cost<<'\n';
            cost+=i.cost;
            Unire(rx,ry);
        }
    }
    cout<<cost;
    return 0;
}
