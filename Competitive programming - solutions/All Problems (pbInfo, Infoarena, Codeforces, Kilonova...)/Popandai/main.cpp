#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define int long long
#define double long double
using namespace std;
const string TASK("popandai2");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1009;

int n, x[N], y[N];

int next(int i)
{
    if(i < n)return i + 1;
    return 1;
}

int dot(int i, int j, int k)
{
    return (x[j] - x[i]) * (x[k] - x[i]) + (y[j] - y[i]) * (y[k] - y[i]);
}
int cross(int i, int j, int k)///ij->, ik->
{
    return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}

int aria(int i, int j, int k)
{
    return abs(cross(i, j, k));
}

signed main()
{
    cin >> n;

    FOR(i, 1, n)cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        int p1 = i, p2 = i + 1;

        for(int j = i + 1; j <= n; ++j)
        {
            while(p1 != j && aria(i, p1, j) <= aria(i, next(p1), j))
                p1 = next(p1);

            while(p2 != i && aria(i, p2, j) <= aria(i, next(p2), j))
                p2 = next(p2);

            ans = max(ans, aria(i, p1, j) + aria(i, p2, j));
        }
    }

    cout << ans / 2;
    if(ans % 2 == 1)cout << ".5\n";
    else cout << ".0\n";
    return 0;
}
