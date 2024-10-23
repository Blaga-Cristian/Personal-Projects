#include <iostream>
#include <algorithm>
using namespace std;
int arr1[509],arr2[509],dp[509][509],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr1[i],arr2[i] = arr1[i];
    reverse(arr2+1,arr2+n+1);
    cout<<endl;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        if(arr1[i] == arr2[j])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    for(int i=1;i<=n;++i,cout<<endl)
        for(int j=1;j<=n;++j)
            cout<<dp[i][j]<<' ';
    return 0;
}
