#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("trie.in");
ofstream cout("trie.out");

int op;
char w[23];

struct node
{
    int cnt,sons;
    node* son[26];
    node ()
    {
        cnt = sons = 0;
        memset(son,0,sizeof(son));
    }
};
node* T = new node;
void add(node*& nod, char* s)
{
    if(*s == '\0')
    {
        nod->cnt ++;
        return;
    }

    if(nod->son[*s - 'a'] == 0)
    {
        nod->son[*s-'a'] = new node;
        nod->sons++;
    }

    add(nod->son[*s-'a'],s+1);
}
bool del(node* nod, char* s)
{
    if(*s == '\0')
        nod->cnt--;
    else if(del(nod->son[*s-'a'],s+1))
    {
        nod->son[*s-'a'] = 0;
        nod->sons --;
    }

    if(nod->sons == 0 && nod ->cnt == 0 && nod != T)
    {
        delete nod;
        return true;
    }

    return false;
}
int cnt(node* nod,char* s)
{
    if(*s == '\0')
        return nod->cnt;
    else if(nod->son[*s-'a'] == 0)
        return 0;
    return cnt(nod->son[*s-'a'],s+1);
}
int pre(node* nod, char* s,int k)
{
    if(*s == '\0' || nod->son[*s-'a'] == 0)
        return k;
    return pre(nod->son[*s-'a'],s+1,k+1);
}
int main()
{
    while(cin>>op)
    {
        if(op == 0)
        {
            cin>>w;
            add(T,w);
        }
        else if(op == 1)
        {
            cin>>w;
            del(T,&w[0]);
        }
        else if(op == 2)
        {
            cin>>w;
            cout<<cnt(T,&w[0])<<'\n';
        }
        else
        {
            cin>>w;
            cout<<pre(T,&w[0],0)<<'\n';
        }
    }
    return 0;
}
