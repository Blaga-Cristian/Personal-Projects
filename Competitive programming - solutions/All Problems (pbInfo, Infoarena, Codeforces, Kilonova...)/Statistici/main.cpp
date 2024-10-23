#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
ifstream cin("statisticiordine.in");
ofstream cout("statisticiordine.out");
unsigned int v[4000001];
int k,n,ok=0;
int partitie(int st,int dr)
{
    swap(v[dr],v[st]);
    int pi=v[st],i,ind=st;
    for(i=st+1;i<=dr;i++)
    {
        if(v[i]<pi)
        {
            v[ind]=v[i];
            v[i]=v[ind+1];
            v[ind+1]=pi;
            ind++;
        }
    }
    return ind;
}
int partitie_r(int st,int dr)
{
    int random=st+rand()%(dr-st+1);
    if(random!=dr)swap(v[random],v[dr]);
    return partitie(st,dr);
}
void Quickselect(int st,int dr)
{
    if(st<dr)
    {
        int pi=partitie_r(st,dr);
        if(pi==k-1)
        {
            cout<<v[pi];
            ok=1;
        }
        else if(pi>k-1)Quickselect(st,pi-1);
        else if(pi<k-1)Quickselect(pi+1,dr);
    }
}
int main()
{
    unsigned int a;
    srand(time(NULL));
    int i;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>v[i];
    Quickselect(0,n-1);
    if(ok==0)cout<<v[k-1];
    return 0;
}
