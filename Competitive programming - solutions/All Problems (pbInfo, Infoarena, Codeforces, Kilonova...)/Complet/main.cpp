#include <fstream>

using namespace std;
ifstream cin("complet.in");
ofstream cout("complet.out");

int n,m,op,k;
int tree[4*(100000+9)];
int main()
{
    cin>>n;
    for(int i = 1;i <= n; ++i)
        cin>>tree[i];
    cin>>m;
    while(m--)
    {
        cin>>op;
        if(op == 1)
        {
            cin>>k;
            cout<<tree[k/2]<<'\n';
        }
        else
        {
            cin>>k;
            if(k == 1)
                cout<<0<<'\n';
            else
                cout<<tree[2*k] + tree[2*k + 1]<<'\n';
        }
    }
    return 0;
}
