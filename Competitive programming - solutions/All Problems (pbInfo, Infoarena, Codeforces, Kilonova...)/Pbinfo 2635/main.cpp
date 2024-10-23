#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
ifstream fin("capslock.in");
ofstream fout("capslock.out");

int main()
{
    char s[256],*p,t[500]="";
    int i,nr=0;
    fin.get(s,255);
    for(i=0;i<=strlen(s);i++)
    {
        if(s[i]=='#')
        {
            nr++;
            if(nr<35)
            {
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            while(s[i]>='a'&&s[i]<='z')
            {
                s[i]=s[i]-'a'+'A';
                i++;
            }
            }
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            i--;
            nr++;
        }
    }
    fout<<s;
    return 0;
}
