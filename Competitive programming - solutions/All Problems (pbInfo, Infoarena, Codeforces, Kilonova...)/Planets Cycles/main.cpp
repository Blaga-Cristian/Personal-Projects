#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9;
int n, t[N];


//For cycles
stack<int> stk;
bool instk[N], viz[N];
int DoCycle[N];


void Dfs(int x)
{
    viz[x] = true;
    stk.push(x);
    instk[x] = true;

    int y = t[x];
    if(!viz[y])
    {
        Dfs(y);
        if(DoCycle[x] == -1)DoCycle[x] = DoCycle[y] + 1;
    }
    else if(!instk[y])
    {
        if(DoCycle[x] == -1)DoCycle[x] = DoCycle[y] + 1;
    }
    else if(instk[y])
    {
        vector<int> aux;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            aux.push_back(a);
            if(a == y)break;
        }

        for(auto i : aux)
            DoCycle[i] = aux.size();
    }

    if(!stk.empty() && stk.top() == x)
    {
        stk.pop();
        instk[x] = false;
    }
}

int main()
{
    memset(DoCycle, -1, sizeof(DoCycle));

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> t[i];

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            Dfs(i);

    for(int i = 1; i <= n; ++i)
        cout << DoCycle[i] << ' ';
    return 0;
}
