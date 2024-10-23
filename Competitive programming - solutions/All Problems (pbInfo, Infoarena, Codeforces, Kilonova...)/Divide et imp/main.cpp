#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream cin("matrice_div_et_imp.in");
ofstream cout("matrice_div_et_imp.out");
vector<vector<int> >v;
void parcurgere(int i,int j,int l)
{
    if(l==1)cout<<v[i][j]<<" ";
    else
    {
        parcurgere(i,j,l/2);
        parcurgere(i+l/2,j+l/2,l/2);
        parcurgere(i,j+l/2,l/2);
        parcurgere(i+l/2,j,l/2);
    }
}
int main()
{
    int p,b,n;
    cin>>n;
    p=pow(2,n);
    vector<int> a;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            cin>>b;
            a.push_back(b);
        }
        v.push_back(a);
        a.clear();
    }
    parcurgere(0,0,p);
    return 0;
}
