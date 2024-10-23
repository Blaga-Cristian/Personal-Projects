#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 9;
int n,d,x,idx,pos[63];
unsigned long long curr,ans = 0;
unsigned long long p2[63];
bool p[301];
vector<int>prime;
unordered_map<long long,int> mp;
void Ciur()
{
    p[0] = p[1] = 1;
    prime.push_back(2);
    for(int i = 2; i*2 <= 300; ++i)
        p[i*2] = 1;
    for(int i = 3; i <= 300; ++i)
        if(p[i] == 0)
    {
        prime.push_back(i);
        for(int j = 2; j * i <= 300; ++j)
            p[i*j] = 1;
    }
}
int main()
{
    Ciur();
    mp[0] = 1;
    p2[0] = 1;
    for(int  i = 0; i < 62; ++i)
    {
        pos[prime[i]] = i;
        if(i) p2[i] = 2LL * p2[i-1];
    }
    cin>>n;
    cout<<ans<<'\n';
    for(int i = 1; i <= n; ++i)
    {
        cin>>x;
        idx = 0;
        while(x>1)
        {
            d = prime[idx++];
            if(d * d > x)
                d = x;
            while(x % (d*d)==0)
                x /= (d*d);
            if(x % d == 0)
                curr ^= p2[pos[d]],x/=d;
        }
        cout<<ans<<'\n';
        ans += mp[curr];
        ++mp[curr];
    }
    cout<<ans;
    return 0;
}
