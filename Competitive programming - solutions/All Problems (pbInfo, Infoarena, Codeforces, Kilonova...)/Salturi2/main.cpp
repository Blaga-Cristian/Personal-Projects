#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream cin("salturi.in");
ofstream cout("salturi.out");
const int N = 1000009,Inf = 0x3f3f3f3f;
using PI = pair<int,int>;
int dp[N];
int n,a[N],pozmax;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        {cin>>a[i];
        if(i+a[i]>=n)a[i] = n - i;}
    int  p =0;
    dp[0]=0;
    int ok = 1;
    for(int i=0;i<n;++i)
    {
        if(p<i){ok = -1;break;}
        for(int j = p+1;j<=i+a[i];++j)
        {
            dp[j] = dp[i] + 1;
            ++p;
        }
    }
    if(ok==-1)dp[n] = 0;
    cout<<dp[n];

    return 0;
}
