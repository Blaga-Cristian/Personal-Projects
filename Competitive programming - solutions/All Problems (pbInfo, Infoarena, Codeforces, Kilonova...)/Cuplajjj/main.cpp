#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("cuplaj.in");
ofstream cout("cuplaj.out");
const int N = 10009;
int n,m,e,a,b;
vector<int> G[N];
vector<int> L,R;
int v[N];

bool DoMatch(int x)
{
    if(v[x])return false;
    v[x] = true;

    for(auto y : G[x])
        if(!R[y] || DoMatch(R[y]))
        {
            L[x] = y;
            R[y] = x;
            return true;
        }

    return false;
}

int CuplajMaxim()
{
    int max_matching = 0;
    bool foundpath = true;
    do
    {
        memset(v,false,sizeof(v));
        foundpath = false;

        for(int i = 1; i <= n; ++i)
            if(!L[i] && DoMatch(i))
            {
                max_matching ++;
                foundpath = true;
            }
    }while(foundpath);

    return max_matching;
}


int main()
{
    cin>>n>>m>>e;
    L.resize(n+1);
    R.resize(m+1);
    while(e--)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }

    cout<<CuplajMaxim()<<'\n';
    for(int i = 1; i <= n; ++i)
        if(L[i])
            cout<<i<<' '<<L[i]<<'\n';
    return 0;
}
