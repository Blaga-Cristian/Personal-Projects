#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back

using namespace std;
string TASK("infasuratoare");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e5 + 9;
const int Inf = 0x3f3f3f3f;
bool test_case = false;

typedef pair<double, double> point;
#define x first
#define y second
int n;
point stk[N];
point a[N];

point operator - (point a, point b)
{
    return {a.ff - b.ff, a.ss - b.ss};
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

void solve()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i].x >> a[i].y;

    int p = 1;
    FOR(i, 2, n)
        if(a[p] > a[i])
            p = i;

    swap(a[1], a[p]);
    sort(a + 2, a + n + 1, [](point x, point y)
         {
            return cross(x - a[1], y - a[1]) < 0;
         });

    int sz = 0;
    FOR(i, 1, n)
    {
        while(sz > 1 && cross(stk[sz] - stk[sz - 1], a[i] - stk[sz - 1]) > 0)
            -- sz;
        stk[++ sz] = a[i];
    }

    cout << sz << '\n';
    cout << fixed << setprecision(12);
    FORR(i, sz , 1)
        cout << stk[i].ff << ' ' << stk[i].ss << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    if(test_case)cin >> t;
    while(t --)
        solve();
    return 0;
}