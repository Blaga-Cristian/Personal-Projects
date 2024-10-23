#include <fstream>
#include <vector>
using namespace std;
ifstream cin("codul.in");
ofstream cout("codul.out");

string a,b;
int dp[203][203];
vector<int> ans;

int main()
{
    cin>>a>>b;
    for(int i = 1; i <= a.size(); ++i)
        for(int j = 1; j <= b.size(); ++j)
    {
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        if(a[i-1] == b[j-1])
            dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
    }

    int L = 1,val = -1,posi,posj;
    for(int i = 1; i <= a.size(); ++i)
        for(int j = 1; j <= b.size();++j)
    {
        if(dp[i][j] > L)
        {
            L ++;
            ans.push_back(val);
            val = -1;
            i = posi;
            j = posj;
        }
        else if(dp[i][j] == L)
        {
            if(a[i-1] - '0' > val)
            {
                val = a[i-1]-'0';
                posi = i;
                posj = j;
            }
        }
    }
    for(auto i : ans)
        cout<<i<<' ';
    return 0;
}
