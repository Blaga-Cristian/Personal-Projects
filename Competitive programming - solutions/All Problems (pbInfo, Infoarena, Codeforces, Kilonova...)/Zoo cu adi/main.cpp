#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("zoo.in");
ofstream cout("zoo.out");
int n,m;
struct punct
{
    int x,y;
};
vector<punct> puncte,queries;
vector<int> values;
vector<vector<int>>lst;
vector<vector<int>>tree;
int norm(int x)
{
    return distance(values.begin(),lower_bound(values.begin(),values.end(),x)) + 1;
}
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        tree[nod] = lst[st];
        sort(tree[nod].begin(),tree[nod].end());
        return;
    }
    int mij = (st+dr)>>1;

    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    merge(begin(tree[nod<<1]),end(tree[nod<<1]),
          begin(tree[nod<<1|1]),end(tree[nod<<1|1]),
          back_inserter(tree[nod]));
}
int query(int nod,int st,int dr,int x1,int y1,int x2,int y2)
{
    if(x1<=st&&dr<=x2)
        return upper_bound(tree[nod].begin(),tree[nod].end(),y2)-
        lower_bound(tree[nod].begin(),tree[nod].end(),y1);
    int mij = (st+dr)>>1;
    if(x2<=mij)
        return query(nod<<1,st,mij,x1,y1,x2,y2);
    else if(x1>mij)
        return query(nod<<1|1,mij+1,dr,x1,y1,x2,y2);
    else
        return query(nod<<1,st,mij,x1,y1,x2,y2) + query(nod<<1|1,mij+1,dr,x1,y1,x2,y2);
}
int main()
{
    cin>>n;
    puncte = vector<punct>(n);
    for(auto& p : puncte)
        cin>>p.x>>p.y;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        queries.push_back({x2,y2});
        queries.push_back({x1-1,y2});
        queries.push_back({x2,y1-1});
        queries.push_back({x1-1,y1-1});
    }

    for(auto& p : puncte)
        values.push_back(p.x);
    for(auto& q : queries)
        values.push_back(q.x);

    sort(values.begin(),values.end());
    values.erase(unique(values.begin(),values.end()),values.end());

    for(auto& p : puncte)
        p.x = norm(p.x);
    for(auto& q : queries)
        q.x = norm(q.x);

    tree = vector<vector<int>>(4*values.size());
    int sz = values.size();
    lst = vector<vector<int>>(sz+3);

    for(auto& p : puncte)
        lst[p.x].push_back(p.y);

    build(1,1,sz);

    for(int i=0;i<queries.size();i+=4)
    {
        auto& a = queries[i];
        auto& b = queries[i+1];
        auto& c = queries[i+2];
        auto& d = queries[i+3];
        cout<<query(1,1,sz,d.x+1,d.y+1,a.x,a.y)<<'\n';
        /// query(1,1,n,x1,y1,x2,y2);
    }
    return 0;
}
