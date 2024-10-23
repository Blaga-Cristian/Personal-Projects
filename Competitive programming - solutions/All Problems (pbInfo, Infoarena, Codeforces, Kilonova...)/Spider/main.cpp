#include <fstream>
#define PI pair<int,int>
using namespace std;
ifstream cin("spider.in");
ofstream cout("spider.out");
const int N = 1009,di[] = {-1,0,1,0},dj[] = {0,1,0,-1};
PI outside = {-1,-1};
int n,m,mat[N][N];
int best[N][N][5]; ///dp[i][j][d] = drumul care incepe in i,j si care nu sare in directia d

int steps;
PI sol;

void read();
void solve();
int solve(int i,int j,int d);
pair<PI,int> getNextPosition(PI crt,PI prv);
void write();
int main()
{
    read();
    solve();
    write();
    return 0;
}
void read()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>mat[i][j];
}
int getHeight(PI pz)
{
    if(pz == outside)
        return -1;
    return mat[pz.first][pz.second];
}
bool valid(PI pz)
{
    return (pz.first>=1&&pz.first<=n&&pz.second>=1&&pz.second<=m);
}
pair<PI,int> getNextPosition(PI crt,PI prv)
{
    PI ret = outside;
    int dir = -1;

    for(int k=0;k<4;++k)
    {
        PI nxt = make_pair(crt.first + di[k], crt.second + dj[k]);
        if(nxt != prv && valid(nxt) && getHeight(ret) < getHeight(nxt) && getHeight(nxt) <= getHeight(crt))
        {
            ret = nxt;
            dir = k;
        }
    }

    return make_pair(ret,dir);
}
int solve(int x,int y,int d)
{
    if(best[x][y][d])
    {
        return best[x][y][d];
    }

    best[x][y][d] = 1;
    PI prv;

    if(d==4)
        prv = outside;
    else
        prv = {x + di[d],y+dj[d]};

    pair<PI,int> nxt = getNextPosition(make_pair(x,y),prv);

    if(nxt.first != outside)
    {
        best[x][y][d] += solve(nxt.first.first,nxt.first.second,(nxt.second+2)%4);
    }
    return best[x][y][d];
}
void solve()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int dist = solve(i,j,4);
            if(dist>steps)
            {
                steps = dist;
                sol = {i,j};
            }
        }
}
void write()
{
    cout<<steps-1<<'\n';
    PI prv = outside;
    while(sol!=outside)
    {
        cout<<sol.first<<' '<<sol.second<<'\n';
        PI aux = getNextPosition(sol,prv).first;

        prv = sol;
        sol = aux;
    }
}
