#include <fstream>
#include <vector>
using namespace std;
ifstream cin("sormin.in");
ofstream cout("sormin.out");
const int N = 1e5 + 9,MaxV = 5000,LgMax = 13;

int n,s;
vector<int> solvewithprefix(vector<int>& cnt,int s,int prefix)
{
    vector<int> a(s+1,-1);
    a[0] = 0;
    vector<int> link(s+1);
    for(int x = 0; x < cnt.size(); ++x)
    {
        if( (x | prefix) > prefix)continue;
        if(!cnt[x])continue;
        for(int i = 0; i <= s; ++i)
        {
            if(a[i] >= 0)
            {a[i] = cnt[x];}
            else if( i >= x && a[i-x] > 0)
            {a[i] = a[i-x] - 1;link[i] = i-x;}
            else
            {a[i] = -1;}
        }
    }

    vector<int> sol;
    for(int i = s; i && a[i] >= 0; i = link[i])
        sol.push_back(i - link[i]);

    return sol;
}
int main()
{
    cin>>n>>s;
    vector<int> cnt (LgMax+1);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }

    int prefix = (1<<(LgMax+1)) - 1;
    for(int bit = 1 << LgMax; bit; bit >>= 1)
        if(solvewithprefix(cnt,s,prefix^bit).size())
            prefix ^= bit;

    auto ans = solvewithprefix(cnt,s,prefix);
    if(ans.size())
    {
        cout<<prefix<<' '<<ans.size()<<'\n';
        int y[10002],ny = 0;
        for(auto x : ans)y[++ny] = x;
        for(int i = ny; i >= 1; --i)
            cout<<y[i]<<' ';
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
