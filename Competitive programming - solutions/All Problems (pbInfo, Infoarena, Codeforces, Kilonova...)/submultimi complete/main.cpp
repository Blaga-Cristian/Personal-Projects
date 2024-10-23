#include <fstream>

using namespace std;
ifstream cin("submultimi.in");
ofstream cout("submultimi.out");
int b[20],n;
bool p[20];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i]<<" ";
    cout<<'\n';
}
void backtracking(int x,int ist,int xmax)
{
    for(int i=ist;i<n;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i+1;
            if(x==xmax)
            {
                afisare(xmax);
                backtracking(x+1,i+1,xmax+1);
            }
            else backtracking(x+1,i+1,xmax);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    backtracking(0,0,0);
    return 0;
}
