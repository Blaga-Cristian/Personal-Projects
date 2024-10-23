#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("qxy.in");
ofstream cout("qxy.out");
const int N = 10009,V = 1001;
int n,x,q,i,j,y;
vector<int> aib[N];
void update(int x,int y)
{
    for(x; x < N; x += x&-x)
        aib[x].push_back(y);
}
int query(int x,int y)
{
    int ret = 0;
    for(x; x; x -= x&-x)
        ret += distance(aib[x].begin(),upper_bound(aib[x].begin(),aib[x].end(),y));
    return ret;
}
void Sort_All()
{
    for(int i=0;i<N;++i)
        sort(aib[i].begin(),aib[i].end());
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        update(i,x);
    }
    Sort_All();
    cin>>q;
    while(q--)
    {
        cin>>i>>j>>x>>y;
        cout<<(query(j,y) - query(j,max(0,x-1)) - (query(max(0,i-1),y) - query(max(0,i-1),max(0,x-1))))<<'\n';
    }
    return 0;
}
