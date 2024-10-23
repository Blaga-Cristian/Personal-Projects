#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,b[21];
bool p[21];
void afisare(int len)
{
    for(int i=0;i<len;i++)cout<<b[i]+1<<" ";
    cout<<'\n';
}
void backtracking(int x,int ist,int len)
{
    if(len<=n)
    {
    for(int i=ist;i<n;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==len-1)
            {
                afisare(len);
                backtracking(x+1,i+1,len+2);
            }
            else backtracking(x+1,i+1,len);
            p[i]=0;
        }
    }
    }
}
int main()
{
    cin>>n;
    backtracking(0,0,1);
    return 0;
}
