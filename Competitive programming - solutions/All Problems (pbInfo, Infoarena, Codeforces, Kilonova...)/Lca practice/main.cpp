#include <fstream>
#include <vector>

using namespace std;
ifstream cin("delay.in");
ofstream cout("delay.out");
const int N = 16009,LG = 20;
int n,cost[N],tour[2*N],first[N],last[N],idx,a,b,c,m;
int tree[8*N];
int t[N][LG],dep[N];
vector<vector<int>> G;

void Dfs(int x,int p)
{
    first[x] = ++idx;
    tour[idx] = cost[x];

    dep[x] = dep[p] + 1;
    t[x][0] = p;
    for(int i = 1; i < LG; ++i)
        t[x][i] = t[t[x][i-1]][i-1];

    for(auto y : G[x])
        if(y != p)
            Dfs(y,x);

    last[x] = ++idx;
    tour[idx] = -cost[x];
}

void Build(int nod = 1,int st = 1,int dr = idx)
{
    if(st == dr)
    {
        tree[nod] = tour[st];
        return;
    }
    int mij = (st + dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}

void update(int poz,int val,int nod = 1,int st = 1,int dr = idx)
{
    if(st == dr)
    {
        tree[nod] = val;
        return;
    }
    int mij = (st + dr)>>1;
    if(poz <= mij)
        update(poz,val,nod<<1,st,mij);
    else
        update(poz,val,nod<<1|1,mij+1,dr);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}

int query(int a,int b,int nod = 1,int st = 1,int dr = idx)
{
    if(a <= st && dr <= b)
        return tree[nod];
    int mij = (st + dr)>>1;
    if(b <= mij)
        return query(a,b,nod<<1,st,mij);
    else if(a > mij)
        return query(a,b,nod<<1|1,mij+1,dr);
    return query(a,b,nod<<1,st,mij) + query(a,b,nod<<1|1,mij+1,dr);
}

int get_lca(int a,int b)
{
    if(dep[a] < dep[b])
        swap(a,b);

    for(int i = LG - 1; i >= 0; --i)
        if(dep[t[a][i]] >= dep[b])
            a = t[a][i];

    if(a == b)return a;

    for(int i = LG - 1; i >= 0; --i)
        if(t[a][i] != t[b][i])
        {
            a = t[a][i];
            b = t[b][i];
        }

    return t[a][0];
}

int main()
{
    cin>>n;
    G = vector<vector<int>>(n+1);

    for(int i = 1; i <= n; ++i)
        cin>>cost[i];

    for(int i = 1; i < n; ++i)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Dfs(1,0);
    Build();

    cin>>m;
    while(m--)
    {
        cin>>a>>b>>c;
        if(a == 1)
        {
            update(first[b],c);
            update(last[b],-c);
        }
        else
        {
            int lca = get_lca(b,c);

            cout<< query(min(first[lca],first[b]),max(first[lca],first[b])) + query(min(first[lca],first[c]),max(first[lca],first[c])) - query(first[lca],first[lca])<<'\n';
        }
    }
    return 0;
}
