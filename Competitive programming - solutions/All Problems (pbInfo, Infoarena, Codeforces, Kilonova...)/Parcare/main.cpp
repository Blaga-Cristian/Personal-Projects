#include <bits/stdc++.h>
#define pb push_back
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
#define ull unsigned ll
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define ALL(v) v.begin(), v.end()
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
ifstream fin("parcare.in");
ofstream fout("parcare.out");
const int N = 2e5 + 9;

int n, m, t;
int ans[N], parcare[N];

struct event
{
    int x, idx;
    bool leaving;

    bool operator < (event const& a) const noexcept
    {
        return x == a.x ? leaving < a.leaving : x < a.x;
    }
};
vector<event> events;

int main()
{
    fin >> n >> m >> t;

    int s, d;
    REP(i, 1, m)
    {
        fin >> s >> d;
        events.pb({s, i, 0});
        events.pb({d, i, 1});
    }

    sort(ALL(events));

    queue<int> q;
    REP(i, 1, n)q.push(i);
    fill(parcare, parcare + n + 1, -1);

    for(auto e : events)
        if(e.x > t)break;
        else if(!e.leaving)
        {
            if(q.empty())ans[e.idx] = -1;
            else
            {
                int f = q.front();
                ans[e.idx] = f;
                parcare[f] = e.x;
                q.pop();
            }
        }
        else if(ans[e.idx] != -1)
        {
            q.push(ans[e.idx]);
            parcare[ans[e.idx]] = -1;
        }

    REP(i, 1, m)
        fout << ans[i] << '\n';
    REP(i, 1, n)
        fout << parcare[i] << ' ';
    return 0;
}
