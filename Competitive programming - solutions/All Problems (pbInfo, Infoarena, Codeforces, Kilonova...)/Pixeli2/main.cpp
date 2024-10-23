#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
ifstream cin("pixeli.in");
ofstream cout("pixeli.out");
using ll = long long;
char s[100];
ll n,m,p2;

struct trie
{
    bool setat;
    ll nrfiset;
    trie* son[4];
    trie()
    {
        setat = nrfiset = 0;
        memset(son,0,sizeof(son));
    }
};
int upd(trie* x,char* s)
{
    if(*s == '\0')
    {
        if(x->setat)
        {
            x->setat = false;
            return -1;
        }
        else
        {
            x->setat = true;
            return 1;
        }
    }

    if(x->son[*s - '1'] == 0)
        x->son[*s - '1'] = new trie;

    int a = upd(x->son[*s-'1'],s+1);
    x->nrfiset += a;
    return a;
}
ll query(trie* x,char *s)
{
    if(*s == '\0')
    {
        if(x->setat)
            return 0;
        return 1;
    }

    if(x->son[*s-'1'] == 0)
        x->son[*s-'1'] = new trie;

    ll a = query(x->son[*s-'1'],s+1);

    if(x->nrfiset == 0)
        return 4*a;
    return a;
}

trie* T = new trie;
void solve()
{
    while(m--)
    {
        cin.get(s,100);
        cin.get();

        if(s[0] == '1')
            upd(T,s+2);
        else
            cout<<query(T,s+2)<<'\n';
    }
}

int main()
{
    cin>>n>>m;
    cin.get();
    p2 = log2(n);
    p2 += 2;

    solve();
    return 0;
}
