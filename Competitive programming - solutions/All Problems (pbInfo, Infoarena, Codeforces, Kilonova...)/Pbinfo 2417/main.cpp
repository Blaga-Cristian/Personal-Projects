#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("criptare1.in");
ofstream cout("criptare1.out");
char g[101]="";
int main()
{
    char s[1001],k[21],v[21],ok=0,i,j;
    cin>>s>>k;
    strcpy(v,k);
    while(ok==0)
    {
        ok=1;
        for(i=0;i<strlen(v)-1;i++)
        {
            if(v[i]>v[i+1])
            {
                char aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ok=0;
            }
        }
    }
    for(i=0;i<strlen(v);i++)
    {
        for(j=0;j<strlen(k);j++)
        {
            if(v[i]==k[j])
            {
                k[j]=i+'1';
                break;
            }
        }
    }
    int nr=strlen(s)/strlen(k);
    strcpy(g,k);
    for(i=1;i<=nr;i++)
    {
        for(j=0;j<strlen(k);j++)
        {
            g[k[j]-1]=s[(i-1)*strlen(k)+j];
        }
        cout<<g<<endl;
    }
    return 0;
}
