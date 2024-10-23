#include <fstream>
#include <cstring>
#include <unordered_map>
using namespace std;
ifstream cin("sub.in");
ofstream cout("sub.out");

int Na,Nb;
long long cnt;
char s[304];
struct node
{
    int cnt;
    node* son[26];
    node ()
    {
        cnt = 0;
        memset(son,0,sizeof(son));
    }
};
node* T = new node();
void add(node* nod, char* s,int pos)
{
    if(*s == '\0')
        return;
    if(nod->son[*s-'a'] == 0)
        nod->son[*s-'a'] = new node();
    if(nod->son[*s-'a']->cnt >= pos - 1)
    {
        nod->son[*s-'a']->cnt = pos;
        add(nod->son[*s-'a'],s+1,pos);
    }
}
void del(node* nod, char* s)
{
    if(*s == '\0')
        return;
    if(nod->son[*s-'a'] != 0)
    {
        nod->son[*s-'a']->cnt = 0;
        del(nod->son[*s-'a'],s+1);
    }
}
void query(node* nod)
{
    if(nod == 0)
        return;
    if(nod->cnt == Na)
        cnt++;
    for(int i = 0; i < 26; ++i)
        if(nod->son[i] != 0)
            query(nod->son[i]);
}
int main()
{
    cin>>Na;
    for(int i = 1; i <= Na; ++i)
    {
        cin>>s;
        for(int j = 0; j < strlen(s);++j)
            add(T,s+j,i);
    }
    cin>>Nb;
    for(int i = 1; i <= Nb;++i)
    {
        cin>>s;
        for(int j = 0; j < strlen(s);++j)
            del(T,s+j);
    }
    query(T);
    cout<<cnt;
    return 0;
}
