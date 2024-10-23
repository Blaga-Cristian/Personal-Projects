#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("trie.in");
ofstream cout("trie.out");

int op,x,y,n,m;
char w[23];
struct node
{
    int cnt,sons;
    node *son[26];
    node()
    {
        cnt = sons = 0;
        memset(son,0,sizeof(son));
    }
};
node *R = new node;
void add(node*& x,char* s)
{
    if(*s == '\0')
    {
        x->cnt++;
        return;
    }

    if(x->son[*s-'a'] == 0)
    {
        x->son[*s-'a'] = new node;
        x->sons ++;
    }

    add(x->son[*s-'a'],s+1);
}
bool rem(node*& x,char* s)
{
    if(*s == '\0')
        x->cnt--;
    else if(rem(x->son[*s-'a'],s+1))
    {
        x->son[*s-'a'] = 0;
        x->sons--;
    }

    if(x->cnt == 0 && x->sons == 0 && x != R)
    {
        delete x;
        return true;
    }

    return false;
}
int cnt(node*& x,char* s)
{
    if(*s == '\0')
        return x->cnt;

    if(x->son[*s-'a'])
        return cnt(x->son[*s-'a'],s+1);
    return 0;
}
int pref(node*& x,char* s,int k)
{
    if(*s == '\0' || x->son[*s-'a'] == 0)
        return k;

    return pref(x->son[*s-'a'],s+1,k+1);
}
int main()
{
    while(cin>>op>>w)
    {
        if(op==0)
            add(R,w);
        else if(op == 1)
            rem(R,w);
        else if(op == 2)
            cout<<cnt(R,w)<<'\n';
        else
            cout<<pref(R,w,0)<<'\n';
    }
    return 0;
}
