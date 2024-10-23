#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const int N = 2e5 + 9, D = 25;

int n, a[N], s[N];

struct trie
{
    trie* sons[2];
    trie()
    {
        sons[0] = sons[1] = 0;
    }
};
trie* t = new trie();
void add(int x, int dep = D, trie* nod = t)
{
    if(dep == -1)return;

    bool bit = ((x & (1 << dep)) != 0);

    if(!nod->sons[bit])nod->sons[bit] = new trie();

    add(x, dep - 1, nod->sons[bit]);
}
int find_max(int x, int dep = D, trie* nod = t)
{
    if(dep == -1)return 0;

    bool bit = ((x & (1 << dep)) != 0);

    if(nod->sons[!bit])return (1 << dep) + find_max(x, dep - 1, nod->sons[!bit]);
    return find_max(x, dep - 1, nod->sons[bit]);
}

int main()
{
    cin >> n;

    FOR(i, 1, n - 1)
    {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        add(s[i]);
    }

    int b;
    FOR(i, 0, n - 1)
        if(max(i, find_max(i)) == n - 1)
            b = i;

    cout << b << ' ';
    FOR(i, 1, n - 1)
        cout << (b ^ s[i]) << ' ';
    return 0;
}
