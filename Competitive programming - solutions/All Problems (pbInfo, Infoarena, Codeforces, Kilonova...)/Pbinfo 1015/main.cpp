#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int n;
int sumvec(vector<int> &v,int st,int dr)
{
    if(st==dr)return v[st];
    else
    {
        int m=(st+dr)/2;
        int s1=sumvec(v,st,m);
        int s2=sumvec(v,m+1,dr);
        return s1+s2;
    }
}
int main()
{
    cin>>n;
    int a;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<sumvec(v,0,n-1);
    return 0;
}
