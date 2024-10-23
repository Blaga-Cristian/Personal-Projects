#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("prim.in");
ofstream cout("prim.out");

const int Inf = 0x3f3f3f3f;
//int tata[100000];
bool viz[100000];
vector<vector<pair<int,int> > >c;
vector<int > D;
int n,m,S=0;
void Prim()
{
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > >q;
    for(auto x:c[1])
    {
        //tata[x.second]=1;
        D[x.second]=x.first;
        q.emplace(x);
    }
    while(!q.empty())
    {
        pair<int,int> P = q.top();
        q.pop();

        if(viz[P.second]==true)continue;

        viz[P.second]=true;
        S+=P.first;

        for(auto i:c[P.second])
        {
            if(!viz[i.second]&&D[i.second]>i.first)
            {
                D[i.second] = i.first;
                //tata[i.second]=P.second;
                q.emplace(i);
            }
        }
    }
}
int main()
{
    int a,b,w;
    cin>>n>>m;
    c= vector<vector<pair<int,int> > >(n+1);
    D.resize(n+1,Inf);
    viz[1]=true;
    D[1]=0;
    //tata[1]=0;
    while(m--)
    {
        cin>>a>>b>>w;
        c[a].emplace_back(w,b);
        c[b].emplace_back(w,a);
    }
    Prim();
    cout<<S<<'\n';
    for(int i=1;i<=n;++i)
    {
        //cout<<tata[i]<<' ';
    }
    return 0;
}
