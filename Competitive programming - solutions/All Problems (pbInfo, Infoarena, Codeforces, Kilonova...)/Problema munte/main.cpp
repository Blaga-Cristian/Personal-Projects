#include <fstream>
/**
    Det lungimii lmax al celui mai lung subsir crescatoor intr-un sire de lungime n

    Prob: det lungiimea Lmax, in intervalul [1...n];
    Subprob: det lungimea Lmax, in intervalul [1..i] care SE TERMINA cu a[i]
    Caz de baza: L[1]=1;

    Rel de recurenta: L[i] = max(L[j]) + 1;
                            1 <= j < i
                             a[j] < a[i]

*/
using namespace std;

const int Mod = 900001, N = 1000;
char  a[N];
int n,Lmax;
int L[N]; ///Lungimea maxima al celui mai lug subsir crescator care e termina cu a[i]
int R[N]; /// R[i] = cel mai lung cs care incepe cu a[i]
///Complexitate O(n*n)
int CmlscL();
int CmlscR();
void CitesteSir();
int main()
{
    CitesteSir();
    ofstream fout("cmlsc.out");
    fout<< CmlscL();
    return 0;
}

int CmlscL()
{
    L[1]=1;
    for(int i=2;i<=n;++i)
    {
        L[i]=1;
        for(int j=1;j<i;++j)
            if(a[j]<=a[i] && L[j]+1 > L[i])
                L[i] = L[j] + 1;
        Lmax  =  max(Lmax,L[i]);
    }

    return Lmax;
}

int CmlscR()///O(n*n)
{
    R[1]=1;
    for(int i=n;i>=1;--i)
    {
        R[i]=1;
        for(int j=i+1;j<=n;++j)
            if(a[i]>=a[j] && R[j]+1 > R[i])
                R[i] = R[j] + 1;
        Lmax  =  max(Lmax,R[i]);
    }

    return Lmax;
}

void CitesteSir()
{
    ifstream fin("cmlsc.in");
    fin>>n;
    for(int i=1;i<=n;++i)
        fin>>a[i];
}
