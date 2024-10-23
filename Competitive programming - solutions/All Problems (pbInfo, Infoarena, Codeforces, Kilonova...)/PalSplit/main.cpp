#include <iostream>

using namespace std;
int n;
int v[501],dp[501][501]; /// dp[i][j] = nr minim de stergeri necesare pentru a elimina secventa i...j
int PalSplit(int st,int dr)
{
    int mini = dr-st+1;
    for(int i=st;i<dr;++i)
        mini = min(mini , dp[st][i] + dp[i+1][dr]);
    return mini;
}
int main()
{
    cin>>n;
    /// citire si cazuri de baza
    for(int i=1;i<=n;++i)
    {
        cin>>v[i];
        dp[i][i] = 1;
        if(i>=2)
        {
            if(v[i]==v[i-1])
                dp[i-1][i] = 1;
            else
                dp[i-1][i] = 2;
        }
    }


    for(int len = 3;len<=n;++len)
        for(int i=1;i+len-1<=n;++i)
        {
            int j = i+len-1;
            if(v[i]==v[j])
                dp[i][j] = min(PalSplit(i,j),dp[i+1][j-1]);
            else dp[i][j] = PalSplit(i,j);
        }
    cout<<dp[1][n];
    return 0;
}
