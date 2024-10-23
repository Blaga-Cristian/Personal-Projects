#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,v[11],b[11],k,pos1,pos2,maxi=-2147483647,mini=2147483647;
bool p[11];
void afisare()
{
    int pp=0;
    for(int i=0;i<n+2;i++)
    {
        if(i==pos1)cout<<maxi<<" ";
        else if(i==pos2)cout<<mini<<" ";
        else cout<<v[b[pp++]]<<" ";
    }
    cout<<endl;
}
void backtracking(int x)
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==n-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>maxi)
        {
            maxi=v[i];
            pos1=i;
        }
        if(v[i]<mini)
        {
            mini=v[i];
            pos2=i;
        }
    }
    v[pos1]=2147483647;
    v[pos2]=2147483647;
    sort(v,v+n);
    n-=2;
    backtracking(0);
    return 0;
}
