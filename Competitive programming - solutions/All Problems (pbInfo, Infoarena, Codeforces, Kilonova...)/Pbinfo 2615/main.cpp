#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("caesar.in");
ofstream cout("dbftbs.out");

int main()
{
    char s[257],k[10]="";
    int n,i;
    cin.get(s,256);
    cin>>n>>k;
    if(n>=26)n=n%26;
    if(strcmp(k,"encrypt")==0)
    {
        for(i=0;i<strlen(s);i++)
        {
            if(islower(s[i]))
            {
                if(s[i]+n>=123)s[i]=s[i]-('z'-'a')-1;
                s[i]=s[i]+n;
            }
            else if(isupper(s[i]))
            {
                s[i]=s[i]+n;
                if(s[i]>'Z')s[i]=s[i]-('Z'-'A')-1;
            }
        }
    }
    else if(strcmp(k,"decrypt")==0)
    {
        for(i=0;i<strlen(s);i++)
        {
            if(islower(s[i]))
            {
                s[i]=s[i]-n;
                if(s[i]<'a')s[i]=s[i]+('z'-'a')+1;
            }
            else if(isupper(s[i]))
            {
                s[i]=s[i]-n;
                if(s[i]<'A')s[i]=s[i]+('Z'-'A')+1;
            }
        }
    }
    cout<<s;
    return 0;
}
