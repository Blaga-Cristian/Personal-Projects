#include <fstream>
#include <vector>
#define N 100005
#define l first
#define r second
using namespace std;
ifstream cin("di.in");
ofstream cout("di.out");
pair<int,int> tree[5*N];
vector<int> c;
int n,q,v[N],i,val,j,cer,m,a,b,cnt;
void build_tree(int nod,int st,int dr)
{
    if(st==dr)
    {
        tree[nod].l = tree[nod].r = st;
        return;
    }
    int mij = (st+dr)>>1;
    build_tree(2*nod,st,mij);
    build_tree(2*nod+1,mij+1,dr);

    tree[nod] = {tree[2*nod].l,tree[2*nod+1].r};
}

void desc(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
    {
        if(!c.empty())c.push_back(tree[nod].r);
        else
            c.push_back(tree[nod].l),c.push_back(tree[nod].r);
        cnt++;
        return;
    }
    int mij = (st+dr)>>1;
    if(a<=mij&&b>mij)
        desc(2*nod,st,mij,a,b),desc(2*nod+1,mij+1,dr,a,b);
    else if(a>mij)
        desc(2*nod+1,mij+1,dr,a,b);
    else
        desc(2*nod,st,mij,a,b);
}

int main()
{
    cin>>n;
    build_tree(1,1,n);
    cin>>m;
    while(m--)
    {
        c.clear();
        cnt = 0;
        cin>>a>>b;
        desc(1,1,n,a,b);
        cout<<cnt<<' ';
        for(auto i : c)cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}
