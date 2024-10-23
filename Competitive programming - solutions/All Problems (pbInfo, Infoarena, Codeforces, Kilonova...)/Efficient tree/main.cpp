#include <iostream>

using namespace std;
const int N = 100009;
int n,m,op,x,y,a,b;
int tree[2*N];
void Build()
{
    for(int i = n ; i > 0; --i)tree[i] = tree[i<<1] + tree[i<<1|1];
}
void modify(int p,int val)
{
    for( tree[p += n] = val; p > 1; p >>= 1)tree[p>>1] = tree[p] + tree[p^1];
}
int query(int l,int r)
{
    int res = 0;
    for(l+=n,r+=n;l<r; l>>=1, r>>=1)
    {
        if(l&1)res += tree[l++];
        if(r&1)res += tree[--r];
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>tree[i+n];
    Build();
    cout<<tree[2]<<'\n';
    while(m--)
    {
        cin>>op>>x>>y;
        if(op==1)
            modify(x,y);
        else
            cout<<query(x,y)<<'\n';
    }
    return 0;
}
