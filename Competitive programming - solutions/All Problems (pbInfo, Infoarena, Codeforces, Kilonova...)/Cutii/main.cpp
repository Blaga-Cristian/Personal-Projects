#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("cutii.in");
ofstream cout("cutii.out");
const int N = 3509;
struct cuti
{
    int x,y,z;
    bool operator < (const cuti &c) const
    {
        return z < c.z;
    }
};

int aib[N + 10][N + 10]; /// aib[x][y] - nr maxim de cutii cu _x < x && _y<y
                        /// care pot fi incuibate

void Update(int cx,int cy,int val)
{
    for(int i = cx ; i<= N; i += i&-i)
        for(int j = cy ; j<= N ; j += j&-j)
            aib[i][j] = max(aib[i][j],val);
}
int Query(int cx,int cy)
{
    int mx = 0;
    for(int i = cx; i; i-=i&-i)
        for(int j = cy;j;j-=j&-j)
            mx = max(mx,aib[i][j]);
    return mx;
}
void Reset(int cx,int cy)
{
    for(int i = cx ; i<= N; i += i&-i)
        for(int j = cy ; j<=N ; j += j&-j)
            aib[i][j] = 0;
}

int Solve(int n)
{
    vector<cuti> C;
    int x, y, z;

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        cuti a;
        a.x = x;
        a.y = y;
        a.z = z;
        C.push_back(a);
    }
    sort(C.begin(),C.end());

    int ans = 0;
    for(const auto& c : C)
    {
        int d = Query(c.x-1,c.y-1) +1;
        ans = max(ans,d);
        Update(c.x,c.y,d);
    }

    for(const auto& c : C)
        Reset(c.x,c.y);

    return ans;
}
int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=t;++i)
        cout<<Solve(n)<<'\n';
    return 0;
}
