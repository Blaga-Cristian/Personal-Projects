#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("dungeon.in");
ofstream cout("dungeon.out");
int t,n,x,y;
void dfs(int x,vector<vector<int>>& sirad,vector<bool>& used)
{
    if(used[x])
        return;
    used[x] = true;
    for(auto& i : sirad[x])
        dfs(i,sirad,used);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<vector<int>>sirad(2*n+3);
        for(int i=1;i<n;++i)
        {
            cin>>x>>y;
            sirad[x].push_back(y);
            sirad[y].push_back(x);
        }
        for(int i=1;i<n;++i)
        {
            cin>>x>>y;
            sirad[x].push_back(y);
            sirad[y].push_back(x);
        }

        vector<bool> matched(2*n+3,false);
        vector<vector<int>>matching(2*n+3);
        for(int i=1;i<=n;++i)
        {
            cin>>x>>y;
            matched[x] = matched[y] = true;
            matching[x].push_back(y);
            matching[y].push_back(x);
        }

        vector<bool> used(2*n+3,false);
        dfs(1,sirad,used);
        dfs(n+1,sirad,used);

        queue<int>q;
        vector<int>degree(2*n+5,0);
        for(int i=1;i<2*n+2;++i)
        {
            degree[i] = sirad[i].size();
            if(degree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto& x : sirad[node])
            {
                if(degree[x]>0)
                {
                    sirad[x].push_back(node);
                    sirad[node].push_back(x);
                    degree[node] = 0;
                    degree[x] = 0;
                    for(auto& y : sirad[x])
                        if(--degree[y] == 1)
                            q.push(y);
                }
            }
        }

        bool ok = 1;
        for(int i=1;i<2*n+2;++i)
            if(matching[i].size()!=2)
                ok = 0;
        if(!ok)
        {
            cout<<"-1\n";
            continue;
        }

        vector<int> answer;
        int node = 1;
        int last = -1;
        do
        {
            answer.push_back(node);
            for(int i=0;i<2;++i)
                if(matching[node][i] != last)
            {
                int next = matching[node][i];
                last = node;
                node = next;
                break;
            }
        }while(node!=1);
        if(answer.size() != 2*n)
        {
            cout<<"-1\n";
            continue;
        }

        for(auto& x : answer)
            cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}
