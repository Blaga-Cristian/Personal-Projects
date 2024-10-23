#include <fstream>

using namespace std;
ifstream cin("summax1.in");
ofstream cout("summax1.out");
const int N = 2005,MAX = 2*1e9;
const long long Inf = 9223372036854775807LL;
int cer,n,st,dr;
int v[N][N];
int trs[N][N],sum[N][N];
int inv[N][N]; ///inv[i][j] = nr de drumuir maxime ce incep in i,j
bool ok[N][N];
int main()
{
    cin>>cer>>n>>st>>dr;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cin>>v[i][j];
    if(cer==1)
    {
        int mx = 0;
        trs[1][1] = 1;
        sum[1][1] = v[1][1];
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
        {
            if(sum[i][j] < sum[i-1][j] + v[i][j])
            {
                sum[i][j] = sum[i-1][j] + v[i][j];
                trs[i][j] = trs[i-1][j];
            }
            if(sum[i][j] < sum[i-1][j-1] + v[i][j])
            {
                sum[i][j] = sum[i-1][j-1] + v[i][j];
                trs[i][j] = trs[i-1][j-1];
            }
            else if(sum[i][j] == sum[i-1][j-1] + v[i][j])
                trs[i][j] += trs[i-1][j-1];
            mx = max(sum[i][j],mx);
        }
        long long ans = 0;
        for(int i=1;i<=n;++i)
            if(sum[n][i] == mx)ans+=trs[n][i];
        if(ans > MAX)cout<<MAX+1;
        else cout<<ans;
    }
    else
    {
        int mx = 0;
        trs[1][1] = 1;
        sum[1][1] = v[1][1];
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
        {
            if(sum[i][j] < sum[i-1][j] + v[i][j])
            {
                sum[i][j] = sum[i-1][j] + v[i][j];
                trs[i][j] = trs[i-1][j];
            }
            if(sum[i][j] < sum[i-1][j-1] + v[i][j])
            {
                sum[i][j] = sum[i-1][j-1] + v[i][j];
                trs[i][j] = trs[i-1][j-1];
            }
            else if(sum[i][j] == sum[i-1][j-1] + v[i][j])
                trs[i][j] += trs[i-1][j-1];
            mx = max(sum[i][j],mx);
        }
        for(int i=1;i<=n;++i)
            if(sum[n][i] == mx)
                ok[n][i] = 1,
                inv[n][i] = 1;
        for(int i=n;i>1;--i)
            for(int j=1;j<=i;++j)
        {
            if(ok[i][j] && sum[i-1][j] == sum[i][j] - v[i][j])ok[i-1][j] = 1;
            if(ok[i][j] && sum[i-1][j-1] == sum[i][j] - v[i][j])ok[i-1][j-1] = 1;
        }
        for(int i=n;i>1;--i)
            for(int j=1;j<=i;++j)
        {
            if(ok[i-1][j])inv[i-1][j] += inv[i][j];
            if(ok[i-1][j-1])inv[i-1][j-1] += inv[i][j];
        }
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=i;++j)
                cout<<inv[i][j]<<' ';

    }
    return 0;
}
