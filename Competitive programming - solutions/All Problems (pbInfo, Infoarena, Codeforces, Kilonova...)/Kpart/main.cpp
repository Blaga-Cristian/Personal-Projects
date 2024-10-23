#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1009,Vm = 1e5 + 9;
int n,t;

int a[N],best[Vm],cnt[N];
void solve()
{
    memset(a,0,sizeof(a));
    memset(best,0,sizeof(best));
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        cin>>a[i],sum+=a[i];
    sum >>= 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = sum; j > a[i]; --j)
            best[j] = max(best[j],best[j-a[i]]);

        best[a[i]] = i;

        int sum = 0;
        for(int j = i; j >= 1; --j)
        {
            sum += a[j];
            if(!(sum % 2) && best[sum>>1] >= j)
                ++cnt[i-j+1];
        }
    }

    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        if(cnt[i] == n - i + 1)
            ans.push_back(i);

    cout<<ans.size()<<' ';
    for(auto i : ans)
        cout<<i<<' ';
    cout<<'\n';
}

int main()
{
    cin>>t;
    while(t--)
        solve();
    return 0;
}
