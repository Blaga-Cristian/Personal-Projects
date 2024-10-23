#include <fstream>

using namespace std;
ifstream cin("sumaxl.in");
ofstream cout("sumaxl.out");
typedef int NrMare[1010];
NrMare n;
void Suma(NrMare n,int a)
{
    while(n[n[0]]==0&&n[0]>1)n[0]--;
    int i=1,t=0;
    while(a!=0||t!=0)
    {
        t=t+n[i]+a%10;
        n[i]=t%10;
        t=t/10;
        a=a/10;
        i++;
    }
    if(i-1>n[0])n[0]=i-1;
}
int main()
{
    int i,a;
    cin>>n[0];
    for(i=n[0];i>=1;i--)cin>>n[i];
    cin>>a;
    Suma(n,a);
    for(i=n[0];i>=1;i--)cout<<n[i];
    return 0;
}
