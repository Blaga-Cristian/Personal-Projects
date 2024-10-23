#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],c[255],t[256]="";;
    int i;
    cin>>s;
    cin>>c;
    if(strlen(s)!=strlen(c))cout<<"cod incorect";
    else
    {
        t[0]=s[0];
        for(i=1;i<strlen(s);i++)
        {
            if(c[i]%2==0)
            {
                char sir[256]="";
                sir[0]=s[i];
                strcat(sir,t);
                strcpy(t,sir);
            }
            else
            {
                char sir[256]="";
                sir[0]=s[i];
                strcat(t,sir);
            }
        }
    }
    cout<<t;
    return 0;
}
