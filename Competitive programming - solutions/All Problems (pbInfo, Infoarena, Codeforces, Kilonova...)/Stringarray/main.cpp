#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int NMAX=100000;
char arr[200][200];
char s[200],t[200];
int p[200];
int main()
{
    cin>>s;
    int l=strlen(s);
    for(int i=0;i<=strlen(s);++i)
    {
        p[i]=i;
        arr[i][0]=s[i];
    }
    bool ok=0;
    while(ok==0)
    {
        ok=1;
        for(int i=0;i<l;++i)
        {
            if(arr[i][0]>arr[i+1][0])
            {
                ok=0;
                swap(arr[i][0],arr[i+1][0]);
                swap(p[i],p[i+1]);
            }
        }
    }
    int n=2;
    while(n<=l)
    {
        for(int i=0;i<=strlen(s);++i)
        {
            int nr=n>>1;
            for(int j=p[i]+n>>1;j<n;++j)
            {
                arr[i][nr++]=s[j%(l+1)];
            }
        }
        n<<=1;
    }
    for(int i=0;i<=l;++i)cout<<arr[i]<<'\n';
    return 0;
}
