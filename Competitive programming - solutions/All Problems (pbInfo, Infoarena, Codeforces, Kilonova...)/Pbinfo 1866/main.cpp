#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("prosir.in");
ofstream fout("prosir.out");
int main()
{
    char s[255],t[255]="";
    int i=0;
    fin.get(s,255);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!=' '&&s[i]!='.')
        {
            while(s[i]!=' '&&s[i]!='.')
            {
                i++;
            }
            s[i-1]='5';
        }
    }
    fout<<s;
}
