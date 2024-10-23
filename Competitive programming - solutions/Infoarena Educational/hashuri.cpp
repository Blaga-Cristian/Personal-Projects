#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");
#define cin fin
#define cout fout

const int N = 1e6 + 9, P = 666013;

int n;
vvi G(P);

void Insert(int x){G[x % P].pb(x);}
void Erase(int x)
{
    auto it = find(G[x % P].begin(), G[x % P].end(), x);
    if(it != G[x % P].end())G[x % P].erase(it);
}
bool Find(int x){return find(G[x % P].begin(), G[x % P].end(), x) != G[x % P].end();}

int main()
{
    cin >> n;

    int op, x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> op >> x;
        if(op == 1)Insert(x);
        else if(op == 2)Erase(x);
        else cout << Find(x) << '\n';
    }
    return 0;
}