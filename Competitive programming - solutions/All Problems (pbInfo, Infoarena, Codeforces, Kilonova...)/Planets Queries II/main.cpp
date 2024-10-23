#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9, LG = 25;
int n, m, t[N], T[N][LG], invt[N], a, b;


//For components
int cnt, comp[N], viz[N], ind[N], tcycle[N], dep[N];
vector<vector<int>> cycle;
stack<int> stk;
bool instk[N], incycle[N];


void DfsTree(int x)
{
    viz[x] = true;
    int y = t[x];

    if(incycle[y])
        tcycle[x] = y;

    if(!viz[y] && !incycle[y])
        DfsTree(y);

    dep[x] = dep[y] + 1;
    tcycle[x] = tcycle[y];
}
void Dfs(int x)
{
    viz[x] = true;
    stk.push(x);
    instk[x] = true;

    int y = t[x];
    if(!viz[y])
    {
        Dfs(y);
        comp[x] = comp[y];
    }
    else if(!instk[y])
        comp[x] = comp[y];
    else
    {
        comp[x] = cnt++;
        vector<int> aux;
        while(!stk.empty())
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            ind[a] = aux.size();
            aux.push_back(a);
            incycle[a] = true;
            if(a == y)break;
        }
        cycle.push_back(aux);
    }
}

void Preprocess()
{
    for(int i = 1; i <= n; ++i)
        T[i][0] = t[i];

    for(int k = 1; k < LG; ++k)
        for(int i = 1; i <= n; ++i)
            T[i][k] = T[T[i][k-1]][k-1];
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> t[i];

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            while(!stk.empty())
            {
                int a = stk.top();
                stk.pop();
                instk[a] = false;
            }
            Dfs(i);
        }


    //I find Depths
    memset(viz, false, sizeof(viz));
    for(int i = 1; i <= n; ++i)
        if(incycle[i])
            tcycle[i] = i;
    for(int i = 1; i <= n; ++i)
        if(!viz[i] && !incycle[i])
            DfsTree(i);

    Preprocess();

    while(m --)
    {
        cin >> a >> b;
        if(comp[a] != comp[b])
            cout << "-1\n";
        else if(tcycle[a] == tcycle[b])
        {
            if(dep[a] < dep[b])
                cout << "-1\n";
            else
            {
                int ans = 0;
                if(a == b)
                {
                    cout << ans << '\n';
                    continue;
                }

                for(int k = LG; k >= 0; --k)
                    if(dep[a] - (1 << k) > dep[b])
                    {
                        a = T[a][k];
                        ans += (1 << k);
                    }

                a = t[a];
                ans++;

                if(a == b)
                    cout << ans << '\n';
                else
                    cout << "-1\n";
            }

        }
        else if(incycle[b])
        {
            int ans = 0;
            ans += dep[a];
            a = tcycle[a];
            ans += dep[b];
            b = tcycle[b];

            if(ind[a] > ind[b])
                ans += ind[a] - ind[b];
            else
                ans += cycle[comp[a]].size() - (ind[b] - ind[a]);

            cout << ans << '\n';
        }
        else
            cout << "-1\n";
    }
    return 0;
}
