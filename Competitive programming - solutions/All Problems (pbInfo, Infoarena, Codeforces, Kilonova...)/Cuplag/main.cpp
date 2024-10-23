#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream cin("cuplaj.in");
ofstream cout("cuplaj.out");
const int N = 10009;
int n,m,e,a,b;
vector<vector<int>> G;
int L[N],R[N];
bitset<N> v;

int CuplajMaxim();
bool DoMatch(int x);

int main()
{
    cin>>n>>m>>e;
    G = vector<vector<int>>(n+m+3);
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

int CuplajMaxim()
{
    int maxmatch = 0;
    bool found_path = false;
    do
    {
        v.reset();
        found_path = false;
        for(int i = 1; i <= n; ++i)
            if(!L[i] && DoMatch(i))
            {
                found_path = true;
                maxmatch++;
            }
    }while(found_path);

    return maxmatch;
}
bool DoMatch(int x)
{
    if( v[x] )return false;
    v[x] = true;
    for(auto y : G[x])
        if(!R[y] || DoMatch(R[y]))
        {
            R[y] = x;
            L[x] = y;
            return true;
        }
    return false;
}
