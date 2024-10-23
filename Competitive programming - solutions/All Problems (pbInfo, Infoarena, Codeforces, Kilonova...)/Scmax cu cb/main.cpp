#include <fstream>
#include <stack>
using namespace std;
ifstream cin("scmax.in");
ofstream cout("scmax.out");
const int N = 101015;
int n,v[N],c[N],len,L[N],poz,p[N];
stack<int> stk;
int cb(int x) /// upperbound
{
    if(x > c[len])return len + 1;
    if(len==0)return 1;

    int st = 1,dr = len,mij,pz = -1;
    while(st<=dr)
    {
        mij = (st+dr)/2;
        if(x < c[mij])
        {
            pz = mij;
            dr = mij-1;
        }
        else
            st = mij+1;
    }
    return pz;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
    {
        poz = cb(v[i]);
        if(poz > len)
            ++len;
        c[poz] = v[i];
        p[i] = poz;
    }
    cout<<len<<'\n';
    for(int i=n;i>=1;--i)
        if(p[i] == len)
        {
            stk.push(v[i]);
            --len;
        }
    while(!stk.empty())
    {
        cout<<stk.top()<<' ';
        stk.pop();
    }
    return 0;
}
