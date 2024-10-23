#include <fstream>
#include <cmath>
#define ull unsigned long long
using namespace std;
ifstream cin("comisia.in");
ofstream cout("comisia.out");
const int N = 200009;
ull n,risc[N],pers[N],mn = 1e18;
ull ST[N][20];
void process()
{
    for(int i=1;i<=n;++i)
        ST[i][0] = pers[i];

    for(int j=1; (1<<j) <= n; ++j)
        for(int i=1; i + (1<<j) - 1 <= n; ++i)
            ST[i][j] = max(ST[i][j-1],ST[i + (1<<(j-1))][j-1]);
}
ull Query(int i,int j)
{
    int k = log2(j-i+1);
    return max(ST[i][k],ST[j-(1<<k)+1][k]);
}
void sim(int p)
{
    ull l = pers[p], pi = p;
    while(p - pi + 1 < l && pi + l - 1 <= n)
        p = pi + l - 1,
        l = Query(pi,p);
    if(p - pi + 1 == l && pi + l - 1 <= n)mn = min(mn,risc[p] - risc[pi-1]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>pers[i];
    for(int i=1;i<=n;++i)
        cin>>risc[i],risc[i]+=risc[i-1];
    process();///rmq de pers (deocamdata)
    int st=1,dr=1;
    for(int i=1;i<=n;++i)sim(i);
    cout<<mn;
    return 0;
}
