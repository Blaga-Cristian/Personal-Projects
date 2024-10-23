#include <iostream>
#include <vector>
using namespace std;

int n,m,k,v,a,b,x,y,z,cnt;
vector<vector<int>>sirad;
vector<bool> sigur,viz;
void Dfs(int x)
{
    viz[x] = true;
    for(auto i : sirad[x])
        if(!viz[i] && sigur[i])
            Dfs(i);
}
int main()
{
    cin>>n>>m>>k>>v;
    sirad = vector<vector<int>>(109);
    sigur = vector<bool>(109);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }
    while(k--)
    {
        cin>>x;
        sigur[x] = true;
    }
    while(v--)
    {
        cin>>a>>b;
        viz = vector<bool>(109);
        Dfs(a);
        viz[b] ? cout<<"DA\n": cout<<"NU\n";
    }
    return 0;
}
