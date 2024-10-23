#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2e5 + 9;

int arr[N], n, cnt;

struct info
{
    ll st, dr, p, v;
};
vector<info> v;

void solve()
{
    v.clear();
    cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        if(arr[i] > 0)cnt ++;
    }

    ll MAXP = 2 * n, prod = 1;
    for(int i = 1; i <= n; ++i)
    {
        prod *= arr[i];
        if(prod > MAXP)break;
    }

    if(prod > MAXP)
    {
        int st = 1, dr = n;
        while(arr[st] == 1)st ++;
        while(arr[dr] == 1)dr --;
        cout << st << ' ' << dr << '\n';
        return;
    }

    for(int i = 1; i <= n; ++ i)
    {
        if(arr[i] == 1)continue;

        info a;
        a.st = a.dr = i;
        a.p = a.v = arr[i];

        while(i < n && arr[i + 1] > 1)
        {
            ++ i;
            a.p *= arr[i];
            a.v += arr[i];
            a.dr = i;
        }

        v.push_back(a);
    }


    int ans = 0, ansst = 1, ansdr = 1;
    for(int i = 0; i < v.size(); ++i)
    {
        ll prod = v[i].p, sm = v[i].v;

        if(ans <= prod - sm)
        {
            ans = prod - sm;
            ansst = v[i].st;
            ansdr = v[i].dr;
        }

        for(int j = i - 1; j >= 0; --j)
        {
            prod *= v[j].p, sm += v[j].v + (v[j + 1].st - v[j].dr - 1);

            if(ans <= prod - sm)
            {
                ans = prod - sm;
                ansst = v[j].st;
                ansdr = v[i].dr;
            }
        }
    }

    cout << ansst << ' ' << ansdr << '\n';
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
