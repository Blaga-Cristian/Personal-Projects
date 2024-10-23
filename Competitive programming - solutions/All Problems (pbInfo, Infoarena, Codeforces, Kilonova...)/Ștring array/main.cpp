#include <iostream>
#include <cstring>
using namespace std;
int NMAX=100000;
char arr[200][200];
char s[200],t[200];
int p[200];
void f(int a,int b)
{
    return t[a]<t[b];
}
int main()
{
    int n=1;
    cin>>s;
    int l=strlen(s);
    strcpy(t,s);
    for(int i=0;i<=strlen(s);++i)
    {
        p[i]=i;
        arr[i][0]=s[i];
        t[i]=s[i];
    }
    sort(t,t+strlen(t));
    sort(p,p+strlen(t),f);
    return 0;
}
