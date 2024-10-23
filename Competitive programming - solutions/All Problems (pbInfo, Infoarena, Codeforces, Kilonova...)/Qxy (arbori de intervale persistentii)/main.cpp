#include <fstream>
#include <vector>
using namespace std;
ifstream cin("qxy.in");
ofstream cout("qxy.out");
const int N = 10009;
int n,q,i,j,x,y;
class PersistentSegmentTree
{
public:
    struct Tree{
        int val;
        int leftt;
        int rightt;
    };
    vector<int> Roots;
    vector<Tree> Arb;
    int nodes;
    PersistentSegmentTree()
    {
        nodes = 0;
        Roots = vector<int>(4*N);
        Arb = vector<Tree>(4*N);
    }
    int copynode(int nod)
    {
        nodes++;
        Arb[nodes] = Arb[nod];
        return nodes;
    }
    void ResetP()
    {
        nodes = 0;
        fill(Roots.begin(),Roots.end(),0);
        Arb.clear();
    }
    int NewRootAfterUpdateOnPosition(int nod,int st,int dr,int poz,int val)
    {
        nod = copynode(nod);
        if(st==dr)
        {
            Arb[nod].val = val;
            return nod;
        }
        int mij = (st+dr)>>1;
        if(poz<=mij)
            Arb[nod].leftt = NewRootAfterUpdateOnPosition(Arb[nod].leftt,st,mij,poz,val);
        else
            Arb[nod].rightt = NewRootAfterUpdateOnPosition(Arb[nod].rightt,mij+1,dr,poz,val);

        Arb[nod].val = min(Arb[Arb[nod].leftt].val,Arb[Arb[nod].rightt].val);

        return nod;
    }
    int MinimumOnCurrentInterval(int nod,int st,int dr,int a,int b)
    {
        if(a<=st && dr<=b)
            return Arb[nod].val;
        int mij = (st+dr)>>1;
        if(b<=mij)
            return MinimumOnCurrentInterval(Arb[nod].leftt,st,mij,a,b);
        else if(a>mij)
            return MinimumOnCurrentInterval(Arb[nod].rightt,mij+1,dr,a,b);
        else
            return min(MinimumOnCurrentInterval(Arb[nod].leftt,st,mij,a,b),MinimumOnCurrentInterval(Arb[nod].rightt,mij+1,dr,a,b));
    }
};
int main()
{
    cin>>n;
    PersistentSegmentTree Copac;
    Copac.ResetP();
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        Copac.Roots[i] = Copac.NewRootAfterUpdateOnPosition(Copac.Roots[i-1],1,n,i,x);
    }
    cin>>q;
    while(q--)
    {

    }
    return 0;
}
