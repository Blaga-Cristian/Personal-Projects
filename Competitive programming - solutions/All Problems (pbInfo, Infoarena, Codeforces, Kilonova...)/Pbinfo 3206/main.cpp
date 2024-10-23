#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
long long s=0;
void Combina(int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j,k=p;
    int L[n1],M[n2];
    for(i=0;i<n1;i++)L[i]=v[p+i];
    for(i=0;i<n2;i++)M[i]=v[q+1+i];
    i=0;
    j=0;
    while(i<n1&&j<n2)
    {
        if(L[i]<=M[j])
        {
            v[k]=L[i];
            s=s+k-i-p;
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
        s=s+k-i-p;
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
void MergeSort(int st, int dr)
{
    if(st<dr)
    {
        int m=(st+dr)/2;
        MergeSort(st,m);
        MergeSort(m+1,dr);
        Combina(st,m,dr);
    }
}
int main()
{
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    MergeSort(0,n-1);
    cout<<s;
    return 0;
}
