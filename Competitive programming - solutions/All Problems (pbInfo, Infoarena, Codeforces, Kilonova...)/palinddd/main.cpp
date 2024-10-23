#include <fstream>

using namespace std;
ifstream cin("grexy.in");
ofstream cout("grexy.out");
const int mod = 666013;
int n,x;
int pow(unsigned long long baza,int exp)
{
    unsigned long long ans = 1;
    while(exp!=0)
    {
        if(exp&1)
        {
            ans = (ans * baza)% mod;
        }
        baza = (baza*baza)%mod;
        exp>>=1;
    }
    return ans;
}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x==1)cout<<0<<'\n';
        else cout<<(pow(26,x-1)*25)%mod<<'\n';
    }
    return 0;
}
