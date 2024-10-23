#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n,k,i;
    cin>>k>>n;
    if(n<k)cout<<0;
    else
    {
        long long p=1;
        for(i=n-k+1;i<=n;i++)
        {
            p=p*i;
            if(p>224737)p=p%224737;
        }
        cout<<p%224737;
    }
    return 0;
}
