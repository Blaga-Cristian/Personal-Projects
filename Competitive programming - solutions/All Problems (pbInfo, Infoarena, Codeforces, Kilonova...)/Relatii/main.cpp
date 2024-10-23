#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("relatii.in");
ofstream cout("relatii.out");

vector<vector<int> > sir;
vector<vector<bool> >mat;
vector<int> deg;
queue<int> q;
int main()
{
    char s[10];
    int n,m,x,y;
    cin>>n>>m;
    cin.get();
    sir = vector<vector<int> > (n+1);
    mat = vector<vector<bool> >(n+1,vector<bool>(n+1));
    deg =vector<int> (n+1);
    while(m--)
    {
        cin.get(s,10);
        cin.get();
        if(s[1]=='>')swap(s[0],s[2]);
        x = s[0]-'a'+1;
        y = s[2]-'a'+1;
        if(mat[x][y]==0)
        {
            mat[x][y]=1;
            sir[x].emplace_back(y);
            deg[y]++;
        }
    }
    for(int i=1;i<=n;++i)if(deg[i]==0)q.emplace(i);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        cout<<char(x+'a'-1);
        for(auto i:sir[x])
        {
            deg[i]--;
            if(deg[i]==0)q.emplace(i);
        }
    }
    return 0;
}
