#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("train.in");
ofstream cout("train.out");
const int N = 1e5 + 9;
int n,m,x,y;
struct element
{int x,y,c,ind;};
inline bool cmp(element a,element b)
{return (a.x == b.x) ? a.y < b.y : a.x < b.x;};
element pasager[N];
int auxx[N],auxy[N];
int best[N],len[N];
int t[N];

int tree[4*N],indice[4*N];
void update(int nod,int st,int dr,int poz,int val,int ind)
{
    if(tree[nod] < val)
    {
        tree[nod] = val;
        indice[nod] = ind;
    }
    if(st == dr)return;
    int mij = (st+dr)>>1;
    if(poz <= mij)update(nod<<1,st,mij,poz,val,ind);
    else update(nod<<1|1,mij+1,dr,poz,val,ind);
}
pair<int,int> query(int nod,int st,int dr,int endd)
{
    if(dr <= endd)
        return {tree[nod],indice[nod]};
    int mij = (st+dr)>>1;
    if(endd <= mij)
        return query(nod<<1,st,mij,endd);
    return max(query(nod<<1,st,mij,endd),query(nod<<1|1,mij+1,dr,endd));
}

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
    {
        cin>>pasager[i].x>>pasager[i].y>>pasager[i].c;
        pasager[i].ind = i;
        auxx[i] = pasager[i].x;
        auxy[i] = pasager[i].y;
    }

    sort(auxy + 1, auxy + n + 1);
    for(int i = 1;i <= n;++i)
        pasager[i].y = lower_bound(auxy+1,auxy+n+1,pasager[i].y) - auxy;

    sort(pasager+1,pasager+n+1,cmp);

    int ans = 0,ans_ind = 0;
    for(int i = 1; i <= n; ++i)
    {
        auto pi = query(1,1,n,pasager[i].y);
        int vl = pi.first;
        int ind = pi.second;
        vl += pasager[i].c;
        t[pasager[i].ind] = ind;
        if(vl > ans)
        {
            ans = vl;
            ans_ind = pasager[i].ind;
        }
        update(1,1,n,pasager[i].y,vl,pasager[i].ind);
    }
    cout<<ans<<'\n';
    vector<int> res;
    while(ans_ind)
    {
        res.push_back(ans_ind);
        ans_ind = t[ans_ind];
    }
    cout<<res.size()<<'\n';
    reverse(res.begin(),res.end());
    for(auto i : res)
        cout<<i<<' ';
    return 0;
}
