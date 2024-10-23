#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p,c[255],t[255]="",c1[255]="";
    int n,i,j,cnt=0,max=-99,ind=-3,min=999;
    cin.get(s,255);
    cin.get();
    cin.get(c,255);
    for(i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i])&&((s[i-1]==" ")||i==0))
        {
            j=i;
            while(s[j]!=" "&&j<strlen(s))j++;
            strcpy(s+j+1,s+j);
            s[j]='?';
            i=j;
        }
    }
    cout<<s;
    return 0;
}
