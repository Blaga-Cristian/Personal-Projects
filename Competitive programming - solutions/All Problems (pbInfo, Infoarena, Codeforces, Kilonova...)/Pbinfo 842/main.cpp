#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> a;
void dinti(int n,int i,int len)
{
    if(n>0)
    {
        a[i+len/2]=n;
        int o=len/2;
        dinti(n-1,i,o);
        dinti(n-1,i+o+1,o);
    }
}
int main()
{
    int n,nr,i;
    cin>>n;
    nr=pow(2,n);
    int b=0;
    for(i=0;i<nr;i++)a.push_back(b);
    dinti(n,0,nr-1);
    for(i=0;i<nr-1;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
