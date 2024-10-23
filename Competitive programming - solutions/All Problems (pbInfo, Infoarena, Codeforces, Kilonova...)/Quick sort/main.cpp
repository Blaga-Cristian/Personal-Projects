#include <iostream>

using namespace std;
int v[100001];
int n;
int partitie(int low, int high)
{
    int pivot=v[low],ind=low,i;
    for(i=low+1;i<=high;i++)
    {
        if(v[i]<pivot)
        {
            v[ind]=v[i];
            v[i]=v[ind+1];
            v[ind+1]=pivot;
            ind++;
        }
    }
    return ind;
}
void quicksort(int low,int high)
{
    if(low<high)
    {
        int pi=partitie(low,high);
        quicksort(low,pi-1);
        quicksort(pi+1,high);
    }
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)cin>>v[i];
    quicksort(0,n-1);
    for(i=0;i<n;i++)cout<<v[i]<<" ";
    return 0;
}
