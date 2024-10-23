#include <iostream>

using namespace std;
#define modulo (1000000007)
#define ull unsigned long long
int n,cnt;
void backt(int x,ull sum,ull prod)
{
    if(x==n+1)
    {
        if(sum==prod)++cnt,cnt%=modulo;
    }
    else for(int i=1;i<=9;++i)backt(x+1,sum+i,prod*i);
}
int main()
{
    cin>>n;
    backt(1,0,1);
    cout<<cnt;
    return 0;
}
