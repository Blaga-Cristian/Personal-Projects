#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("ninjago.in");
ofstream cout("ninjago.out");
const int Inf = 0x3f3f3f3f;
int v,n,m,cnt1;
struct element
{
    int nod,cntE,cost;
};
struct muchie
{
    int a,b,cntE,cost;
};
vector<vector<element> > sirad;
vector<muchie>Kru;
vector<int> T;
vector<bool> viz;
bool f(muchie a, muchie b)
{
    if(a.cntE<b.cntE)return true;
    if(a.cntE==b.cntE&&a.cost<b.cost)return true;
    return false;
}
void dfs(int x)
{
    viz[x] = true;
    cnt1++;
    for(auto i:sirad[x])
        if(viz[i.nod]==false&&i.cntE==0)dfs(i.nod);
}
int Radacina(int x)
{
    int rad=x,y;
    while(T[rad]!=0)rad = T[rad];

    while(x != rad)
    {
        y = T[x];
        T[x] = rad;
        x = y;
    }
    return rad;
}
void Unire(int rx,int ry)
{
    T[ry] = rx;
}
int main()
{
    char s[255];
    int a,b,c,cnt;
    cin>>v>>n>>m;
    T = vector<int>(n+1);
    sirad = vector<vector<element> >(n+1);
    cin.get();
    for(int i=1;i<=m;++i)
    {
        c=0;
        cnt=0;
        cin>>a>>b;
        cin.get();
        cin.get(s,255);
        cin.get();
        for(int j=0;j<4;++j)
        {
            if(s[j]=='E')++cnt;
            else if(s[j]=='A')c = c + 1*pow(5,j);
            else if(s[j]=='B')c = c + 2*pow(5,j);
            else if(s[j]=='C')c = c + 3*pow(5,j);
            else if(s[j]=='D')c = c + 4*pow(5,j);
        }
        //cout<<c<<endl;
        sirad[a].push_back({b,cnt,c});
        sirad[b].push_back({a,cnt,c});
        Kru.push_back({a,b,cnt,c});
    }
    if(v==1)
    {
        viz  = vector<bool>(n+1);
        dfs(1);
        cout<<cnt1;
    }
    else
    {
        long long energie = 0;
        cnt1 = 0;
        int nrajut = 0;
        sort(Kru.begin(),Kru.end(),f);
        for(auto i:Kru)
        {
            int rx = Radacina(i.a);
            int ry = Radacina(i.b);
            if(rx!=ry)
            {
                if(i.cntE)nrajut++;
                cnt1+=i.cntE;
                energie += i.cost;
                Unire(rx,ry);
            }
        }
        if(v==2)
        {
            cout<<nrajut<<'\n';
            cout<<cnt1;
        }
        else cout<<energie;
    }
    return 0;
}
