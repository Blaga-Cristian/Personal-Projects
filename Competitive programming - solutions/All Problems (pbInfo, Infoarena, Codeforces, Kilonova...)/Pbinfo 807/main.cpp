#include <bits/stdc++.h>
using namespace std;
char s[256] , a[101][101];
int main()
{
    cin.getline(s , 256);
    int i=0,j=0,m=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
        {
            j=0;
            m++;
        }
        else
        {
            a[m][j]=s[i];
            j++;
        }
    }
    for(i=0;i<=m;i++)
    {
        if(strlen(a[i])!=3)cout<<a[i]<<' ';
        else cout<<'*'<<' ';
    }
}
