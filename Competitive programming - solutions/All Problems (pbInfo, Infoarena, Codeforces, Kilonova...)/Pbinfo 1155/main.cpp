#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int x,n,m;
bool cautare(int a,double mid,int b)
{
    if(mid>(int)mid)mid=(int)mid+1;
    if(v[mid]==x)return 1;
    else
    {
        if(v[mid]>x)return cautare(a,(a+mid)/2,mid);
        else return cautare(mid,(b+mid)/2,b);
    }
    return 0;
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        int x;
        cin>>x;
        cout<<cautare(0,(n-1)/2,n-1);
    }
    return 0;
}
