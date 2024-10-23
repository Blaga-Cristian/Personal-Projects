#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;

ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

class fmcm
{
    public :
    const int oo = 1e9;
    struct muchie
    {
        int cap,flow,cost,to,from;
        muchie(int a,int b,int c,int d,int e) : cap(a),flow(b),cost(c),to(d),from(e){}
    };

    vector<int> pi,real,ta; int s,t;
    vector<vector<int>> vecini;
    vector<muchie> muchii;

    fmcm(int _n,int _s,int _t) : s(_s),t(_t)
    {
        vecini.resize(_n+1); ta.resize(_n+1);
        pi.resize(_n+1,oo); real.resize(_n+1);
    }

    void add(int a,int b,int c,int d)
    {
        vecini[a].emplace_back(muchii.size()); muchii.push_back(muchie(c,0,d,b,a));
        vecini[b].emplace_back(muchii.size()); muchii.push_back(muchie(0,0,-d,a,b));
    }

    void boot()
    {
        queue<int> q; q.push(s); pi[s] = 0;
        bool inq[vecini.size()] = {0};
        while(!q.empty())
            {
                int v = q.front(); q.pop(); inq[v] = 0;
                for(auto &it : vecini[v])
                    {
                        if(!muchii[it].cap) continue;
                        int dist = muchii[it].cost + pi[v];
                        if(dist < pi[muchii[it].to])
                            {
                                pi[muchii[it].to] = dist;
                                if(!inq[muchii[it].to])
                                    {
                                        inq[muchii[it].to] = 1;
                                        q.push(muchii[it].to);
                                    }
                            }
                    }
            }
    }

    void dijkstra()
    {
        vector<int> dist(vecini.size(),oo); fill(real.begin(),real.end(),0);
        priority_queue<pii,vector<pii>,greater<pii>> pq; pq.push({0,s}); dist[s] = 0;
        while(!pq.empty())
            {
                pii varf = pq.top(); pq.pop();
                if(varf.first != dist[varf.second]) continue;
                for(auto &it : vecini[varf.second])
                    {
                        if(!(muchii[it].cap - muchii[it].flow)) continue;
                        int fcost = muchii[it].cost + pi[varf.second] - pi[muchii[it].to];
                        if(dist[muchii[it].to] > dist[varf.second] + fcost)
                            {
                                dist[muchii[it].to] = dist[varf.second] + fcost;
                                ta[muchii[it].to] = it; pq.push({dist[muchii[it].to],muchii[it].to});
                                real[muchii[it].to] = real[varf.second] + muchii[it].cost;

                            }
                    }

            }
    }

    pair<int,int> info()
    {
        int ansf(0),ansc(0);
        boot(); for(;;)
        {
            fill(ta.begin(),ta.end(),-1);
            dijkstra(); int delta = oo; if(ta[t] == -1) break;
            for(int i = ta[t]; i != -1 ; i = ta[muchii[i].from]) delta = min(delta,muchii[i].cap - muchii[i].flow);
            for(int i = ta[t]; i != -1 ; i = ta[muchii[i].from]) muchii[i].flow += delta,muchii[i^1].flow -= delta;
            pi.swap(real); ansf += delta; ansc += delta * pi[t];
        }

        return {ansf,ansc};
    }


};

int main()
{
    int n,m,s,t,a,b,c,d; cin >> n >> m >> s >> t;
    fmcm ans(n,s,t); while(m--)
    {
        cin >> a >> b >> c >> d;
        ans.add(a,b,c,d);
    }

    cout << ans.info().second;
}