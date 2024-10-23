#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("paritatesiruri.in");
ofstream fout("paritatesiruri.out");

int main()
{
    char p[10000]=" ",s[10000];
    int n,i,j,k=0,nr,l;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>s;
        for(j=0;j<strlen(s);j++)
        {
            if(j%2==1)
            {
                for(l=strlen(p);l>=k;l--)
                {
                    p[l+1]=p[l];
                }
                p[k]=s[j];
                k++;
            }
            else
            {
                nr=strlen(p);
                p[nr+1]=p[nr];
                p[nr]=s[j];
            }
        }
        fout<<p<<endl;
        k=0;
        strcpy(p," ");
    }
    return 0;
}
