#include <vector>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
ifstream cin("bomber.in");
ofstream cout("bomber.out");
struct Bomba{int x,y,p;};
vector<struct Bomba>v;
float distanta(int x1,int y1,int x2,int y2)
{
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
void explozie(int a)
{
    int x=v[a].x,y=v[a].y,p=v[a].p;
    queue<int> q;
    v[a].x=-2000;
    v[a].y=-2000;
    v[a].p=0;
    for(int i=0;i<v.size();i++)
    {
        if(i!=a)
        {
            if(v[i].x!=-2000)if(distanta(x,y,v[i].x,v[i].y)<=p)q.push(i);
        }
    }
    while(!q.empty())
    {
        explozie(q.front());
        q.pop();
    }
}
int main()
{
    int n,I,cnt=0;
    cin>>n>>I;
    Bomba a;
    for(int i=0;i<n;i++)
    {
        cin>>a.x>>a.y>>a.p;
        v.push_back(a);
    }
    explozie(I-1);
    for(int i=0;i<v.size();i++)
    {
        if(v[i].x!=-2000)cnt++;
    }
    cout<<cnt;
    return 0;
}
