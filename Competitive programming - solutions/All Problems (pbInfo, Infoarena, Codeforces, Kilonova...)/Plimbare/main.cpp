#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("plimbare1.in");
ofstream cout("plimbare1.out");
struct muchie
{
    int x,y,cost;
    muchie (int& a,int& b,int& c)
    {
        x = a;
        y = b;
        cost = c;
    }
};
bool cmp(muchie a,muchie b)
{
    return a.cost<b.cost;
}
vector<muchie> v;
vector<int>t;
long long total;
inline int Radacina(int x)
{
    int rad = x, y;
    while(t[rad]!=rad)rad=t[rad];

    while(t[x]!=x)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
inline void Unire(int rx,int ry)
{
    t[rx] = ry;
}
int n,m;
int main()
{
    int c,a,b,cost;
    cin>>n>>m;
    t.resize(n+1);
    for(int i=1;i<=n;++i)t[i]=i;
    for(int i=1;i<=m;++i)
    {
        cin>>c;
        if(c==1)
        {
            cin>>a>>b;
            Unire(Radacina(a),Radacina(b));
        }
        else
        {
            cin>>a>>b>>c;
            v.emplace_back(a,b,c);
        }
    }
    int r1,r2;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();++i)
    {
        r1 = Radacina(v[i].x);
        r2 = Radacina(v[i].y);
        if(r1==r2)continue;
        total+=v[i].cost;
        Unire(r1,r2);
    }
    cout<<total;

    return 0;
}
