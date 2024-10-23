#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[101];
    cin.get(s,100);
    char *p=strtok(s," ");
    while(p!=NULL)
    {
        if(strlen(p)%2==1)
        {
            for(int i=0;i<strlen(p)/2;i++)
            {
                int aux=p[i];
                p[i]=p[strlen(p)-1-i];
                p[strlen(p)-1-i]=aux;
            }
        }
        cout<<p<<" ";
        p=strtok(NULL," ");
    }
    return 0;
}
