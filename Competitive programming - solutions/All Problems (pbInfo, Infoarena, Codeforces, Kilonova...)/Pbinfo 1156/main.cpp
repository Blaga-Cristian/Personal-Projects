#include <iostream>

using namespace std;
int v[1001];
int v1[1001];
int pivot(int st,int dr)
{
    int pi=v[st];
    int ind=st,i;
    for(i=st+1;i<=dr;i++)
    {
        if(v[i]<pi)
        {
            v[ind]=v[i];
            v[i]=v[ind+1];
            v[ind+1]=pi;
            int alt=v1[ind];
            v1[ind]=v1[i];
            v1[i]=v1[ind+1];
            v1[ind+1]=alt;
            ind++;
        }
    }
    return ind;
}
void Quicksort(int st,int dr)
{
    if(st<dr)
    {
        int pi=pivot(st,dr);
        Quicksort(st,pi-1);
        Quicksort(pi+1,dr);
    }
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        v1[i]=i;
    }
    Quicksort(0,n-1);
    for(i=0;i<n;i++)cout<<v1[i]+1<<" ";
    cout<<endl;
    return 0;
}
