#include <fstream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
ifstream cin("distanta.in");
ofstream cout("distanta.out");

vector<string>orase;
stack<int> st,ans;
vector<int> to,dist;
vector<bool> viz;
vector<int> tata;
vector<vector<pair<int,int>> >sirad;
int mini=999999999;
int n,m,x,y;
char p[255],q[255];
int src(string s)
{
    for(int i=1;i<=n;++i)
        if(s==orase[i])return i;
}
void Bfs(int y)
{
    queue<int> q;
    dist[y] = to[y];
    tata[y] = y;
    q.push(y);
    while(!q.empty())
    {
        int a = q.front();
        //cout<<a<<' ';
        q.pop();

        for(auto i : sirad[a])
        {
            int aux = dist[a] + i.second + to[i.first];
            if(dist[i.first]== 2147483647||dist[i.first]>=aux)
            {
                dist[i.first]=aux;
                tata[i.first]=a;
                q.emplace(i.first);
            }
        }
    }
}
int main()
{
    cin>>n;
    orase = vector<string>(1LL*n+1);
    to = dist = vector<int>(1LL*n+1);
    for(int i=0;i<=n;++i)dist[i] = 2147483647;
    sirad = vector<vector<pair<int,int>> >(1LL*n+1);
    viz = vector<bool>(1LL*n+1);
    tata = vector<int>(1LL*n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>orase[i]>>to[i];
    }
    cin>>m;
    char s1[255] ,s2[255] ;
    int c;
    for(int i=1;i<=m;++i)
    {
        cin>>s1>>s2>>c;
        int x = src(s1);
        int y = src(s2);
        sirad[x].emplace_back(y,c);
        sirad[y].emplace_back(x,c);
    }
    cin>>p>>q;
    x = src(p);
    y = src(q);
    //cout<<x<<' '<<y<<endl;
    Bfs(y);
    cout<<endl;
    if(dist[x]==2147483647)
    {
        cout<<"NU EXISTA TRASEU";
        return 0;
    }
    cout<<dist[x]<<'\n';
    while(tata[x]!=x)
    {
        cout<<orase[x]<<'\n';
        x = tata[x];
    }
    cout<<orase[y];
    return 0;
}
