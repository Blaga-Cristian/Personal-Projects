#include <fstream>

using namespace std;
ifstream cin("file.in");
ofstream cout("file.out");
const int N = 1e5 + 9;
int n,m,i,j,stage,cer,val;
int v[N];
int NEXT_FREE_INDEX;
int L[N],R[N],idx;
int Roots[N];
int tree[3*N];

int Build(int st,int dr)
{
    int nod = ++NEXT_FREE_INDEX;

    if(st == dr)
    {
        tree[nod] = v[st];
        return nod;
    }

    int mij = (st + dr)/2;

    L[nod] = Build(st,mij);
    R[nod] = Build(mij+1,dr);

    tree[nod] = tree[L[nod]] + tree[R[nod]];

    return nod;
}

int update(int nod,int st,int dr,int poz,int val)
{
    int nnod = ++NEXT_FREE_INDEX;
    L[nnod] = L[nod];
    R[nnod] = R[nod];

    if(st == dr)
    {
        tree[nnod] = val;
        return nnod;
    }

    int mij = (st + dr)>>1;
    if(poz <= mij)
        L[nnod] = update(L[nod],st,mij,poz,val);
    else
        R[nnod] = update(R[nod],mij+1,dr,poz,val);

    return nnod;
}

int query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod];

    int mij = (st + dr)>>1;
    if(b <= mij)
        return query(L[nod],st,mij,a,b);
    else if(a > mij)
        return query(R[nod],mij+1,dr,a,b);
    return query(L[nod],st,mij,a,b) + query(R[nod],mij+1,dr,a,b);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    Roots[++idx] = Build(1,n);
    cout<<tree[R[Roots[1]]];

    //while(m--)
    {
        cin>>cer;
        if(cer == 1)
        {
            cin>>i>>val;
            //Roots[++idx] = update(Roots[idx-1],1,n,i,val);
        }
        else
        {
            cin>>stage>>i>>j;
            //cout<<query(Roots[stage],1,n,i,j);
        }
    }
    return 0;
}
