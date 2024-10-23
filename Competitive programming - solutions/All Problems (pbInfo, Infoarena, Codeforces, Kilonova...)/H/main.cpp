#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
ifstream cin("11-h.in");
ofstream cout("h.out");
using pi = pair<int,int>;
const int N = 1009;
using ll = long long;
int n;
char x;
bool mat[N][N];
int sus[N][N],jos[N][N],st[N][N],dr[N][N];

using PQ = priority_queue<pi,vector<pi>,greater<pi>>;
PQ E;

ll aib[N];
void update(int poz,int val)
{
    for(;poz <= n; poz += poz & -poz)
        aib[poz] += val;
}
ll query(int poz)
{
    ll ret = 0;
    for(;poz; poz -= poz&-poz)
        ret += aib[poz];
    return ret;
}

void reset()
{
    E = PQ();
    memset(aib,0,sizeof(aib));
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin>>x;
            mat[i][j] = x-'0';
        }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(mat[i][j])
            {
                sus[i][j] = 1 + sus[i-1][j];
                st[i][j] = 1 + st[i][j-1];
            }
    for(int i = n; i >= 1; --i)
        for(int j = n; j >= 1; --j)
            if(mat[i][j])
            {
                jos[i][j] = 1 + jos[i+1][j];
                dr[i][j] = 1 + dr[i][j+1];
            }

    ll ans = 0;
    for(int i = 1; i <= n; ++i,reset())
        for(int j = 1; j <= n; ++j)
        {
            while(!E.empty() && E.top().first < j)
            {
                update(E.top().second,-1);
                E.pop();
            }

            int ln = min(sus[i][j],jos[i][j]) * 2 - 1;
            if(ln > 2)
                ans += query(ln);

            if(ln > 2 && dr[i][j] > 1)
            {
                update(ln,1);
                E.push({j + dr[i][j] - 1,ln});
            }
        }

    cout<<ans;
    return 0;
}
