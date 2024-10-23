#include <fstream>
#include <vector>
using namespace std;
ifstream cin("nano.in");
ofstream cout("nano.out");
int st,dr;
char s[51][510];
int comparare(char a[],char b[])
{
    int i,ok=1;
    if(a[0]>b[0])return 1;
    else if(a[0]<b[0])return 2;
    else if(a[0]==b[0])
    {
        for(i=1;i<=a[0];i++)
        {
            if(a[i]>b[i])
            {
                ok=1;
                break;
            }
            else if(a[i]<b[i])
            {
                ok=2;
                break;
            }
        }
    }
    return ok;
}
int main()
{
    int n,i,x,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        s[i][0]=x;
        for(j=1;j<=x;j++)cin>>s[i][j];
    }
    for(i=1;i<n;i++)
    {
        cout<<comparare(s[i-1],s[i])<<endl;
    }
    return 0;
}
