#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,k;
multiset<int> low, high;
ll slow, shigh;
int x;
int v[200005];

void ins(int x)
{
    if(low.empty())
    {
        low.insert(x);
        return;
    }

    ll a = *low.rbegin();
    if(a > x)
    {
        slow += x;
        low.insert(x);
        if(low.size() > (k + 1) / 2)
        {
            shigh += *low.rbegin();
            slow -= *low.rbegin();
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
    else
    {
        shigh += x;
        high.insert(x);
        if(high.size() > k / 2)
        {
            slow += *high.begin();
            shigh -= *high.begin();
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
    }
}

void er(int val)
{
    if(high.find(val) != high.end())
    {
        shigh -= val;
        high.erase(high.find(val));
    }
    else
    {
        slow -= val;
        low.erase(low.find(val));
    }

    if(low.empty())
    {
        slow += *high.begin();
        shigh -= *high.begin();
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n ;++i)
    {
        cin >> v[i];
        ins(v[i]);
        if(i >= k)
        {
            cout << k * (*low.rbegin()) * low.size() - slow + (shigh - (*low.rbegin()) * high.size()) << ' ';
            er(v[i - k + 1]);
        }
    }
    return 0;
}
