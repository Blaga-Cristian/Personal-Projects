#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char cuv[10][10],ans[11],s[250];
int n;
bool p[40],ok;
void afisare()
{
    for(int i=0;i<n;++i)cout<<ans[i];
}
void backt(int x)
{
    for(int i=0;i<strlen(cuv[x]);++i)
    {
        if(p[cuv[x][i]-'a']==0)
        {
            p[cuv[x][i]-'a']=1;
            ans[x]=cuv[x][i];
            if(ok)return;
            if(x==n-1)
            {
                ok=1;
                afisare();
            }
            else backt(x+1);
            p[cuv[x][i]-'a']=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cuv[i];
        int ok=0;
        while(ok==0)
        {
            ok=1;
            for(int j=0;j<strlen(cuv[i])-1;++j)
            {
                if(cuv[i][j]>cuv[i][j+1])
                {
                    ok=0;
                    char aux=cuv[i][j];
                    cuv[i][j]=cuv[i][j+1];
                    cuv[i][j+1]=aux;
                }
            }
        }
    }
    for(int i=0;i<n;++i)cout<<cuv[i]<<'\n';
    backt(0);
    return 0;
}
