#include <iostream>
#include <algorithm>
using namespace std;
int s,b[100],ind;
bool p[21];
void afisare(int x)
{
    b[ind++]=x;
}
void backt(int x,int sum,int rez)
{
    int i;
    if(x==1)i=1;
    else i=0;
    for(i;i<=9;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            if(sum-i<0);
            else if(sum-i==0)
            {
                afisare(rez*10+i);
                backt(x+1,0,rez*10+i);
            }
            else backt(x+1,sum-i,rez*10+i);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>s;
    backt(1,s,0);
    sort(b,b+ind);
    for(int i=0;i<ind;++i)cout<<b[i]<<'\n';
    return 0;
}
