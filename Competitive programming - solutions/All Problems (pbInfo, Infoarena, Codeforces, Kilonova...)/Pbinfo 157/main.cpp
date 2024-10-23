#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("doarvocale.in");
ofstream fout("doarvocale.out");
int main()
{
    char s[255];
    int n,i,ok=1,nr=0,j;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>s;
        for(j=0;j<strlen(s);j++)
        {
            if(strchr("aeiou",s[j])==NULL)ok=0;
        }
        nr=nr+ok;
        ok=1;
    }
    fout<<nr;
    return 0;
}
