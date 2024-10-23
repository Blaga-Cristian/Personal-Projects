#include <fstream>

using namespace std;
ifstream cin("dineu.in");
ofstream cout("dineu.out");
const int N = 26;
int pers[N],b[N],n,l,nr,x;
int ans[N],ans_sz;
bool ok;
void check(int sz)
{
    if(sz>ans_sz)
    {
    ans_sz = sz;
    for(int i=1;i<=sz;++i)
        ans[i] = b[i];
    }
}
void Back(int ind,int sz)
{
    check(sz);
    for(int i=ind;i<=n;++i)
    {
        ok = 1;
        for(int j=1;j<=sz;++j)
            if((pers[i]&pers[b[j]]) == 0)
                ok = 0;
        if(ok)
        {
            b[sz+1] = i;
            Back(i+1,sz+1);
        }
    }
}
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;++i)
    {
        cin>>nr;
        while(nr--)
        {
            cin>>x;
            pers[i] += (1<<(x-1));
        }
    }
    Back(1,0);
    cout<<ans_sz<<'\n';
    for(int i=1;i<=ans_sz;++i)
        cout<<ans[i]<<' ';
    return 0;
}
