#include <iostream>
#define N 1005
#include <iomanip>
#include <algorithm>
#define val first
#define cnt second
using namespace std;
const int Inf = 0x3f3f3f3f;
int a[N];
float dp[N];///dp[i] minimul de cuparat pana la indicele i, nr de obiecte cuplate inainte
int n;

float f3(int i)
{
    return min(min(a[i-2],a[i-1]),a[i]);
}
float f2(int i)
{
    return (min(a[i-1],a[i]))/2.0;
}

int main()
{
    long long sum = 0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum+=a[i];
    for(int i=1;i<=n;++i)
    {
        dp[i] = dp[i-1];
        if(i>=3)
            dp[i] = max(dp[i],max(dp[i-3]+f3(i),dp[i-2]+f2(i)));
        if(i>=2)
            dp[i] = max(dp[i],dp[i-2]+f2(i));
    }
    float ans = 0;
    cout<<fixed<<setprecision(1);
    cout<<1.0*sum-dp[n];
    return 0;
}
