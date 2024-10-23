#include <fstream>
#include <queue>
using namespace std;
ifstream cin("hambar.in");
ofstream cout("hambar.out");
const int k=1001;
int v[1001][1001];
bool v1[1001][1001];
struct pereche{int first,second;}a;
int main()
{
    int n,m,i,j,b;
    cin>>n>>m;
    queue<pereche>q;
    pereche a;
    for(i=0;i<m;i++)
    {
        cin>>a.first>>a.second;
        a.first-=1;
        a.second-=1;
        if(a.first>0)q.push(a);
        v1[a.first][a.second]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(v1[i][j]!=1&&i==0)v[i][j]=1;
            else if(v1[i][j]!=1)v[i][j]=v[i-1][j]+1;
            if(i==n-1)
            {
                if(v[i][j]!=0)
                {
                    a.first=i+1;
                    a.second=j;
                    q.push(a);
                }
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().first-1;
        int st=q.front().second;
        int dr=st;
        while(v[x][st]<=v[x][q.front().second]&&st>0)st--;
        while(v[x][dr]<=v[x][q.front().second]&&v[x][dr]!=0&&dr<n-1)dr++;
        cout<<q.front().first<<" "<<q.front().second<<" "<<st<<" "<<dr<<endl;
        q.pop();
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
