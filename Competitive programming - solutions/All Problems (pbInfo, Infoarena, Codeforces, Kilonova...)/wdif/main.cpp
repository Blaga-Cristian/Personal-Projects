#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
ifstream cin("weightdif.in");
ofstream cout("weightdif.out");
const int N = 30009;
int n,m,a,b,c;
struct muchie
{
    int a,b,c;
    bool operator < (const muchie& other) const
    {return c < other.c;}
};
vector<muchie> muchii;
int t[N];

int find(int x)
{
    int rad = x,y;
    while(t[rad])rad = t[rad];

    while(x != rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
void unite(int tx,int ty)
{
    t[tx] = ty;
}


bool arbore(int strt,int stp)
{
    memset(t,0,sizeof(t));
    int cnt = n;

    for(int i = strt; i <= stp; ++i)
    {
        int rx = find(muchii[i].a);
        int ry = find(muchii[i].b);

        if(rx != ry)
        {
            unite(rx,ry);
            cnt--;
        }
    }

    return (cnt == 1);
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b>>c;
        muchii.push_back({a,b,c});
    }

    sort(muchii.begin(),muchii.end());

    int imin = 0,imax = muchii.size()-1,st,dr,mij;
    int mid = (muchii.size()+1)/2 - 1;
    st = 0,dr = mid;
    int poz = 0;

    while(st <= dr)
    {
        mij = (st + dr)>>1;
        if(arbore(mij,muchii.size()-1-mij))
        {
            st = mij + 1;
            poz = mij;
        }
        else
            dr = mij - 1;
    }


    imin = poz, imax = muchii.size()-1-poz;
    st = poz, dr = muchii.size()-1-poz;
    while(st <= dr)
    {
        mij = (st + dr)>>1;
        if(arbore(imin,mij))
        {
            dr = mij-1;
            imax = mij;
        }
        else
            st = mij + 1;
    }

    st = poz, dr = muchii.size()-1-poz;
    while(st <= dr)
    {
        mij = (st + dr)>>1;
        if(arbore(mij,imax))
        {
            st = mij + 1;
            imin = mij;
        }
        else
            dr = mij-1;
    }

    cout<<muchii[imax].c - muchii[imin].c;
    return 0;
}
