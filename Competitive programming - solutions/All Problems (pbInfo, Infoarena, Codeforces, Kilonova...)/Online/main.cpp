#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 30009;
int n,q,i,j,k;
vector<int> tree[4*N];
void Build(int nod = 1,int st = 1,int dr = n)
{
    if(st==dr)
    {
        int x;
        cin>>x;
        tree[nod].push_back(x);
        return;
    }
    int mij = (st+dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    merge(begin(tree[nod<<1]),end(tree[nod<<1]),
          begin(tree[nod<<1|1]),end(tree[nod<<1|1]),
          back_inserter(tree[nod]));
}
int query(int nod,int st,int dr,int a,int b,int k)
{
    if(a <= st && dr <= b)
        return tree[nod].size() - (upper_bound(tree[nod].begin(),tree[nod].end(),k) - tree[nod].begin());
    int mij = (st+dr)>>1;
    if(b <= mij)
        return query(nod<<1,st,mij,a,b,k);
    else if(a>mij)
        return query(nod<<1|1,mij+1,dr,a,b,k);
    else return query(nod<<1,st,mij,a,b,k) + query(nod<<1|1,mij+1,dr,a,b,k);
}
int main()
{
    cin>>n;
    Build();
    cin>>q;
    while(q--)
    {
        cin>>i>>j>>k;
        if(i>j || j < 1 || i > n)
        {
            cout<<"0\n";
            continue;
        }
        i = max(1,i);
        j = min(j,n);
        cout<<query(1,1,n,i,j,k)<<'\n';
    }
    return 0;
}
