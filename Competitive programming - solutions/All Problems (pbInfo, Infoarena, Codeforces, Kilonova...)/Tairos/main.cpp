#include <fstream>
#include <vector>
using namespace std;
ifstream cin("tairos.in");
ofstream cout("tairos.out");
const int mod = 1000000007;
long long n,d,a,b,x,y,node,dist[1000],rad[10023];
vector<vector<int>>sirad;
vector<int>frunz;

void Dfs(int x,int p,int distanta)
{
    dist[distanta] ++;
    int ok = 1;
    if(sirad[x].size() == 1 && sirad[x][0] == p)frunz.push_back(distanta);
    for(auto i : sirad[x])
        if(i!=p)
            Dfs(i,x,distanta+1);
}
int main()
{
    cin>>n>>d;
    sirad = vector<vector<int>>(n+1);
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }

    Dfs(1,0,0);

    rad[0] = 1;
    for(int i = 0; i <= d; ++i)
    {
        if(rad[i])
            for(auto x : frunz)
            {
                rad[i+x] += rad[i];
                rad[i+x]%=mod;
            }
        rad[i]%=mod;
    }

    long long ans = 0;
    for(int i = max(0LL,d-103); i < d; ++i)
        ans += (rad[i] * dist[d-i])%mod,
        ans %= mod;
    cout<<ans;
    return 0;
}
