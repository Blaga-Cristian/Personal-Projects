#include <fstream>
#include <deque>
#include <vector>
using namespace std;
ifstream cin("rau.in");
ofstream cout("rau.out");
const int N = 50009, V = 400000,Inf = 0x3f3f3f3f;
int n,k,c;
int dp[N],h[N];
deque<int> dq[V+1];
int tree[4 * V];
void update(int nod,int st,int dr,int poz);
void push(int h_val,int ind)
{
    while(!dq[h_val].empty() && dp[dq[h_val].back()] >= dp[ind])
        dq[h_val].pop_back();

    dq[h_val].push_back(ind);

    if(dq[h_val].size() == 1)update(1,1,V,h_val);
}
void pop(int h_val,int ind)
{
    if(!dq[h_val].empty() && dq[h_val].front() == ind)
    {
        dq[h_val].pop_front();
        update(1,1,V,h_val);
    }
}

void build(int nod,int st,int dr)
{
    tree[nod] = Inf;
    if(st == dr)return;
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);
}
void update(int nod,int st,int dr,int poz)
{
    if(st == dr)
    {
        if(dq[poz].empty())tree[nod] = Inf;
        else tree[nod] = dp[dq[poz].front()];
        return;
    }
    int mij = (st + dr)>>1;
    if(poz <= mij)
        update(nod<<1,st,mij,poz);
    else
        update(nod<<1|1,mij+1,dr,poz);

    tree[nod] = min(tree[nod<<1],tree[nod<<1|1]);
}
int query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod];
    int mij = (st + dr)>>1;
    if(b <= mij)
        return query(nod<<1,st,mij,a,b);
    else if(a > mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    return min(query(nod<<1,st,mij,a,b),query(nod<<1|1,mij+1,dr,a,b));
}




int main()
{
    cin>>n>>k>>c;
    for(int i = 1; i <= n; ++i)
        cin>>h[i];

    build(1,1,V);
    dp[1] = 0;
    push(h[1],1);
    for(int i = 2; i <= n; ++i)
    {
        if(i - k - 1 >= 1)pop(h[i-k-1],i-k-1);
        dp[i] = Inf;
        for(int cub = 0; cub <= 100; ++cub)
        {
            int offset = (cub+1)*(cub+1)*(cub+1) - 1;
            int left = max(0,h[i] - offset);
            int right = min(V,h[i] + offset);
            int candidate = query(1,1,V,left,right) + cub + c;

            dp[i] = min(dp[i],candidate);
        }
        push(h[i],i);
    }

    cout<<dp[n];
    return 0;
}
