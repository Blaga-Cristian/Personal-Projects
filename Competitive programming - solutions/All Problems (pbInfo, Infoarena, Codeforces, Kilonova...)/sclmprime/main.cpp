#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;
ifstream cin("sclmprime.in");
ofstream cout("sclmprime.out");
const int Inf = 0x3f3f3f3f;
bool prim[1000007];
int c[1001],p[1001],v[1001],len,x;
void Ciur(int n)
{
    prim[0] = prim[1] = 1;
    for(int i=2;i*i<=n;++i)
    {
        if(prim[i]==0)
            for(int j=2;j*i<=n;++j)prim[i*j]=1;
    }
}
int main()
{
    Ciur(1000001);
    int ans = -1;
    int ip = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(prim[x]==0)
        {
        v[++ip] = x;
        if(v[ip]>c[len])
            c[++len] = v[ip],p[ip]=len;
        else
        {
            int poz = upper_bound(c+1,c+len+1,v[ip]) - c;
            c[poz] = v[ip];
            p[ip] = poz;
        }
        }
    }
    n = ip;
    cout<<ans<<'\n';
    int mini,ind;
    stack<int> st;
    for(int j=ans;j>=1;--j)
    {
        for(int i = n;i>=1;--i)
        {
            if(p[i] == j)
            {
                mini = min(mini, v[i]);
            }
        }
        st.push(mini);
    }
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    return 0;
}
