#include <fstream>

using namespace std;
ifstream cin("xormax.in");
ofstream cout("xormax.out");
const int N = 50009,L = 20;
using pi = pair<int,int>;
int n,v[N],xp[N];
struct trie
{
    int fin;
    trie* son[2];
    trie()
    {
        fin = 0;
        son[0] = son[1] = 0;
    }
};
trie* T = new trie;

void add(trie* x,int a,int b,int index)
{
    bool bit = ((a & (1<<b)) > 0) ? 1 : 0;

    if(x->son[bit] == 0)
        x->son[bit] = new trie;

    if(b == 0)x->son[bit]->fin = index;
    else add(x->son[bit],a,b-1,index);
}

pi query(trie* x,int s,int b,int mask)
{
    bool bit = ((s & (1<<b)) > 0) ? 1 : 0;

    if(b == -1)
        return {mask,x->fin};
    else if(x->son[bit^1] != 0)
        return query(x->son[bit^1],s,b-1,(mask | (1<<b)));
    else
        return query(x->son[bit],s,b-1,(mask | (1<<b)) - (1<<b));
}

int main()
{
    cin>>n;

    add(T,xp[0],20,0);
    int maxXor = -1;
    int st = -1,dr = -1;
    for(int i = 1; i <= n;++i)
    {
        cin>>v[i];

        xp[i] = (xp[i-1] ^ v[i]);

        pi aux = query(T,xp[i],20,0);

        if(aux.first > maxXor)
        {
            maxXor = aux.first;
            st = aux.second;
            dr = i;
        }


        add(T,xp[i],20,i);
    }

    cout<<maxXor<<' '<<st+1<<' '<<dr;
    return 0;
}
