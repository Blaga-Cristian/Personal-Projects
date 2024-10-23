#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int i,j,ok,k;
    cin.getline(s,255);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
        {
            j=i+1;
            ok=0;
            while(s[j]!=' ')
            {
                if((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))ok=1;
                j++;
            }
            if(ok==1)
            {
                for(k=i+1;k<=(j-1-i-1)/2;k++)
                {
                    int aux=s[k];
                    s[k]=s[j-1-k+i+1];
                    s[j-1-k+i+1]=aux;
                }
            }
            i=j;
        }
    }
    cout<<s;
    return 0;
}
