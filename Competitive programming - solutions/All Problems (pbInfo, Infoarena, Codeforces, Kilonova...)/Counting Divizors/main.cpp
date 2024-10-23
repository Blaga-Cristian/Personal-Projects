#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9, V = 1e6 + 9;

int ans, cnt[V];



vector<bool> nprim(V);
vector<int> prime;
void Ciur()
{
    nprim[0] = nprim[1] = true;

    for(int i = 2; i < V; ++i)
        if(!nprim[i])
        {
            prime.push_back(i);
            for(int j = 2; i * j < V; ++j)nprim[i * j] = true;
        }
}


int main()
{
    Ciur();
    int n, x, mx = 0;
    cin >> n;

    while(n --)
    {
        cin >> x;
        cnt[x] ++;
    }

    for(int gcd = V; gcd > 0; --gcd)
    {
        int nr = 0;
        for(int j = gcd; j < V; j += gcd)nr += cnt[j];
        if(nr >= 2)
        {
            cout << gcd << '\n';
            return 0;
        }
    }
    return 0;
}
