#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[40][255],*p,c[255],t[255]="",c1[255]="";
    int n,i,j,cnt=0,max=-99,ind=-3,min=999;
    cin>>n;
    cin.get();
    for(i=0;i<n;i++)
    {
        cin.get(s[i],255);
        cin.get();
        for(j=0;j<strlen(s[i]);j++)
        {
            if(strchr("aeiou",s[i][j])!=NULL)cnt++;
        }
        if(cnt<=min)
        {
            min=cnt;
            ind=i;
        }
        cnt=0;
    }
    cout<<s[ind];
    return 0;
}
