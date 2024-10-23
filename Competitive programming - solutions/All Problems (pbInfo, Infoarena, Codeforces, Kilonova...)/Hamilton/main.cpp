#include <fstream>
#include <vector>
using namespace std;
ifstream cin("drum_hamiltonian.in");
ofstream cout("drum_hamiltonian.out");

int n,a,b,x,y,cnt;
int v[30];
bool ok,p[30];
vector<vector<int>>sirad;
void Back(int x,int sz)
{
    if(sz == n)
    {
        ok = 1;
        cout<<1<<'\n';
        for(int i=1;i<=sz;++i)cout<<v[i]<<' ';
        return;
    }
    for(auto i : sirad[x])
    {
        if(ok==1)return;
        if(p[i] == 0)
        {
            p[i] = 1;
            v[sz+1] = i;
            Back(i,sz+1);
            p[i] = 0;
        }
    }
}
int main()
{
    cin>>n;
    sirad = vector<vector<int>>(n+1);
    while(cin>>a>>b)
        sirad[a].push_back(b);
    for(int i=1;i<=n && ok == 0;++i)
    {
        v[1] = i;
        p[i] = 1;
        Back(i,1);
        p[i] = 0;
    }
    if(!ok)cout<<0;
    return 0;
}
