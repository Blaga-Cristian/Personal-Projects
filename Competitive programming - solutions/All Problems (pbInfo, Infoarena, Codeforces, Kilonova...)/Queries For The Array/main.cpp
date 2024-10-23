#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 9;

string s;
int ndec[N];

void solve()
{
    cin >> s;

    int sz = 0, sorted = 2; /// 2 - stiu sigur ca e crescator, 1 - nu stiu, 0 - e descrescator
    ndec[0] = ndec[1] = 2;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '+')
        {
            if(sz == 0)++sz;
            else if(ndec[sz] == 2 || ndec[sz] == 1)ndec[++sz] = 1;
            else if(ndec[sz] == 0)ndec[++sz] = 0;
        }
        else if(s[i] == '-')
        {
            if(ndec[sz] == 2)ndec[sz - 1] = 2;
            --sz;
        }
        else if(s[i] == '1')
        {
            if(ndec[sz] == 0)
            {
                cout << "NO\n";
                return;
            }
            ndec[sz] = 2;
        }
        else if(s[i] == '0')
        {
            if(ndec[sz] == 2)
            {
                cout << "NO\n";
                return;
            }
            ndec[sz] = 0;
        }
    }

    cout << "YES\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
