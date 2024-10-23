#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("15-subsecvente.in");
ofstream cout("subsecvente.out");
const int L = 50009;
char s[5][L];
int n;

struct trie
{
    int s;
    trie* son[2];
    trie()
    {s = 0;
    son[0] = son[1] = 0;}
};
trie* T = new trie;
void add(trie* x,char* sir,int len,int ord)
{
    x->s |= (1<<ord);

    if(len == 0)
        return;

    if(x->son[*sir - 'a'] == 0)
        x->son[*sir - 'a'] = new trie;

    add(x->son[*sir - 'a'],sir+1,len - 1,ord);
}
int query(trie* x)
{
    if(x->s != (1<<n) - 1)
        return 0;
    int a = 0,b = 0;
    if(x->son[0])
        a = query(x->son[0]);
    if(x->son[1])
        b = query(x->son[1]);

    return 1 + max(a,b);
}
int main()
{
    cin>>n;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s[i],L);
        cin.get();
        for(int k = 0; k < strlen(s[i]); ++k)
            add(T,s[i]+k,min(int(strlen(s[i]) - k),60),i-1);
    }

    cout<<query(T)-1;
    return 0;
}
