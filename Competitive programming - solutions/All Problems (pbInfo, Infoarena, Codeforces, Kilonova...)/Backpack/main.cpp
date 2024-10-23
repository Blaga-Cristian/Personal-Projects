#include <iostream>
#define ull unsigned long long
using namespace std;
const ull Inf = 9223372036854775807LL;
ull n,x,a,v[65];/// sunt cel mult 60 de bancnote
ull dp[65];/// dp[i] = nr minim de bancnote necesare pentru a face x diviz prin v[i+1] cu bancnote din intervalul 1...i
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    int cnt=0;
    for(int i=1;i<n;++i)
    {
        if(x==0)break;
        if(x%v[i+1]!=0 && v[i] <= x)
        {
            int low = (int(x/v[i+1])) * v[i+1],
            up = (int(x/v[i+1]) + 1) * v[i+1];
            if((x-low)/v[i] < (up-x)/v[i])
            {
                cnt+=(x-low)/v[i];
                x = low;
            }
            else
            {
                cnt+=(up-x)/v[i];
                x = up;
            }
        }
    }
    cnt += x/v[n];
    cout<<cnt;
    return 0;
}
