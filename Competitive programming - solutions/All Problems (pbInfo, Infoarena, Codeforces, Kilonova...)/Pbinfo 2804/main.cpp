#include <iostream>
#include <cstring>
using namespace std;
char s[1000001];
int main()
{
    int x[1001],n,i,j;
    cin.get(s,1000);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        if(x[i]%2==0)strncat(s,s,x[i]);
        else
        {
            char t[1001]="";
            int nr=0;
            for(j=x[i]-1;j>=0;j--)
            {
                t[nr]=s[j];
                nr++;
            }
            strcat(s,t);
        }
    }
    cout<<s;
    return 0;
}
