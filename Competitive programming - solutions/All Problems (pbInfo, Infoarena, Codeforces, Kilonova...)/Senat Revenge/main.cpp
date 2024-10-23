#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream cin("senat.in");
ofstream cout("senat.out");
const int N = 109,Inf = 0x3f3f3f3f;
string s;
int n,m,a,b;
int C[2*N][2*N],t[2*N],ans[N];
vector<vector<int>> G;
bitset<2*N> v;
queue<int> q;

bool Bf(int source,int sink)
{
    v.reset();
    v[source] = 1;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
            if(!v[y] && C[x][y] > 0)
            {
                v[y] = 1;
                t[y] = x;
                q.push(y);
            }
    }

    return v[sink];
}

int MaxFlow(int source,int sink)
{
    int maxflow = 0,fmin;
    while( Bf(source,sink) )
        for(auto x : G[sink])
        {
            if(!v[x] || C[x][sink] < 0)continue;

            fmin = Inf;
            for(int i = sink; i != source; i = t[i])
                fmin = min(fmin,C[t[i]][i]);

            if(fmin == 0)continue;

            int mcor, ncor;
            for(int i = sink; i != source; i = t[i])
            {
                if(i < sink && i > n)
                    mcor = i;
                if(i > source && i <= n)
                    ncor = i;
                C[t[i]][i] -= fmin;
                C[i][t[i]] += fmin;
            }
            maxflow += fmin;
            ans[mcor-n] = ncor;
        }

    return maxflow;
}
int main()
{
    cin>>n;
    cin.get();
    cin>>m;
    cin.get();
    G = vector<vector<int>>(n+m+2);
    for(int i = n+1; i <= n + m; ++i)
    {
        getline(cin,s);

        int k = 0;
        for(;k < s.length() && s[k] == ' '; ++k);

        while(k < s.length())
        {
            int nr = 0;
            while(k < s.length() && s[k] != ' ')
                nr = nr*10 + (s[k++] - '0');

            G[nr].push_back(i);
            G[i].push_back(nr);
            C[nr][i] = 1;

            while(k < s.length() && (s[k] == ' ') || (s[k] == '\n'))
                ++k;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        G[0].push_back(i);
        G[i].push_back(0);
        C[0][i] = 1;
    }
    for(int i = n + 1; i <= n + m; ++i)
    {
        G[i].push_back(n+m+1);
        G[n+m+1].push_back(i);
        C[i][n+m+1] = 1;
    }

    int maxflow = MaxFlow(0,n+m+1);

    if(maxflow < m)
        cout<<'0';
    else
    {
        for(int x = n+1; x <= n + m; ++ x)
            for(auto y : G[x])
                if(C[y][x] == 0)
                    cout<<y<<'\n';
    }
    return 0;
}
