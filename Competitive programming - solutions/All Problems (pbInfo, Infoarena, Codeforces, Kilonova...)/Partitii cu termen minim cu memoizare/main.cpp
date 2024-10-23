#include <iostream>
/**
    Numarul minim de partiti astfel incat termenu lminim sa fie CEL PUTIN k.

    Prob: Det nr partiti alelui nastfel inccat termenul minim sa fie cel putin k.
    Subprob: Det ne minim part i astfel incat rtermenul minim sa fie cel putin j.
    Starea: (p,i,j)
    Structure de date:
                int p[100][100]; p[i][j]=......
    Cazuri de baza p[i][i]=1 (i in intervalul 1,n)
                    p[i][j] = 0 (j>i);

    Recurenta: p[i][j] = p[i][j+1] + p[i-j][j];
*/
using namespace std;

const int N = 1000,Mod = 900001;

int p[N][N];
int Part (int n,int k)//O(n^2)
{
    int& P = p[n][k];
    if(k>n) return P=0;
    if(k==n) return P = 1;
    if(p[n][k])return P;
    return P = (Part(n,k+1) + Part(n-k,k))%Mod;
}
int main()
{
    int n,k;
    cin>>n>>k;

    cout<<Part(n,k);
    return 0;
}
