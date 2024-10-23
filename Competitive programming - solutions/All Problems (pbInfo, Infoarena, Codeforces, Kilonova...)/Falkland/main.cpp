#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
string f = "falkland.";
ifstream cin(f + "in");
ofstream cout(f + "out");
const int M = 50009;
int l[M],r[M],u[M];
int n,m,k,a,b;
vector<vector<int>> sirad;
int pairup(int n)
{
    if(u[n])return 0;
    u[n] = 1;

    for(auto i : sirad[n])
        if(!r[i])
    {
        l[n] = i;
        r[i] = n;
        return 1;
    }

    for(auto i : sirad[n])
        if(pairup(r[i]))
    {
        l[n] = i;
        r[i] = n;
        return 1;
    }

    return 0;
}
int main()
{
    cin>>n>>m>>k;
    sirad = vector<vector<int>>(n+1);
    while(k--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }

    int change = 1;
    while(change)
    {
        change = 0;
        memset(u,0,sizeof(u));
        for(int i=1;i<=n;++i)
            if(!l[i])
                change |= pairup(i);
    }
    int cuplaj = 0;
    for(int i= 1;i<=n;++i)
        cuplaj += (l[i] > 0);
    cout<<cuplaj;
    return 0;
}
