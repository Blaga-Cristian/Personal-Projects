#include <iostream>

using namespace std;
int v[200001];
void Combine1(int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j;
    int L[n1],M[n2];
    for(i=0;i<n1;i++)L[i]=v[p+i];
    for(i=0;i<n2;i++)M[i]=v[q+1+i];
    i=0;
    j=0;
    int k=p;
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
void Combine2(int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j;
    int L[n1],M[n2];
    for(i=0;i<n1;i++)L[i]=v[p+i];
    for(i=0;i<n2;i++)M[i]=v[q+1+i];
    i=0;
    j=0;
    int k=p;
    while(i<n1&&j<n2)
    {
        if(L[i]>M[j])
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
void Mergesort(int st,int dr,bool ok)
{
    if(st<dr)
    {
        int pi=(st+dr)/2;
        Mergesort(st,pi,ok);
        Mergesort(pi+1,dr,ok);
        if(ok==0)Combine1(st,pi,dr);
        else Combine2(st,pi,dr);
    }
}
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>v[i];
    Mergesort(0,k-1,0);
    Mergesort(k,n-1,1);
    for(i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
