#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORI(i, a, b) for(int i = a; i >= b; --i)
#define X first
#define Y second
#define ll long long
#define ull unsigned ll
using namespace std;
const int N = 2e5 + 9;

int n;
PI v[N];
PI stk[N]; int head;

int high, low;

ll cross_product(PI const& A, PI const& B, PI const& C)
{
    return 1LL * (B.X - A.X) * (C.Y - A.Y) - 1LL * (B.Y - A.Y) * (C.X - A.X);
}
ll dist(PI const& a, PI const& b)
{
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}
bool cmp(PI const& a, PI const& b)
{
    return cross_product(v[1], a, b) < 0;
}

void sort_points()
{
    int idx = 1;
    FOR(i, 2, n)
        if(v[i] < v[idx])
            idx = i;

    swap(v[1], v[idx]);
    sort(v + 2, v + n + 1, cmp);
}
vector<int> ans;
void build_hull()
{
    FOR(i, 1, n)
    {
        while(head >= 2 && cross_product(stk[head - 1], stk[head], v[i]) > 0)
            head --;
        stk[++ head] = v[i];
    }

    int idx = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(idx <= head && cross_product(v[1], v[i], stk[idx]) > 0)
        if(cross_product(v[1], v[i], stk[idx]) <= 0)
            ans.push_back(i);
    }
}

int main()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> v[i].X >> v[i].Y;
        high = max(high, v[i].Y);
        low = min(low, v[i].Y);
    }

    sort_points();
    build_hull();

    cout << ans.size();
    return 0;
}
