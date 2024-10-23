#include <iostream>

using namespace std;
void Combine(int v[],int p,int q,int r)
{
    int L[q-p+2],M[r-q+2],n1,n2,i,j;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)L[i]=v[p+i];
    for(i=0;i<n2;i++)M[i]=v[q+1+i];
    int k=p;
    i=0;
    j=0;
    while(i<n1&&j<n2)
    {
        if(L[i]<M[j])
        {
            v[k]=L[i];
            i++;
        }
        else
        {
            v[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        v[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        v[k]=M[j];
        j++;
        k++;
    }
}
void Mergesort(int v[],int start,int stop)
{
    if(start<stop)
    {
        int q=(start+stop)/2;
        Mergesort(v,start,q);
        Mergesort(v,q+1,stop);
        Combine(v,start,q,stop);
    }
}
int main()
{
    int i,v[100001],n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>v[i];
    Mergesort(v,1,n);
    for(i=1;i<=n;i++)cout<<v[i]<<" ";
    return 0;
}
