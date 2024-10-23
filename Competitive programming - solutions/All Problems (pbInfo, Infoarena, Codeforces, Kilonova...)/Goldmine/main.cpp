#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("kop14.in");
ofstream cout("KOP.OUT");
const int N = 60009,mj = 30000;
int n,s,w,x,y;
struct event
{
    int x,y1,y2;
    bool add;
    inline bool operator < (const event& b)
    {
        return x < b.x;
    }
};
vector<event> events;
struct node
{
    int val,lazy;
};
vector<node> tree(4*N);
void Push(int nod,int st,int dr)
{
    if(tree[nod].lazy == 0 || st == dr)
        return;

    tree[nod<<1].val += tree[nod].lazy;
    tree[nod<<1].lazy += tree[nod].lazy;

    tree[nod<<1|1].val += tree[nod].lazy;
    tree[nod<<1|1].lazy += tree[nod].lazy;

    tree[nod].lazy = 0;
}
void update(int nod,int st,int dr,int a,int b,int val)
{
    Push(nod,st,dr);
    if(a <= st && dr <= b)
    {
        tree[nod].val += val;
        tree[nod].lazy += val;
        return;
    }
    int mij = (st+dr)>>1;
    if(a <= mij)
        update(nod<<1,st,mij,a,b,val);
    if(b > mij)
        update(nod<<1|1,mij+1,dr,a,b,val);

    tree[nod].val = max(tree[nod<<1].val,tree[nod<<1|1].val);
}
int main()
{
    cin>>s>>w;///lungime si inaltime
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y;
        x += mj;
        y += mj;
        events.push_back({max(0,x-s),max(0,y-w),y,true});
        events.push_back({x+1,max(0,y-w),y,false});
    }

    sort(events.begin(),events.end());

    int ans = 0;
    int j = 0;
    for(int i=0;i<=N;++i)
    {
        while( j < events.size() && events[j].x <= i)
        {
            if(events[j].add)
                update(1,0,N,events[j].y1,events[j].y2,1);
            else
                update(1,0,N,events[j].y1,events[j].y2,-1);
            ++j;
        }
        ans = max(ans,tree[1].val);
    }

    cout<<ans;
    return 0;
}
