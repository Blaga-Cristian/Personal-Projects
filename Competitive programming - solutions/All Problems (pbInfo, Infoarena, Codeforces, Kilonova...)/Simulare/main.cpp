#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("eliminare.in");
ofstream fout("eliminare.out");
char s[1000001];
int main()
{
    int i=0,k;
    fin>>s;
    fin>>k;
    char t[strlen(s)+1];
    for(i=0;i<strlen(s)-1;i++)
    {
        if(k==0)break;
        if(s[i]<s[i+1])
        {
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            k--;
            if(i>=1)i=i-2;
            else i=i-1;
        }
    }
    if(k!=0)strcpy(s+strlen(s)-k,s+strlen(s));
    fout<<s;
    return 0;
}
