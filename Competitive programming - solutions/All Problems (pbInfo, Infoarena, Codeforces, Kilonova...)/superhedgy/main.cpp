#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("superhedgy.in");
ofstream cout("superhedgy.out");
using ll = long long;
const int nmax = 1000002;
struct cladire
{
    int L,H,E;
    cladire() {L=0,H=0,E=0;}
};
cladire sup[nmax+5],sub[nmax+5];
int main()
{
    int N,M,nr=1,curr=0,ind=1;
    ll lmax=0;
    cin>>N;
    sup[0].L = sup[0].H = sup[0].L =0;
    for(int i=1;i<=N;++i)
    {
        cin>>sup[i].L>>sup[i].H>>sup[i].E;
        lmax+=sup[i].L;
    }
    cin>>M;
    sub[0].L = sub[0].H = sub[0].L =0;
    for(int i=1;i<=M;++i)
    {
        cin>>sub[i].L>>sub[i].H>>sub[i].E;
    }
    int i=0,j=0;
    ll solsup=0,solsub=0;
    while(i<=N&&j<=M)
    {
        int lg = min(sup[i].L,sub[j].L);
        solsup +=lg;
        sup[i].L-=lg;
        solsub +=lg;
        sub[j].L-=lg;
        ll elevator = sup[i].E + sub[j].E;
        ll vertsup = sup[i].L ? 0 : abs(sup[i].H- sup[i+1].H);
        ll vertsub = sub[j].L ? 0 : abs(sub[j].H-sub[j+1].H);
        ll auxsup = solsup;
        ll auxsub = solsub;
        solsup = min(auxsup + vertsup, auxsub + elevator + vertsup);
        solsub = min(auxsub + vertsub, auxsup + elevator + vertsub);
        i += (sup[i].L==0);
        j += (sub[j].L==0);
    }
    cout<<min(solsub,solsup);
    return 0;
}
