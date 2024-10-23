#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const string TASK("kth");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 3e5 + 9;

int n, k, ln, q, v[N], ans[N];

multiset<int> l, r;
void insert(int x)
{
    l.insert(x);

    if(l.size() > k)
    {
        x = *l.rbegin();
        l.erase(l.find(x));
        r.insert(x);
    }
}
void remove(int x)
{
    if(r.find(x) != r.end())r.erase(r.find(x));
    else
    {
        l.erase(l.find(x));
        if(l.size() < k)
        {
            x = *r.begin();
            r.erase(r.find(x));
            l.insert(x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k >> ln;
    FOR(i, 1, n)cin >> v[i];

    FOR(i, 1, ln)insert(v[i]);
    ans[1] = *l.rbegin();

    for(int j = ln + 1; j <= n; ++j)
    {
        remove(v[j - ln]);
        insert(v[j]);
        ans[j - ln + 1] = *l.rbegin();
    }

    cin >> q;
    int p;
    FOR(i, 1, q)
    {
        cin >> p;
        cout << ans[p] << '\n';
    }
    return 0;
}
