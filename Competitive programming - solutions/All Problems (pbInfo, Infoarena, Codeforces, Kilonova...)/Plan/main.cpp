#include <fstream>
#include <set>
#define dim 100006
using namespace std;
ifstream cin("is.in");
ofstream cout("is.out");
int n,x1,x2,y1,y2,N;
long long ans;
int tree[5*dim];
set<pair<int,int> >s;
struct segment
{
    int x1,x2,y1,y2;
    int getType()
    {
        if(y1 == y2)
            return 1;
        else
            return 2;
    }
}v[dim];

void Update(int nod,int st,int dr,int poz,int val)
{
    if(st==dr)
    {
        tree[nod] += val;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        Update(2*nod,st,mij,poz,val);
    else
        Update(2*nod+1,mij+1,dr,poz,val);

    tree[nod] = tree[2*nod] + tree[2*nod+1];
}

void Query(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
    {
        ans += tree[nod];
        return;
    }
    int mij = (st+dr)>>1;
    if(a<=mij)
        Query(2*nod,st,mij,a,b);
    if(b>mij)
        Query(2*nod+1,mij+1,dr,a,b);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
        if(v[i].x1 == v[i].x2)
        {
            if(v[i].y1>v[i].y2)
                swap(v[i].y1,v[i].y2);
            s.insert({v[i].x1,i});
            N = max(N,v[i].y1);
            N = max(N,v[i].y2);
        }
        else
        {
            if(v[i].x1>v[i].x2)
                swap(v[i].x1,v[i].x2);
            s.insert({v[i].x1,i});
            s.insert({v[i].x2,i});
            N = max(N,v[i].y1);
            N = max(N,v[i].y2);
        }
    }

    for(auto it = s.begin(); it!=s.end();it++)
    {
        int x = it->first,
        i = it->second;
        if(v[i].getType()==2)
            Query(1,0,N,v[i].y1,v[i].y2);
        else
        {
            if(v[i].x1==x)
                Update(1,0,N,v[i].y1,1);
            else
                Update(1,0,N,v[i].y1,-1);
        }
    }

    cout<<ans;
    return 0;
}
