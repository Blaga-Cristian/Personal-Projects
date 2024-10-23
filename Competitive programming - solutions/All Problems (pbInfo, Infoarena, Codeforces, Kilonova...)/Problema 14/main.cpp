#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p,c[255],t[255]="",c1[255]="";
    int n,i,j,cnt=0,max=-99,ind=-3,min=999;
    cin.get(s,255);
    p=strtok(s," ");
    while(p!=NULL)
    {
        if(islower(p[0]))p[0]=p[0]+'A'-'a';
        if(islower(p[strlen(p)-1]))p[strlen(p)-1]=p[strlen(p)-1]+'A'-'a';
        cout<<p<<" ";
        p=strtok(NULL," ");
    }
    return 0;
}
