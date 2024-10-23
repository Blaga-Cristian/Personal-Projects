#include <fstream>

using namespace std;
ifstream cin("permpf.in");
ofstream cout("permpf.out");
bool p[20];
int b[20];
int n;
void afisare()
{
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;
}
void backtracking(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(i==2||i==3||i==5||i==7||i==11||i==13)
        {
            if(x==n)afisare();
            else backtracking(x+1);
            break;
        }
        else if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==n)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;

    backtracking(1);
    return 0;
}
