#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
using namespace std;
const int N = 809, V = 409;

int n, m, a[N][N], maxi;
ll ans;
int v[N];

bool p[V];
int mob[V];

void Precalc()
{
    FOR(i, 1, V - 1)p[i] = mob[i] = 1;

    FOR(i, 2, V - 1)
        if(p[i])
        {
            for(int j = i; j <= V - 1; j += i)
            {
                p[j] = 0;
                mob[j] *= -1;
            }
            for(int j = i * i; j <= V - 1; j += i * i)
                mob[j] = 0;

            p[i] = 1;
            mob[i] = -1;
        }
}

int main()
{
    cin >> n >> m;

    FOR(i, 1, n)
        FOR(j, 1, m)
            cin >> a[i][j], maxi = max(maxi, a[i][j]);

    Precalc();

    FOR(d, 1, maxi)
    {
        if(!mob[d])continue;

        FOR(j, 1, m)v[j] = 0;

        FOR(i, 1, n)
        {
            stack<int> stk;
            stk.push(0);
            ll cur = 0;

            FOR(j, 1, m)
            {
                if(a[i][j] % d)v[j] = 0;
                else v[j] ++;

                while(stk.size() > 1 && v[stk.top()] >= v[j])
                {
                    int top = stk.top();
                    stk.pop();

                    cur -= 1LL * v[top] * (top - stk.top());
                }
                cur += 1LL * v[j] * (j - stk.top());
                stk.push(j);

                ans += cur * mob[d];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
