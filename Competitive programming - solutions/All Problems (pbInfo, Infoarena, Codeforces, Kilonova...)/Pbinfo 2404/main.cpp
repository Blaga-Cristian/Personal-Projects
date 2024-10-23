#include <fstream>

using namespace std;
ifstream cin("test.in");
ofstream cout("test.out");
const int N=6669666;
unsigned long long putere(unsigned int a,unsigned int b)
{
    if(b==0)return 1;
    else
    {
        unsigned long long x=putere(a,b/2);
        if(b%2==0)return x*x%N;
        return x*x%N*a%N;
    }
}
int main()
{
    int n,i,j;
    unsigned long long s=0;
    unsigned long long a[1001],b[1001];
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    for(i=0;i<n;i++)s=s+putere(a[i],b[i]);
    cout<<s;
    return 0;
}
