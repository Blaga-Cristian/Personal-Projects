#include <iostream>
#include <cstring>
using namespace std;
const int N = 3*1e5 + 9,Mod = 1000000007;
int n,m,k,x,sum,sol;
char s[N];
int ff[N],d[N],e[N];

struct trie
{
    int t,len;
    trie* son[26];
    trie()
    {
        t = len = 0;
        memset(son,0,sizeof(son));
    }
};
trie* T = new trie;

void add(trie* x, char* s)
{
    if(*s == 0)
    {
        x->t = 1;
        return;
    }

    if(x->son[*s-'a'] == 0)
    {
        x->son[*s-'a'] = new trie;
        x->son[*s-'a']->len = 1 + x->len;
    }

    add(x->son[*s-'a'],s+1);
}

void dfs(trie* x)
{
    if(x->t)
    {
        d[x->len] ++;
        return;
    }

    e[x->len] ++;

    for(int i = 0; i < 26; ++i)
        if(x->son[i] != 0)
            dfs(x->son[i]);
}


int main()
{
    cin>>n>>m>>k;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s,N);
        cin.get();
        add(T,s);
    }

    dfs(T);

    for(int i = 1; i <= m; ++i)
    {
        cin>>x;
        ff[x] ++;
    }

    sum = sol = 1;
    for(int i = 1; i <= 3 * 1e5; ++i)
    {
        sum = 1LL * sum * k % Mod;
        sum = (sum - d[i] + Mod) % Mod;
        for(int k = 1; k <= ff[i]; ++k)
        {
            sol = (1LL * sol * (sum - e[i] + Mod)) % Mod;
            sum = (sum - 1 + Mod) % Mod;
        }
    }
    cout<<sol;
    return 0;
}
