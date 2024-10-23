#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
ifstream cin("partitiimultime2.in");
ofstream cout("partitiimultime2.out");
short int n,b[20],vmax[20];
char str[24]="";
FILE *pfile;
vector<short int>v[11];
void afisare()
{
    short int l;
    str[0]=0;
    bool ok=0;
    for(short int i=0;i<12;++i)
    {
        ok=0;
        for(short int j=0;j<v[i].size();++j)
        {
            if(v[i][j]>9)
            {
                l=strlen(str);
                str[l]=v[i][j]/10+'0';
                str[l+1]=v[i][j]%10+'0';
                //str[l+2]=0;
            }
            else
            {
                l=strlen(str);
                str[l]=v[i][j]+'0';
                //str[l+1]=0;
            }
            ok=1;
        }
        if(ok==1)l=strlen(str),str[l]='*',str[l+1]=0;
    }
    l=strlen(str);
    str[l]='\n';
    str[l+1]=0;
    cout<<str;
}
void backtracking(short int x)
{
    if(x==n+1)
    {
    short int l;
    str[0]=0;
    bool ok=0;
    for(short int i=0;i<11;++i)
    {
        if(v[i].size()==0)break;
        else
        {
        ok=0;
        for(short int j=0;j<v[i].size();++j)
        {
            if(v[i][j]>9)
            {
                l=strlen(str);
                str[l]=v[i][j]/10+'0';
                str[l+1]=v[i][j]%10+'0';
                str[l+2]=0;
            }
            else
            {
                l=strlen(str);
                str[l]=v[i][j]+'0';
                str[l+1]=0;
            }
            ok=1;
        }
        if(ok==1)l=strlen(str),str[l]='*',str[l+1]=0;
        }
    }
    l=strlen(str);
    str[l]='\n';
    str[l+1]=0;
    cout<<str;
    }
    else
    {
    vmax[x+1]=vmax[x];
    for(short int i=0;i<vmax[x];++i)
    {
        v[i].push_back(x);
        backtracking(x+1);
        v[i].pop_back();
    }
    vmax[x+1]=vmax[x]+1;
    v[vmax[x+1]-1].push_back(x);
    backtracking(x+1);
    v[vmax[x+1]-1].pop_back();
    }
}
int main()
{
    cin>>n;
    backtracking(1);
    return 0;
}
