#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("cifre_romane1.in");
ofstream cout("cifre_romane1.out");
// I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
void convertire(char& s, int &nr)
{
    if(s=='I')
    {
        nr=nr+1;
        s='1';
    }
    else if(s=='V')
    {
        nr=nr+5;
        s='2';
    }
    else if(s=='X')
    {
        nr=nr+10;
        s='3';
    }
    else if(s=='L')
    {
        nr=nr+50;
        s='4';
    }
    else if(s=='C')
    {
        nr=nr+100;
        s='5';
    }
    else if(s=='D')
    {
        nr=nr+500;
        s='6';
    }
    else if(s=='M')
    {
        nr=nr+1000;
        s='7';
    }
}
int main()
{
    char s[255],ok=0;
    int i,nr=0,j;
    cin>>s;
    convertire(s[0],nr);
    for(i=0;i<strlen(s)-1;i++)
    {
        convertire(s[i+1],nr);
        if(s[i]<s[i+1])
        {
            j=i;
            while(s[j]<s[i+1]&&j>=0)
            {
                if(s[j]=='1')nr=nr-2*1;
                else if(s[j]=='2')nr=nr-2*5;
                else if(s[j]=='3')nr=nr-2*10;
                else if(s[j]=='4')nr=nr-2*50;
                else if(s[j]=='5')nr=nr-2*100;
                else if(s[j]=='6')nr=nr-2*500;
                else if(s[j]=='7')nr=nr-2*1000;
                j--;
            }
        }
    }
    for(i=0;i<strlen(s)-1;i++)
    {
        if(s[i]=='2'&&(s[i]==s[i+1]||s[i]==s[i+2]))
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='4'&&(s[i]==s[i+1]||s[i]==s[i+2]))
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='6'&&(s[i]==s[i+1]||s[i]==s[i+2]))
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]==s[i+2]&&s[i+1]>s[i])
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='1'&&s[i+1]>='5')
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]<s[i+2]&&s[i+1]<s[i+2])
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]<s[i+2]&&s[i]<s[i+2])
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='2'&&s[i]<s[i+1])
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i+2]==s[i+3])
        {
            cout<<"Numar invalid";
            ok=1;
        }
    }
    if(ok==0)cout<<nr;
    return 0;
}
