#include <iostream>
#include <queue>
using namespace std;
const int di[]={-1,0,0,1},dj[]={0,-1,1,0};
int n,m,A[101][101];
void Lee(int istart ,int jstart)
{
    queue<pair<int,int> > Q;
    //initializare coada
    Q.push(make_pair(istart , jstart));
    //marcare pozitie de start
    A[istart][jstart] = 1;
    while(! Q.empty()) // cat timp coada este nevida
    {
        int i = Q.front().first, j = Q.front().second; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element în matrice
                && A[iv][jv] == 0) // element liber si nemarcat
            {
                // marcam elementul vecin cu o valoare mai mare
                A[iv][jv] = A[i][j] + 1;
                // il adaugam in coada
                Q.push(make_pair(iv , jv));
            }
        }
        Q.pop(); // eliminam din coada
    }
}
void Traseu1(int i, int j , int lg)
{
    if(A[i][j] == 6)
    {
        cout << lg << "\n";
        cout << i << " " << j << "\n";
    }
    else
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+di[k]][j+dj[k]] + 1)
                p = k;
        Traseu1(i + di[p] , j + dj[p] , lg + 1);
        cout << i << " " << j << "\n";
    }
}
int main()
{
    int i,j,istart,jstart;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>A[i][j];
    cin>>istart>>jstart;
    Lee(istart,jstart);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    Traseu1(1,5,1);
    return 0;
}
