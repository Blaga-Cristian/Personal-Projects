#include <iostream>
#include <vector>
using namespace std;
int NrMinMaxAp(vector<int> &a)
{
    int v[50000],b[50000],i,maxi=-99999999999,mini=999999999999,maxap=0,nr;
    for(i=0;i<50000;i++)
    {
        v[i]=0;
        b[i]=0;
    }
    for(i=0;i<a.size();i++)
    {
        if(a[i]>maxi)maxi=a[i];
        if(a[i]<mini)mini=a[i];
        if(a[i]>=0)v[a[i]]++;
        else b[a[i]*(-1)]++;
    }
    for(i=0;i<=maxi;i++)
    {
        if(v[i]>maxap)
        {
            maxap=v[i];
            nr=i;
        }
    }
    for(i=0;i<=(mini*(-1));i++)
    {
        if(b[i]>maxap)
        {
            maxap=b[i];
            nr=-i;
        }
    }
    return nr;
}
int main()
{
    vector<int>v;
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<NrMinMaxAp(v);
    return 0;
}
