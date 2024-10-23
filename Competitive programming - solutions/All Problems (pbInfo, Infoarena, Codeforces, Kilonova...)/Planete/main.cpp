#include<bits/stdc++.h>
#define N 200001
using namespace std;
int n,t[N],dp[N],st[N],k,st2[N],k2;
bool vz[N],sta[N];

void dfs(int x)
{
    st[++k]=x;
    sta[x]=vz[x]=true;
    if(!vz[t[x]])
    {
        dfs(t[x]);
        if(!dp[x])
            dp[x]=dp[t[x]]+1,sta[st[k--]]=false;
    }
    else
    {
        if(sta[t[x]])
        {
            k2=0;
            while(st[k]!=t[x])
                sta[st[k]]=false,st2[++k2]=st[k--];
            sta[st[k]]=false,st2[++k2]=st[k--];
            for(int j=1;j<=k2;++j)
                dp[st2[j]]=k2;
        }
        else
            dp[x]=dp[t[x]]+1,sta[st[k]]=false,--k;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&t[i]);
    for(int i=1;i<=n;++i)
        if(!dp[i])
            dfs(i);
    for(int i=1;i<=n;++i)
        printf("%d ",dp[i]);
    return 0;
}
