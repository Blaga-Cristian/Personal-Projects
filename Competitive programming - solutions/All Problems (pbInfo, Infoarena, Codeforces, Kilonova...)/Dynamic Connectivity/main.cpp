#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 30009, M = 1e5 + 9, Inf = 0x3f3f3f3f, MSZ = 100;

int n, m, w[N], t[N], cc, min_cc, list_count;
vector<int> lists[MSZ];
stack<PI> events;
inline int Find(int const& x)
{
    return (t[x] == 0) ? x : Find(t[x]);
}
inline void Unite(int const& x, int const& y)
{
    int rx = Find(x), ry = Find(y);
    if(rx == ry)return;

    if(w[rx] < w[ry])swap(rx, ry);

    t[ry] = rx;
    w[rx] += w[ry];
    events.push({ry, rx});
    cc --;
    min_cc = min(min_cc, cc);
}
inline void Rollback()
{
    if(events.empty())return;
    int ry = events.top().F, rx = events.top().S;
    t[ry] = 0;
    w[rx] -= w[ry];
    events.pop();
    cc ++;
}

struct muchie {
    int x, y, cost, ind;

    muchie(int x, int y, int cost, int ind) {
        this->x = x;
        this->y = y;
        this->cost = cost;
        this->ind = ind;
    }
};

vector<muchie> muchii;

struct query {
    int x, y, l, r;

    query(int x, int y, int l, int r) {
        this->x = x;
        this->y = y;
        this->l = l;
        this->r = r;
    }
};

vector<query> queries;

inline void solve(int const& l, int const& r, int const& list_id)
{

    int mij = (l + r) >> 1, sz = events.size(), llist = ++list_count, rlist = ++list_count;

    for(auto ind : lists[list_id])
    {
        auto q = queries[ind];
        if(q.l <= l && q.r >= r)Unite(q.x, q.y);
        else if(l != r)
        {
            if(q.l <= mij && q.r >= l)lists[llist].push_back(ind);
            if(q.r > mij && q.l <= r)lists[rlist].push_back(ind);
        }
    }

    if(l != r)
    {
        solve(l, mij, llist);
        solve(mij + 1, r, rlist);
    }

    while(events.size() != sz)Rollback();
    lists[list_id].clear();
    list_count--;

    cout << list_count << '\n';
}

inline bool ok(int const& val)
{
    queries.clear();
    memset(w, 1, sizeof(w));
    memset(t, 0, sizeof(t));
    cc = n;
    min_cc = n;
    list_count = 0;

    deque<muchie> dq;
    for(auto i : muchii)
    {
        dq.push_back(i);
        while(dq.back().cost - dq.front().cost > val)
        {
            queries.push_back(query(dq.front().x, dq.front().y, dq.front().ind, dq.back().ind - 1));
            dq.pop_front();
        }
    }
    while(!dq.empty())
    {
        queries.push_back(query(dq.front().x, dq.front().y, dq.front().ind, muchii.size()));
        dq.pop_front();
    }

    for(int i = 0; i < queries.size(); ++i)lists[0].push_back(i);
    solve(1, m, 0);

    return min_cc == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream in("weightdif.in");
    ofstream out("weightdif.out");

    in >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, cost;
        in >> x >> y >> cost;
        muchii.push_back(muchie(x, y, cost, 0));
    }

    sort(muchii.begin(), muchii.end(), [](muchie const& i, muchie const& j){return i.cost < j.cost;});

    for(int i = 0; i < muchii.size(); ++i)
        muchii[i].ind = i + 1;

    int st = 0, dr = Inf, mj, poz = -1;
    while(st <= dr)
    {
        mj = (st + dr) >> 1;
        if(ok(mj))
        {
            poz = mj;
            dr = mj - 1;
        }
        else
            st = mj + 1;
    }

    out << poz;
    return 0;
}
