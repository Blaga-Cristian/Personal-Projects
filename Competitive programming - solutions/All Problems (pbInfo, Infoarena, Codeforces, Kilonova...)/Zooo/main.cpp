#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("zoo.in");
ofstream cout("zoo.out");
int n,m,x,y;
struct punct
{
    int x,y;
};
vector<punct> puncte,queries;
vector<int> values;
int norm(int x)
{
    return distance(values.begin(),lower_bound(values.begin(),values.end(),x)) + 1;
}
struct aib
{
    int N;
    vector<vector<int>>tree;
    aib() {}
    aib(int size)
    {
        N = size;
        tree = vector<vector<int>>(size+1);
    }
    void Sort_All()
    {
        for(int i=1;i<=N;++i)
            sort(tree[i].begin(),tree[i].end());
    }
    void update(int x,int y)
    {
        for(int i = x; i<=N;i+=i&-i)
            tree[i].push_back(y);
    }
    int query(int x,int y)
    {
        int ret = 0;
        for(int i = x;i;i-=i&-i)
            ret += distance(tree[i].begin(),lower_bound(tree[i].begin(),tree[i].end(),y+1));
        return ret;
    }
};
aib DS;
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

    DS = aib(values.size());

    for(auto& p : puncte)
        DS.update(p.x,p.y);

    DS.Sort_All();

    for(int i=0;i<queries.size();i+=4)
    {
        auto &a = queries[i];
        auto &b = queries[i+1];
        auto &c = queries[i+2];
        auto &d = queries[i+3];
        cout<<DS.query(a.x,a.y) - DS.query(b.x,b.y) - DS.query(c.x,c.y) + DS.query(d.x,d.y)<<'\n';
    }
    return 0;
}
