#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("ubuntzei.in");
ofstream cout("ubuntzei.out");
#define per pair<int,int>
using PI = pair<int,int>;

const int Inf = 0x3f3f3f3f,Nmax = 2000;

int dp[1<<17][17];
int n,m,k;
int tr[Nmax];
vector<vector<PI> >v;
vector<int> dr;
vector<vector<int> >dist;
priority_queue<PI, vector<PI>,greater<PI>>pq;


void dijkstra(int pr){
    for(int i = 1; i <= n; i++)
        dr[i] = Inf;

    pq.push({0, pr});
    dr[pr] = 0;

    while(!pq.empty()){
        per x = pq.top();
        pq.pop();

        for(auto y: v[x.second])
        if(dr[y.first] > dr[x.second] + y.second){
            dr[y.first] = dr[x.second] + y.second;
            pq.push({dr[y.first], y.first});
        }
    }
}


int main()
{
    dist = vector<vector<int>>(n+3,vector<int>(n+3,Inf));
    v = vector<vector<PI>>(n+1);
    dr = vector<int>(n+1);
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++)
        cin >> tr[i];

    tr[0] = 1;
    tr[k + 1] = n;

    for(int i = 1; i <= m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }

    for(int i = 0; i <= k + 1; i++){
        dijkstra(tr[i]);

        for(int j = 0; j <= k + 1; j++)
            dist[i][j] = dist[j][i] = dr[tr[j]];
        dist[i][i] = Inf;
    }


    for(int i = 0; i < (1 << (k + 2)); i++)
        for(int j = 0; j <= k + 1; j++)
            dp[i][j] = Inf;

    dp[0][0] = dist[0][0] = 0;
    for(int i = 0; i < (1 << (k + 2)); i++)
        for(int j = 0; j <= k + 1; j++)
            if(i & (1 << j))
                for(int l = 0; l <= k + 1; l++)
                    dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][l] + dist[j][l]);

    cout << dp[(1 << (k + 2)) - 1][k + 1];

    return 0;
}
