#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256],v[255]="";
    int max=-3,i,j,k,nr;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("aeiou",s[i])==0)
        {
            j=i;
            while(strchr("aeiou",s[j])==0)
            {
                j++;
            }
            if(j-i>=max)
            {
                nr=0;
                max=j-i;
                for(k=i;k<j;k++)
                {
                    v[nr]=s[k];
                    nr++;
                }
                v[nr]=0;
            }
        }
    }
    cout<<v;
    return 0;
}
