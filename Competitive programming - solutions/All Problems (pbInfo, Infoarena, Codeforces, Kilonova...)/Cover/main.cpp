#include <fstream>
#include <algorithm>
#include <deque>
#define INF  1999999999
#define NMAX 1000005
using namespace std;
ifstream cin("cover.in");
ofstream cout("cover.out");
using PII = pair<int,int>;

int w[NMAX], m[NMAX];
vector<PII> E, F;
int n,l,N, K, R, i, j, k, q, Ans = INF;
int v[NMAX], t[NMAX], vb, ve;

inline void push(int key,int time)
{
    for(;vb<=ve&&key < v[ve];--ve);
    ++ve, v[ve] = key,t[ve] = time;
}
inline void pop(int time)
{
    for(; vb<=ve && t[vb] < time; ++vb);
}
int cmp(PII a, PII b)
{
    if (a == b) return a.first > b.first ? 1 : 0;
    else return a.second < b.second ? 1 : 0;
}
int main()
{
    int a,b;
    cin>>n>>l;
    for(int i=1;i<=l;++i)
        cin>>w[i];
    for(int i=1;i<=n;++i)
        cin>>a>>b,
        F.push_back(make_pair(a,b));
    sort(F.begin(),F.end(),cmp);
    int lst = 0;
    for(int i=0;i<n;++i)
        if(F[i].first > lst)E.push_back(F[i]),lst = F[i].first;

    m[0] = 0;
    vb = ve = 0, v[0] = t[0] = 0;
    q = -1;
    for(int i=1;i<=l;++i)
    {
        for(;q+1<E.size()&&E[q+1].second < i;++q);
        if(q>=0)pop(E[q].first);
        m[i] = w[i] + v[vb];
        push(m[i],i);
    }
    int ans = INF;
    for(int i = E[E.size()-1].first; i<=E[E.size()-1].second;++i)
        if(m[i]<ans)
            ans = m[i];
    cout<<ans;
    return 0;
}
