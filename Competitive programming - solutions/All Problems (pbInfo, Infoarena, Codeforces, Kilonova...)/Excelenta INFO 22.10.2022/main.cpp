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

int p[N][N]={0};

int Part (int n,int k)//O(n^2)
{
    //caauride baza
    for(int i=1;i<=n;++i)
        p[i][i]=1;

    for(int i=2;i<=n;++i)
        for(int j=i-1;j>=1;--j)
            p[i][j] =(p[i][j+1] + p[i-j][j]) % Mod;

    return p[n][k];
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<Part(n,k);
    return 0;
}
