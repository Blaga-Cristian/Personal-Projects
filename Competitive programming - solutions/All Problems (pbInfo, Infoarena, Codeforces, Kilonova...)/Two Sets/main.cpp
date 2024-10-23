#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2 == 0)
    {
        if(n%4 == 0)
        {
            cout<<"YES\n";
            int k = n/4;
            cout<<n/2<<'\n';
            for(int i = 1; i <= n/2; ++i)
                if(i >= n/2 - k + 1)
                    cout<<2 * i<<' ';
                else
                    cout<<2*i - 1<<' ';
            cout<<'\n'<<n/2<<'\n';
            for(int i = 1; i <= n/2; ++i)
                if(i >= n/2 - k + 1)
                    cout<<2 *i - 1<<' ';
                else
                    cout<<2*i<<' ';
        }
        else
            cout<<"NO\n";
    }
    else
    {
        if((n/2+1)%2 == 0)
        {
            cout<<"YES\n";
            int k = (n/2 + 1)/2;
            cout<<n/2 + 1<<'\n';
            for(int i = 1; i <= n/2 + 1; ++i)
                if(i >= n/2 + 1 - k + 1)
                    cout<<2 * (i-1)<<' ';
                else
                    cout<<2 * i - 1<<' ';
            cout<<'\n'<<n/2<<'\n';
            for(int i = 1; i <= n/2; ++i)
                if(i >= n/2 - k + 1)
                    cout<<2 * (i + 1) - 1<<' ';
                else
                    cout<<2 * i<<' ';
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
