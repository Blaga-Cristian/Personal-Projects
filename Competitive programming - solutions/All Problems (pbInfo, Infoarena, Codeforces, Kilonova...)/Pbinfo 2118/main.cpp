#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("minlex.in");
ofstream cout("minlex.out");
int main()
{
    char s[200001],v[200001]="";
    int i=0,h,k=0;
    cin>>s;
    h=strlen(s);
    while(s[i]!=0)
    {
        v[i]=s[i];
        v[h+i]=s[i];
        i++;
    }
    for(i=0;i<h;i++)
    {
        if(strcmp(v+i,s)<0)
        {
            k=i;
            strcpy(s,v+i);
        }
    }
    cout<<k;
    return 0;
}
