#include <fstream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
ifstream cin("ramen.in");
ofstream cout("ramen.out");
const int N = 1e5 + 9;
int n,d;
int ans[N];
using pi = pair<int,int>;
vector<int> t,p;

class event
{
    public:
    int type,time;
    pi who;

    event(int _type,int _time,pi _who = pi())
    {
        type = _type;
        time = _time;
        who = _who;
    }

    bool operator < (event other) const
    {
        return ( time == other.time ) ? type > other.type : time < other.time;
    }
};

void solve()
{
    vector<event> events;
    for(int i = 1; i <= n; ++i)
    {
        events.push_back({0,t[i] + d,{p[i],i}});
        events.push_back({1,t[i] - p[i],{p[i],i}});
    }

    sort(events.begin(),events.end());

    set<pi> waiting;

    for(const auto & evnt : events)
    {
        if(evnt.type == 0)
        {
            auto a = *(waiting.begin());
            ans[a.second] = evnt.time + a.first;
            waiting.erase(waiting.begin());
        }
        else
            waiting.insert(evnt.who);
    }
}

int main()
{
    cin>>n>>d;
    t = p = vector<int>(n+1);
    for(int i = 1; i <= n; ++i)
        cin>>t[i]>>p[i];

    solve();

    for(int i = 1; i <= n; ++i)
        cout<<ans[i]<<'\n';
    return 0;
}
