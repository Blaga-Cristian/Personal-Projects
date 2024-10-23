#include <fstream>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
ifstream cin("scmax.in");
ofstream cout("scmax.out");
const int N = 100009;
int n,v[N],aib[N],p[N],norm[N],ans,m;
map<int,int> mp;
stack<int> stk;
void update(int poz,int val)
{
    for(int i = poz; i <= m; i+=i&-i)
        aib[i] = max(aib[i],val);
}
int query(int poz)
{
    int s = 0;
    for(int i = poz; i>0; i-=i&-i)
        s = max(s,aib[i]);
    return s;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i],norm[i] = v[i];

    sort(norm+1,norm+n+1);
    int val = -1;
    for(int i=1;i<=n;++i)
    {
        if(norm[i]>val)
        {
            val = norm[i];
            mp[norm[i]] = ++m;
        }
    }
    for(int i=1;i<=n;++i)
        v[i] = mp[v[i]];

    for(int i=1;i<=n;++i)
    {
        p[i] = query(v[i]-1) + 1;
        ans = max(ans,p[i]);
        update(v[i],p[i]);
    }
    cout<<ans<<'\n';
    for(int i=n;i>0;--i)
        if(p[i]==ans)
    {
        stk.push(v[i]);
        --ans;
    }
    while(!stk.empty())
    {
        cout<<stk.top()<<' ';
        stk.pop();
    }
    return 0;
}
