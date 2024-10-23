#include <fstream>
#include <map>
using namespace std;
ifstream cin("toorcmmdc.in");
ofstream cout("toorcmmdc.out");
using pi = pair<int,int>;
const int N = 1e5 + 9;
int n,x;
char c;
map<int,pi> mp;

int gcd(int a,int b)
{
    if(a == 0)return b;
    if(b == 0)return a;

    while(a)
    {
        int aux = a;
        a = b%a;
        b = aux;
    }
    return b;
}

int tree[4*N];

void update(int nod,int st,int dr,int poz,int val)
{
    if(st == dr)
    {
        tree[nod] = val;
        return;
    }
    int mij = (st + dr)>>1;
    if(poz <= mij)
        update(nod<<1,st,mij,poz,val);
    else
        update(nod<<1|1,mij+1,dr,poz,val);

    tree[nod] = gcd(tree[nod<<1],tree[nod<<1|1]);
}
int main()
{
    cin>>n;

    for(int i = 1; i <= n;++i)
    {
        cin>>c>>x;
        if(c == '+')
        {
            if(mp[x].first == 0)
            {
                mp[x].second = i;
                update(1,1,n,i,x);
            }
            mp[x].first ++;
        }
        else
        {
            if(mp[x].first != 0)
            {
                mp[x].first --;
                if(mp[x].first == 0)
                    update(1,1,n,mp[x].second,0);
            }
        }

        if(tree[1] == 0)cout<<1<<'\n';
        else cout<<tree[1]<<'\n';
    }
    return 0;
}
