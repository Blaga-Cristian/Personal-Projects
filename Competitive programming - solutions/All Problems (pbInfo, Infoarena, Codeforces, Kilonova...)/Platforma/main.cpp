#include <iostream>

using namespace std;
const int N = 15009;
int op,n,x;
int sp[N];
long long dp[N];///nr de platforme care se termina in i

int main()
{
    cin>>op;
    if(op==1)
    {
        cin>>n;
        bool ok = true;
        int cnt = 0,prv = -99999997;
        for(int i = 1; i <= n;++i)
        {
            cin>>x;
            if(x == prv && cnt == 0)
            {
                ok = 0;
                break;
            }
            else if(x == prv)
                cnt --;
            else
            {
                if(cnt != 0 || x != i)
                {
                    ok = 0;
                    break;
                }
                cnt = i-1;
            }
        }
        cout<<ok;
    }
    else if(op == 2)
    {
        cin>>n;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i-1];
            if(i % 2 == 1)
                dp[i] += dp[i/2];
        }
        cout<<dp[n];
    }
    else if(op == 3)
    {
        cin>>n>>ord;
        dp[n] = 0;
        for(int i = 1; i <= )
        {

        }
    }
    return 0;
}
