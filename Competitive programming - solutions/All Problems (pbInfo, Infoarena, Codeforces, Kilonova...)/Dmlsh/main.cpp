#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("demolish.in");
ofstream cout("demolish.out");

const int N = 500000;
const long long Inf = (1LL<<60);

int m,n,f,dx,dy,x1,y1,x2,y2,c;

struct evnt
{
    int x,y1,y2,cost;
    bool start_dreptunghi;
    bool operator < (const evnt& a)
    {
        return x < a.x;
    }
};
vector<evnt> events;

struct node
{
    long long val,lazy;
    int poz;
};
node tree[4*N];

void build(int nod,int st,int dr)
{
    tree[nod].poz = st;

    if(st!=dr)
    {
        int mij = (st+dr)>>1;
        build(nod<<1,st,mij);
        build(nod<<1|1,mij+1,dr);
    }
}
void update_nod(int nod)
{
    if(tree[nod<<1].val <= tree[nod<<1|1].val)
    {
        tree[nod].val = tree[nod<<1].val;
        tree[nod].poz = tree[nod<<1].poz;
    }
    else
    {
        tree[nod].val = tree[nod<<1|1].val;
        tree[nod].poz = tree[nod<<1|1].poz;
    }
}
void Push(int nod,int st,int dr)
{
    if(st==dr || tree[nod].lazy == 0)
        return;

    tree[nod<<1].val += tree[nod].lazy;
    tree[nod<<1].lazy += tree[nod].lazy;

    tree[nod<<1|1].val += tree[nod].lazy;
    tree[nod<<1|1].lazy += tree[nod].lazy;

    tree[nod].lazy = 0;
}
void update(int nod,int st,int dr,int a,int b,int cost)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
    {
        tree[nod].val += cost;
        tree[nod].lazy += cost;
        return;
    }
    int mij = (st+dr)>>1;
    if(a<=mij)
        update(nod<<1,st,mij,a,b,cost);
    if(b>mij)
        update(nod<<1|1,mij+1,dr,a,b,cost);

    update_nod(nod);
}
int main()
{
    cin>>m>>n>>f>>dx>>dy;

    for(int i=0;i<f;++i)
    {
        cin>>x1>>y1>>x2>>y2>>c;
        events.push_back({x1-(dx-1),y1,y2,c,true});
        events.push_back({x2,y1,y2,c,false});
    }

    sort(events.begin(),events.end());

    long long ans = Inf;
    pair<int,int> ans_poz(-1,-1);

    build(1,0,(n-1)-(dy-1));
    for(int i=0,j=0;i+dx<=m;++i)
    {
        while(j<events.size() && events[j].x <= i)
        {
            int y1 = max(0,events[j].y1 - (dy-1)),
            y2 = min((n-1) - (dy-1), events[j].y2 - 1),
            cost = events[j].cost * ((events[j].start_dreptunghi)? 1 : -1);

            if(y1<=y2)
                update(1,0,(n-1) - (dy-1),y1,y2,cost);
            ++j;
        }
        long long cost = tree[1].val;
        int position = tree[1].poz;

        if(ans > cost)
        {
            ans = cost;
            ans_poz = make_pair(i,position);
        }
    }
    cout<<ans<<'\n'<<ans_poz.first<<' '<<ans_poz.second<<' '<<
    ans_poz.first + dx<<' '<<ans_poz.second + dy;
    return 0;
}
