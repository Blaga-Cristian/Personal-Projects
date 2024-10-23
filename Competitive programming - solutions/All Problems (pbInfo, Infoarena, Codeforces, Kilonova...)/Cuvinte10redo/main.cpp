#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long

using namespace std;
const int N = 3e5 + 9, Mod = 1000000007;

int n, m, k, cnt[N], e[N];
ll dp[N];
char s[N];
VI sir;

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod) x -= Mod;
    if(x < 0) x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}


struct trie
{
    int cnt;
    trie* sons[26];

    trie()
    {
        cnt = 0;
        FOR(i, 0, 25)sons[i] = 0;
    }
};
trie* t = new trie;

void add(char* s, trie* nod = t)
{
    if(s[0] == '\0')
    {
        nod->cnt = 1;
        return;
    }

    if(!nod->sons[s[0] - 'a'])nod->sons[s[0] - 'a'] = new trie();

    add(s + 1, nod->sons[s[0] - 'a']);
}

void Dfs(trie* x, int dep = 0)
{
    if(x->cnt)
    {
        cnt[dep] ++;
        return;
    }

    e[dep] ++;

    FOR(i, 0, k - 1)
        if(x->sons[i])
            Dfs(x->sons[i], dep + 1);
}

int main()
{
    cin >> n >> m >> k;
    cin.get();

    FOR(i, 1, n)
    {
        cin.get(s, N);
        cin.get();
        add(s);
    }

    int x;
    FOR(i, 1, m)
    {
        cin >> x;
        sir.pb(x);
    }
    sort(sir.begin(), sir.end());


    Dfs(t);

    ll ans = 1;
    dp[0] = 1;
    int p = 0;

    FOR(i, 1, N)
    {
        dp[i] = add(mul(dp[i - 1], k), -cnt[i]);

        for(; p < sir.size() && sir[p] == i; ++p)
        {
            ans = mul(ans, add(dp[i], -e[i]));
            dp[i] = add(dp[i], -1);
        }
    }

    cout << ans;
    return 0;
}
