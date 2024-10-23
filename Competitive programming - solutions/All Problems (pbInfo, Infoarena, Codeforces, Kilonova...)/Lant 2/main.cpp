#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("lant2.in");
ofstream cout("lant2.out");
const int N = 155;
char s[N][32];
int cnt,k;
int dp[N];
vector<int>sirad[N];
int lev[35][35];
int leven(char* a,char* b)
{
    ///move
    int n = strlen(a),m = strlen(b);
    for(int i=0;i<=n;++i)
        lev[i][m] = n - i;
    for(int j=0;j<=m;++j)
        lev[n][j] = m - j;

    for(int i = n-1;i>=0;--i)
        for(int j=m-1;j>=0;--j)
    {
        lev[i][j] = min(lev[i][j+1]+1,lev[i+1][j]+1);
        if(a[i] == b[j])
            lev[i][j] = min(lev[i][j],lev[i+1][j+1]);
    }

    return lev[0][0];
}
int main()
{
    char text[1010], *p;
    char sep[] = " ,:;.!?-";
    bool gasit;
    cin>>k;
    cin.get();
    cnt = 0;
    while(cin.getline(text,1001))
    {
        p = strtok(text,sep);
        while(p!=NULL)
        {
            gasit = false;
            for(int i=0;i<cnt&&!gasit;++i)
                if(strcmp(p,s[i]) == 0)
                    gasit = true;
            if(!gasit)
            {
                strcpy(s[cnt++],p);
            }
            p = strtok(NULL,sep);
        }
    }


    for(int i=0;i<cnt;++i)
        for(int j=i+1;j<cnt;++j)
            if(leven(s[i],s[j])<=k)
                sirad[i].push_back(j);

    dp[0] = 1;
    for(int i=0;i<cnt;++i)
        for(auto nod : sirad[i])
            dp[nod] += dp[i];

    int ans = 0;
    for(int i=0;i<cnt;++i)
        if(sirad[i].size() == 0)
            ans += dp[i];
    cout<<ans;
    return 0;
}
