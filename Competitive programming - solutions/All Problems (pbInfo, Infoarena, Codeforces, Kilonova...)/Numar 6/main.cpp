#include <fstream>
#include <queue>
using namespace std;
ifstream cin("numar6.in");
ofstream cout("numar6.out");
using pi = pair<int,int>;
using ppi = pair<int,pi>;
int n,m,x;
priority_queue<ppi,vector<ppi>,greater<ppi>>q;
int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
    {
        cin>>x;
        q.push({x,{x,1}});
    }
    int prv = -13;
    for(int i = 1; i <= m; ++i)
    {
        while(!q.empty() && q.top().first == prv)
        {
            q.push({q.top().second.first * (q.top().second.second+1),{q.top().second.first,q.top().second.second+1}});
            q.pop();
        }
        prv = q.top().first;
        q.push({q.top().second.first * (q.top().second.second+1),{q.top().second.first,q.top().second.second+1}});
        q.pop();
    }
    cout<<prv;
    return 0;
}
