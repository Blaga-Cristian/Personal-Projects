#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct nod
{
    char tip;
    int ton;
};
int n;
vector<nod> v;
vector<vector<pair<int,int> > >sirad;
vector<bool>vis;
vector<vector<int> >Matrici(30);
vector<int> sol;
void Dfs(int nod,int weight,int ind)
{
    vis[nod] = true;
    sol[ind] = min(sol[ind],Matrici[ind][nod]);
    for(auto i : sirad[nod])
    {
        if(vis[i.first]==false)
        {
            Matrici[ind][i.first]+= Matrici[ind][nod]+weight*i.second;
            Dfs(i.first,weight,ind);
        }
    }
}
int main()
{

    int a,b,c;
    cin>>n;
    v = vector<nod>(n+1);
    sirad = vector<vector<pair<int,int> > > (n+1);
    Matrici = vector<vector<int> >(30,vector<int>(n+1));
    vis = vector<bool>(n+1);
    sol = vector<int>(30);
    for(int i=1;i<=n;++i)cin>>v[i].tip;
    for(int i=1;i<=n;++i)cin>>v[i].ton;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b>>c;
        sirad[a].emplace_back(b,c);
        sirad[b].emplace_back(a,c);
    }
    for(int i=1;i<=n;++i)
    {
        sol[v[i].tip-'a'+1]=0x3f3f3f3f;
        Dfs(i,v[i].ton,v[i].tip-'a'+1);
    }
    for(int i=1;i<=26;++i)
    {
        cout<<sol[i]<<' ';
    }
    return 0;
}
