#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> >sir;
int vmax[30];
int n,m;
void afisare()
{
    for(int i=1;i<=n/m+2;++i)
    {
        if(!sir[i].empty())
        {
        cout<<'{';
        for(int j=0;j<m;++j)
        {
            cout<<sir[i][j];
            if(j!=m-1)cout<<',';
        }
        cout<<'}';
        }
        if(i!=n/m)cout<<'U';
    }
    cout<<'\n';
}
void Back(int x)
{
    for(int i=1;i<=vmax[x]+1;++i)
    {
        if(sir[i].size()<m)
        {
            sir[i].push_back(x);
            vmax[x+1] = max(vmax[x],i);
            if(x==n)afisare();
            else Back(x+1);
            sir[i].pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;
    if(n==0||m==0)
    {
        cout<<"IMPOSIBIL";
        return 0;
    }
    if(n%m!=0)
    {
        cout<<"IMPOSIBIL";
        return 0;
    }
    sir = vector<vector<int> >(20);
    Back(1);
    return 0;
}
