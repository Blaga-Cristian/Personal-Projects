#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream cin("fsecv.in");
ofstream cout("fsecv.out");
int Lbuck;
struct query
{
    int l,r,k,origine;
    bool operator<(const query& other) const
    {
        if (l / Lbuck == other.l / Lbuck)
            return r < other.r;
        return l / Lbuck < other.l / Lbuck;
    }
};
vector<int> v;
vector<query>Q;
int mp[100001],mp1[100001],sol[100001];
void expand(int index,int k)
{
    mp1[mp[v[index]]]--;
    mp[v[index]]++;
    mp1[mp[v[index]]]++;
}
void contract(int index,int k)
{
    mp1[mp[v[index]]]--;
    mp[v[index]]--;
    mp1[mp[v[index]]]++;
}
int n,q;
int main()
{
    cin>>n>>q;
    Lbuck = sqrt(n);
    v = vector<int>(n+1);
    Q = vector<query>(q);
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=0;i<q;++i)
       {

       cin>>Q[i].l>>Q[i].r>>Q[i].k;
       Q[i].origine=i;
       }
    sort(Q.begin(),Q.end());
    int st=1,dr=0;
    for(auto i : Q)
    {
        while(dr<i.r)expand(++dr,i.k);
        while(st>i.l)expand(--st,i.k);
        while(dr>i.r)contract(dr--,i.k);
        while(st<i.l)contract(st++,i.k);
        sol[i.origine] = mp1[i.k];
    }
    for(int i=0;i<q;++i)cout<<sol[i]<<'\n';
    return 0;
}
