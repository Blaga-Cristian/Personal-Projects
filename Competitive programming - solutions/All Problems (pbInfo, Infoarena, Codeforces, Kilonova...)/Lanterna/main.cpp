#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream cin("lanterna.in");
ofstream cout("lanterna.out");
const int N = 59, K = 1009,Inf = 0x3f3f3f3f;
using pi = pair<int,int>;
using ppi = pair<int,pi>;
int n,k,m,a,b,t,c;
bool baza[N];
int tmp[N][K];
bool inq[N][K];
vector<vector<ppi>> G;

int BellFord(int cmax)
{
    queue<pi> q;
    memset(inq,0,sizeof(inq));
    memset(tmp,Inf,sizeof(tmp));
    tmp[1][cmax] = 0;
    inq[1][cmax] = true;
    q.push({cmax,1});

    while(!q.empty())
    {
        int c = q.front().first,
        x = q.front().second;
        inq[x][c] = false;
        q.pop();


        for(auto vecin : G[x])
        {
            int y = vecin.first,
            timp = vecin.second.first,
            cost = vecin.second.second;

            if(baza[y] && cost <= c && tmp[y][cmax] > tmp[x][c] + timp)
            {
                tmp[y][cmax] = tmp[x][c] + timp;
                if(!inq[y][cmax])
                {
                    q.push({cmax,y});
                    inq[y][cmax] = true;
                }
            }
            if(cost <= c && tmp[y][c-cost] > tmp[x][c] + timp)
            {
                tmp[y][c-cost] = tmp[x][c] + timp;
                if(!inq[y][cmax])
                {
                    q.push({c-cost,y});
                    inq[y][c-cost] = true;
                }
            }
        }
    }


    int ans = Inf;
    for(int c = 0; c <= cmax; ++c)
        ans = min(ans,tmp[n][c]);
    return ans;
}

int cb(int t)
{
    int st = 0, dr = k, poz = -1,mj;
    while(st <= dr)
    {
        mj = (st + dr)>>1;
        if(BellFord(mj) == t)
        {
            dr = mj - 1;
            poz = mj;
        }
        else
            st = mj + 1;
    }
    return poz;
}
int main()
{
    cin>>n>>k;
    G = vector<vector<ppi>>(n+1);
    for(int i = 1; i  <= n; ++i)
        cin>>baza[i];
    cin>>m;
    while(m--)
    {
        cin>>a>>b>>t>>c;
        G[a].push_back({b,{t,c}});
        G[b].push_back({a,{t,c}});
    }

    int tmin = BellFord(k);
    cout<<tmin<<' '<<cb(tmin);
    return 0;
}
