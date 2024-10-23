#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream cin("harta3.in");
ofstream cout("harta3.out");

const int Inf = 0x3f3f3f3f;
vector<pair<int,int> >pos;
int n;
double D[1000];
bool viz[1000];
double S=0;
double dist(pair<int,int> a,pair<int,int> b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}
void Prim(int x)
{
    priority_queue<pair<double,int> , vector<pair<double,int> > , greater<pair<double,int> > >q;
    D[x]=0;
    viz[x]=true;
    for(int i=2;i<=n;++i)
    {
        D[i] = dist(pos[x],pos[i]);
        q.emplace(dist(pos[x],pos[i]),i);
    }
    while(!q.empty())
    {
        pair<double,int> P=q.top();
        q.pop();

        if(viz[P.second]==true)continue;

        S+=P.first;
        viz[P.second]=true;

        for(int i=1;i<=n;++i)
        {
            if(viz[i]==false&&D[i]>dist(pos[P.second],pos[i]))
            {
                D[i] = dist(pos[P.second],pos[i]);
                q.emplace(dist(pos[P.second],pos[i]),i);
            }
        }
    }
}
int main()
{
    int a,b,w;
    cin>>n;
    pos = vector<pair<int,int> >(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>pos[i].first>>pos[i].second;
        D[i] = Inf;
    }
    Prim(1);
    cout<<fixed<<setprecision(10)<<S;
    return 0;
}
