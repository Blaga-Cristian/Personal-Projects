#include <fstream>
#include <queue>
#include <cmath>
#include <limits>

#define pb push_back
#define mp make_pair
#define NMAX 100
#define KMAX 1000

using namespace std;
ifstream cin("expeditie.in");
ofstream cout("expeditie.out");

int dp[NMAX][NMAX][KMAX];
bool inQueue[NMAX][NMAX][KMAX];

int n, m, k;
int a[NMAX][NMAX];
int T[NMAX][NMAX];

queue<pair<pair<int, int>, int> > q;
pair<pair<int, int>, int> curr;

int INF = numeric_limits<int>::max();

int x[] = {-1, -1, 0, 1, 1, 1, 0, -1}, y[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Read()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>T[i][j];
}

bool verif(int i,int j)
{
    return (i>=1&&i<=n&&j>=1&&j<=m);
}

int Bf(int cap)
{
    int i,j,s;
    int time,capacity;
    pair<int,int> vt;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int s=0;s<=cap;++s)
                dp[i][j][s] = INF,
                inQueue[i][j][s] = false;
    q.push({{1,1},cap});
    dp[1][1][cap] = 0;
    inQueue[1][1][cap] = true;
    while(!q.empty())
    {
        i = q.front().first.first,
        j = q.front().first.second,
        s = q.front().second;

        if(a[i][j]<0)
        {
            dp[i][j][cap] = dp[i][j][s];
            s = cap;
        }
        for(int k=0;k<8;++k)
        {
            int ni = i+x[k],
            nj = j+y[k];
            if(!verif(ni,nj))continue;
            time = T[ni][nj];
            capacity = abs(a[ni][nj]);
            if(capacity <= s && dp[i][j][s] + time < dp[ni][nj][s-capacity])
            {
                dp[ni][nj][s-capacity] = dp[i][j][s] + time;
                if(!inQueue[ni][nj][s-capacity])
                {
                    inQueue[ni][nj][s-capacity] = true;
                    q.push({{ni,nj},s-capacity});
                }
            }
        }

        q.pop();
        inQueue[i][j][s] = false;
    }
    int minim = INF;
    for(i=0;i<=cap;++i)
        minim = min(minim,dp[n][m][i]);
    return minim;
}
void Solve()
{
    int left = 1,right = k,mid;
    int distmin = Bf(k);
    if(distmin==INF)
    {
        cout<<"Nu exista drum";
        return;
    }
    while(left<=right)
    {
        mid = (left + right)>>1;
        if(Bf(mid) == distmin)right = mid-1;
        else left = mid+1;
    }
    cout<<distmin<<'\n'<<left;
}
int main()
{
    Read();
    Solve();
    return 0;
}
