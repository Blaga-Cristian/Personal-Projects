#include <fstream>
#include <vector>
using namespace std;
ifstream cin("dyson.in");
ofstream cout("dyson.out");
using PI = pair<int,int>;
int n,m,k,q;
vector<vector<PI> > sirad;
int main()
{
    int u,v,w;
    cin>>n>>m>>k>>q;
    sirad = vector<vector<PI> >(n+1);
    while(m--)
    {
        cin>>u>>v>>w;
        sirad[u].push_back({v,w});
    }
    for(int i=k+1;i<n;++i)
    return 0;
}
