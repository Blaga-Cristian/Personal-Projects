#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream f("spioni.in");
ofstream g("spioni.out");
int cnt;
bool sir[12];
int baza2(int nr)
{
    int i,x=0;
    for(i=0;i<12;i++)sir[i]=0;
    i=0;
    while(nr>0)
    {
        sir[i]=nr%2;
        nr=nr/2;
        i++;
    }
    for(i=0;i<cnt;i++)
    {
        if(sir[i]==1)x+=pow(2,cnt-i-1);
    }
    return x;
}
int main()
{
    int poz,x,i;
    char cerinta,s[4100],aux;
    f>>cerinta;
    f.get();
    f.get(s,4099);
    x=strlen(s);
    while(x>1)
    {
        cnt++;
        x/=2;
    }
    for(i=0;i<strlen(s);i++)
    {
        poz=baza2(i);
        aux=s[i];
        s[i]=s[poz];
        s[poz]=aux;
    }
    g<<s;
    return 0;
}
