#include <fstream>

using namespace std;
ifstream cin("pixeli.in");
ofstream cout("pixeli.out");
int n,m,op;
char s[40];
struct nod
{
    bool c;
    int sons;
    int has_1;
    nod* son[4];
};
nod* T = new nod;
void add(nod*& x, char* chr)
{
    if(*chr == '\0')
    {
        x->c = !x->c;
        x->has_1 += ((x->c)==1);
        return;
    }

    if(x->son[*chr-'1'] == 0)
    {
        x->sons++;
        x->son[*chr-'1'] = new nod;
    }

    add(x->son[*chr-'1'],chr+1);

    int cnt = 0;
    for(int i = 0; i < 4; ++i)
        if(x->son[i]!=0)
            cnt += x->son[i]->has_1;
    x->has_1 = cnt + x->c;
}
int cnt(nod* x,char* chr,int& k)
{
    if(*chr == '\0')
        return k = (x->c == 0);

    if(x->son[*chr-'1'] == 0)
        return k = 0;

    if(x->has_1)
        return k;

    return k = k*2;
}
int main()
{
    cin>>n>>m;
    int p = 0;
    while(m--)
    {
        cin>>op>>s;
        if(op==1)
            add(T,s);
        else
        {
            p = 0;
            //cout<<cnt(T,s,p)<<'\n';
        }
    }
    return 0;
}
