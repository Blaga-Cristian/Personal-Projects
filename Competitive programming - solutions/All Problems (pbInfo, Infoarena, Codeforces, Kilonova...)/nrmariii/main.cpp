#include <iostream>

using namespace std;
typedef int NrMare[1010];
void inmultire(NrMare nr,int x)
{
    int t=0;
    for(int i=1;i<=nr[0];++i,t/=10)
    {
        nr[i]=(t+=nr[i]*x)%10;
    }
    while(t!=0)
    {
        nr[++nr[0]]=t%10;
        t/=10;
    }
}
void afisare(NrMare nr)
{
    for(int i=nr[0];i>=1;--i)cout<<nr[i];
}
int main()
{
    int n;
    NrMare nr;
    nr[0]=1;
    nr[1]=1;
    cin>>n;
    for(int i=3;i<n;++i)inmultire(nr,i);
    afisare(nr);
    return 0;
}
