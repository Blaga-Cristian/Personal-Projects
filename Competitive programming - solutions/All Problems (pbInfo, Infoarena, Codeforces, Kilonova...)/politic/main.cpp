#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("politic.in");
ofstream cout("politic.out");

typedef vector<vector<int>> Graph;

vector<set<int>> findCycles(vector<int>& fathers)
{
    int size = fathers.size();
    vector<int> visited = vector<int>(size,-1);
    vector<set<int>>cycles;
    for(int u = 0; u<fathers.size();++u)
    {
        if(visited[u] == -1)
        {
            int v = u;
            do
            {
                visited[v] = u;
                v = fathers[v];
            }while(fathers[v] == -1);
            if(visited[v] == u)
            {
                set<int> cycle;
                int firstOnCycle = v;
                do
                {
                    cycle.insert(v);
                    v = fathers[v];
                }while(v!=firstOnCycle);
                cycles.push_back(cycle);
            }
        }
    }
    return cycles;
}
vector<int> solveTree(const Graph &tree, const int u)
{
    vector<int> dp = vector<int>(2,1);
    for(auto& v : tree[u])
    {
        vector<int> sonDp = solveTree(tree,v);
        vector<int> newDp = vector<int>(dp.size() + sonDp.size() -1 , 0);
        newDp[0] = 1;
        for(int i=1;i<dp.size();++i)
            for(int j=0;j<sonDp.size();++j)
                newDp[i+j] = max(newDp[i+j],dp[i] + sonDp[j]);
        dp = newDp;
    }
    return dp;
}
vector<int> mergeDp(const vector<int> &firstDp, const vector<int> &secondDp)
{
    vector<int> newDp = vector<int>(firstDp.size() + secondDp.size() - 1, 0);
    for(int i=0;i<firstDp.size();++i)
        for(int j=0;j<secondDp.size();++j)
            newDp[i+j] = max(newDp[i+j],firstDp[i] + secondDp[j]);
    return newDp;
}
vector<int> solveCycle(const Graph &graph, const set<int> &cycle)
{
    int length = cycle.size();
    vector<int> dp = vector<int>(1,0);
    for(const auto& cycleNode : cycle)
        for(const auto& root : graph[cycleNode])
            if(cycle.find(root)==cycle.end())
                dp = mergeDp(dp,solveTree(graph,root));
    vector<int> cycleDp = vector<int>(length + dp.size());
    for(int i=0;i<length;++i)
        cycleDp[i] = i;
    for(int i = length ; i<cycleDp.size();++i)
        cycleDp[i] = length + dp[i - length];
    return cycleDp;
}
vector<int> solveGraph(vector<int>& fathers)
{
    int size = fathers.size();
    Graph graph = Graph(size);
    for(int i=0;i<size;++i)
        graph[fathers[i]].push_back(i);
    vector<set<int>> cycles = findCycles(fathers);
    vector<int> dp = vector<int>(1,0);
    for(const set<int>& cycle : cycles)
        dp = mergeDp(dp,solveCycle(graph,cycle));
    return dp;
}
vector<int> readInput()
{
    int size;
    cin>>size;
    vector<int> fathers = vector<int>(size);
    for(int i=0;i<size;++i)
    {
        cin>>fathers[i];
        fathers[i]--;
    }
    return fathers;
}
void write(vector<int>& remaining)
{
    for(int i=1;i<remaining.size();++i)
        cout<<i<<'\n';
}
int main()
{
    auto fathers = readInput();
    auto remaining = solveGraph(fathers);
    for(int i=0;i<remaining.size();++i)
        remaining[i] = fathers.size() - remaining[i];
    write(remaining);
    return 0;
}
