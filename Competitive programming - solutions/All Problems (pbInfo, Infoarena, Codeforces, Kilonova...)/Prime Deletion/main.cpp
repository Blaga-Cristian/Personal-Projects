#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ans;
int sol;

bool prim(int nr)
{
    if(nr == 0 || nr == 1)return false;
    else if(nr == 2) return true;
    else if(nr % 2 == 0)return false;
    else
    {
        for(int i = 3; i * i <= nr; i += 2)
            if(nr % i == 0)return false;

        return true;
    }
}

void Back(int nr)
{
    if(nr < 10)return;
    if(prim(nr))
    {
        ans = true;
        sol = nr;
        return;
    }

    Back(nr);
    for(int i = 1; pow(10, i - 1) <= nr && !ans; ++i)
    {
        int aux;
        if(i == 1)aux = 0;
        else aux = nr % (int)(pow(10, i - 1));
        nr = (nr - (nr % (int)(pow(10, i)))) / 10;
        nr += aux;

        Back(nr);
    }
}

void solve()
{
    int n;
    ans = false;
    cin >> n;
    Back(n);
    if(ans)cout << sol << '\n';
    else cout << "-1\n";
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
