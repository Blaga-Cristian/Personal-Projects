#include <fstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <cmath>
using namespace std;
ifstream fin("stele.in");
ofstream fout("stele.out");
typedef int NrMare[1010];
void suma(NrMare a,unsigned long long b)
{
    int i=0,t=0;
    while(b!=0)
    {
        i++;
        t=a[i]+b%10+t;
        a[i]=t%10;
        b=b/10;
        t=t/10;
    }
    while(t)
    {
        i++;
        t=a[i]+t;
        a[i]=t%10;
        t=t/10;
    }
    if(i>a[0])a[0]=i;
}
void Baza2(unsigned long long s,int cnt)
{
    if(s>0)
    {
        if(s%2==1)fout<<(char)('a'+cnt);
        cnt++;
        Baza2(s/2,cnt);
    }
}
void adunare(NrMare sum,char s[420])
{
    unsigned long long x=0;
    while(strlen(s)!=0)
    {
        x=atoll(s);
        if(x==0)x=1;
        int k=0;
        while(!islower(s[k]))k++;
        for(int i=1;i<=x;i++)suma(sum,pow(2,s[k]-'a'));
        for(int i=sum[0];i>=1;i--)fout<<sum[i];
        fout<<endl;
        char t[420]="";
        strcpy(t,s+k+1);
        strcpy(s,t);
    }
}
int main()
{
    int c;
    fin>>c;
    if(c==1)
    {
        unsigned long long s;
        fin>>s;
        Baza2(s,0);
    }
    else
    {
        int g;
        fin>>g;
        fout<<g;
        fin.get();
        char sir[421];
        NrMare sum;
        sum[0]=1;
        for(int i=1;i<=1000;i++)sum[i]=0;
        int nr;
        for(nr=0;nr<g;nr++)
        {
            fin.get(sir,420);
            fin.get();
            fout<<sir<<endl;
            //adunare(sum,sir);
        }
        //for(i=sum[0];i>=1;i--)fout<<sum[i];
    }
    return 0;
}
