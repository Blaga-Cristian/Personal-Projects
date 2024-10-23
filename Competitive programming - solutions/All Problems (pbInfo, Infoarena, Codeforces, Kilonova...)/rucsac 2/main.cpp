#include <fstream>

using namespace std;
ifstream cin("bete.in");
ofstream cout("bete.out");



const int Inf = 0x3f3f3f3f;
bool dp[100009];
int l[1009];
int t[100009];
int n,S;
void scrie (int s,int cnt)
{
    if(s==0)cout<<cnt<<'\n';
    else
    {
        scrie(s - l[t[s]],cnt+1);
        cout<<t[s]<<' ';
    }
}
int main()
{
    long long smax=0;
    cin>>n>>S;
    for(int i=1;i<=n;++i)cin>>l[i],smax+=l[i];

    if(S>smax)
    {
        cout<<"NU";
        return 0;
    }

    dp[0]=1;
    for(int i=1;i<=n;++i)
        for(int j = S-l[i];j>=0;--j)
            if(dp[j])
                dp[j+l[i]] = 1,
                t[j+l[i]] = i;
    if(dp[S])
    {
        cout<<"DA\n";
        scrie(S,0);
    }
    else cout<<"NU";
    return 0;
}
