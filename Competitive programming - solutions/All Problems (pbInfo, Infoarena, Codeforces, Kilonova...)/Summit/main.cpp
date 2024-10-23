#include <fstream>
#include <vector>
using namespace std;
ifstream cin("summit.in");
ofstream cout("summit.out");
long long int s[1000001];
int st,dr;
int cb(int x,int i)
{
    if(st<=dr)
    {
        int mij=(st+dr)/2;
        if(s[mij]==x)return mij;
        else if(x<s[mij])
        {
            dr=mij-1;
            return cb(x,i);
        }
        else
        {
            st=mij+1;
            return cb(x,i);
        }
    }
    return 0;
}
int main()
{
    int n,i;
    cin>>n;
    int x;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        s[i]=s[i-1]+x;
        st=0;
        dr=i;
        int val=cb(x,i);
        if(s[val]==x)cout<<val<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}
