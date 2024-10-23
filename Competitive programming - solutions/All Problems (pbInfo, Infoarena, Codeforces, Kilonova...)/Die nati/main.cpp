#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("aiacupalindroame.in");
ofstream cout("aiacupalindroame.out");
const int N = 100009;
using pi = pair<int,char>;
int n,q,t[N],a,b;
char c[N],aux;
vector<vector<pi>> G;
bool v[N];

struct trie
{
    trie* son[26];
    trie()
    {
        memset(son,0,sizeof(son));
    }
};
trie* T = new trie;
trie* lst[N];

void Dfs(int x)
{
    v[x] = true;
    for(auto i : G[x])
    {
        int y = i.first;
        char chr = i.second;

        if(v[y])continue;

        if(lst[x]->son[chr-'a'] == 0)
            lst[x]->son[chr-'a'] = new trie;

        lst[y] = lst[x]->son[chr-'a'];

        Dfs(y);
    }
}

int main()
{
    cin>>n>>q;
    G = vector<vector<pi>>(n+1);
    for(int i = 2; i <= n ;++i)
        cin>>t[i];
    for(int i = 2; i <= n; ++i)
        cin>>c[i];

    for(int i = 2; i <= n; ++i)
        G[t[i]].push_back({i,c[i]});

    lst[1] = T;
    Dfs(1);

    while(q--)
    {
        cin>>a>>b;
        cout<<(lst[a] == lst[b])<<'\n';
    }
    return 0;
}
