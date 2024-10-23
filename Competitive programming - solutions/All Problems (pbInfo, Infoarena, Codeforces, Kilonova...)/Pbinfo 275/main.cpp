#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("perechivocale1.in");
ofstream cout("perechivocale1.out");
int f[1000];
int main()
{
    char s[255],v[100][100];
    int i,ok=0,j,max=-1,nr=0;
    while(cin)
    {
        cin.getline(s,255);
        if(strlen(s)>1)
        {
        nr++;
        for(i=0;i<strlen(s)-1;i++)
        {
            if(strchr("aeiou",s[i])!=0&&strchr("aeiou",s[i+1])!=0)
            {
                char sir[3]="";
                sir[0]=s[i];
                sir[1]=s[i+1];
                sir[2]=0;
                ok=0;
                j=0;
                while(ok==0)
                {
                    if(strcmp(v[j],sir)==0)
                    {
                        f[j]++;
                        if(f[j]>max)max=f[j];
                        ok=1;
                    }
                    else if(v[j][0]==0)
                    {
                        strcpy(v[j],sir);
                        f[j]++;
                        if(f[j]>max)max=f[j];
                        ok=1;
                    }
                    j++;
                }
            }
        }
        }
    }
    j=0;
    while(v[j][0]!=0)
    {
        if(f[j]==max)cout<<v[j]<<" ";
        j++;
    }
    return 0;
}
