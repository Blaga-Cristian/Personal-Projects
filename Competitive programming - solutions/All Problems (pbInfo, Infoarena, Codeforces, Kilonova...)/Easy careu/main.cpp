#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
ifstream cin("miculprint.in");
ofstream cout("miculprint.out");


const int dx[] = {-1,0,0,1},dy[] = {0,-1,1,0};
const int N = 259;
using pi = pair<int,int>;
using ppi = pair<int,pi>;

int n,mat[N][N];
int viz[N][N];
bool fol[N][N];
char s[N];
int t[N][N];
int cnt;
vector<string> ans;

inline bool inmat(int x,int y)
{
    return (x > 0 && x <= n && y > 0 && y <= n);
}
bool Bfs(int x,int y)
{
    ++cnt;
    queue<ppi> q;
    memset(t,0,sizeof(t));
    t[x][y] = -1;
    q.push({x,{y,1}});
    viz[x][y] = cnt;
    pi endd = {-1,-1};

    while(!q.empty())
    {
        int x = q.front().first,
        y = q.front().second.first,
        poz = q.front().second.second;
        q.pop();

        if(poz == strlen(s))
        {
            endd = {x,y};
            break;
        }

        for(int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k],
            ny = y + dy[k];

            if(inmat(nx,ny) && viz[nx][ny] != cnt && mat[nx][ny] == s[poz] && !fol[nx][ny])
            {
                t[nx][ny] = k;
                viz[nx][ny] = cnt;
                q.push({nx,{ny,poz+1}});
            }
        }
    }

    if(endd.first != -1)
    {
        ans.push_back(s);
        while(true)
        {
            fol[endd.first][endd.second] = true;
            if(t[endd.first][endd.second] == -1)break;
            int a = t[endd.first][endd.second];
            endd.first -= dx[a];
            endd.second -= dy[a];
        }
        return true;
    }
    return false;
}

int main()
{
    cin>>n;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s,N);
        cin.get();
        for(int j = 0; j < strlen(s); ++j)
            mat[i][j+1] = s[j];
    }

    while(true)
    {
        cin.get(s,30);
        cin.get();
        bool ok = false;
        for(int i = 1; i <= n && !ok ; ++i)
            for(int j = 1; j <= n && !ok ; ++j)
                if(!fol[i][j])
                    ok = Bfs(i,j);
        if(cin.eof())break;
    }

    cout<<ans.size()<<'\n';
    for(auto i : ans)
        cout<<i<<'\n';
    return 0;
}
