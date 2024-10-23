#include <bits/stdc++.h>
#define ll long long
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 1e5 + 9;

int n;
int idx;
bool viz[2 * N];
vector<vector<PI>> G;
stack<int> stk;
char s[20];


void putB2(int x, int nrcif)
{
    for(int i = nrcif - 1; i >= 0; --i)
        if(x & (1 << i))
            cout << '1';
        else
            cout << '0';
}

int main()
{
    cin >> n;
    G = vector<vector<PI>>((1 << (n - 1)) + 9);

    for(int i = 0; i < (1 << (n - 1)); ++i)
    {
        int x1 = (i << 1) - ((1 << (n - 1)) & (i << 1));
        int x2 = (i << 1) + 1 - ((1 << (n - 1)) & ((i << 1) + 1));
        putB2(i, n - 1);
        cout << ' ';
        putB2(x1, n - 1);
        cout << ' ';
        putB2(x2, n - 1);
        cout << '\n';
        G[i].push_back({(i << 1) - ((1 << (n - 1)) & (i << 1)), ++idx});
        G[i].push_back({(i << 1) + 1 - ((1 << (n - 1)) & (i << 1)), ++idx});
    }

    stk.push_back(0);


    for(int i = stk.size(); i >= 0; --i)
    {
        putB2(stk[i], n - 1);
        cout << '\n';
    }
    return 0;
}
