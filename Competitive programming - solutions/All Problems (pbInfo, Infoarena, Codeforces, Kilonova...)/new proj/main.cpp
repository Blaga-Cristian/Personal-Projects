#include <iostream>

using namespace std;
int n,x,poz;
int tree[400];
void update(int nod,int st,int dr,int poz,int val)
{
    if(st == dr)
    {
        tree[nod] ++;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz <= mij)
        update(nod<<1,st,mij,poz,val);
    else
        update(nod<<1|1,mij+1,dr,poz,val);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}
int get_poz(int nod,int st,int dr,int pos)
{
    if(st == dr)
        return st;
    int mij = (st + dr)>>1;
    if(pos <= tree[nod<<1])
        return get_poz(nod<<1,st,mij,pos);
    else
        return get_poz(nod<<1|1,mij+1,dr,pos - tree[nod<<1]);
}
int main()
{
    cin>>n>>x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> poz;
        update(1,0,99,poz,1);
    }
    cout<<get_poz(1,0,99,x);
    return 0;
}
