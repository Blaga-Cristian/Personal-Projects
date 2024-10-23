#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("cifre_romane2.in");
ofstream cout("cifre_romane2.out");
// I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
void convertire2(char& s, int &nr)
{
    if(s=='V')
    {
        nr=nr+5000;
        s='a';
    }
    else if(s=='X')
    {
        nr=nr+10000;
        s='b';
    }
    else if(s=='L')
    {
        nr=nr+50000;
        s='c';
    }
    else if(s=='C')
    {
        nr=nr+100000;
        s='d';
    }
    else if(s=='D')
    {
        nr=nr+500000;
        s='e';
    }
    else if(s=='M')
    {
        nr=nr+1000000;
        s='f';
    }
}
void convertire(char s[], int &nr,int i)
{
    char t[255]="";
    if(s[i]=='I')
    {
        nr=nr+1;
        s[i]='1';
    }
    else if(s[i]=='V')
    {
        nr=nr+5;
        s[i]='2';
    }
    else if(s[i]=='X')
    {
        nr=nr+10;
        s[i]='3';
    }
    else if(s[i]=='L')
    {
        nr=nr+50;
        s[i]='4';
    }
    else if(s[i]=='C')
    {
        nr=nr+100;
        s[i]='5';
    }
    else if(s[i]=='D')
    {
        nr=nr+500;
        s[i]='6';
    }
    else if(s[i]=='M')
    {
        nr=nr+1000;
        s[i]='7';
    }
    else if(s[i]=='(')
    {
        convertire2(s[i+1],nr);
        strcpy(t,s+i+1);
        strcpy(s+i,t);
        strcpy(t,s+i+2);
        strcpy(s+i+1,t);
    }
}
char cif_rom[1001] , rez[256];
int n , cnt = 1 , h;
int main()
{
    char s[1000],ok=0,t[1000]="";
    int i=0,nr=0,j,c;
    cin>>c;
    if(c==2)
    {
    cin>>s;
    convertire(s,nr,i);
    for(i=0;i<strlen(s)-1;i++)
    {
        convertire(s,nr,i+1);
        if(s[i]<s[i+1])
        {
            if(s[i]=='1')nr=nr-2*1;
            else if(s[i]=='2')nr=nr-2*5;
            else if(s[i]=='3')nr=nr-2*10;
            else if(s[i]=='4')nr=nr-2*50;
            else if(s[i]=='5')nr=nr-2*100;
            else if(s[i]=='6')nr=nr-2*500;
            else if(s[i]=='7')nr=nr-2*1000;
            else if(s[i]=='a')nr=nr-2*5000;
            else if(s[i]=='b')nr=nr-2*10000;
            else if(s[i]=='c')nr=nr-2*50000;
            else if(s[i]=='d')nr=nr-2*100000;
            else if(s[i]=='e')nr=nr-2*500000;
            else if(s[i]=='f')nr=nr-2*1000000;
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
        else if(s[i]=='a'&&(s[i]==s[i+1]||s[i]==s[i+2]))
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='c'&&(s[i]==s[i+1]||s[i]==s[i+2]))
        {
            cout<<"Numar invalid";
            ok=1;
        }
        else if(s[i]=='e'&&(s[i]==s[i+1]||s[i]==s[i+2]))
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
    }
    else if(c==1)
    {
    cin >> n;
    i=0;
    if(n>=1000000)
    {
        while(n>=1000000)
        {
            s[i]='(';
            s[i+1]='M';
            s[i+2]=')';
            i=i+3;
            n=n-1000000;
        }
    }
    if(n>=900000)
    {
        s[i]='(';
        s[i+1]='C';
        s[i+2]=')';
        s[i+3]='(';
        s[i+4]='M';
        s[i+5]=')';
        i=i+6;
        n=n-900000;
    }
    if(n<900000&&n>500000)
    {
        while(n>=100000)
        {
            s[i]='(';
            s[i+1]='M';
            s[i+2]=')';
            i=i+3;
            n=n-1000000;
        }
    }
    s[i]=0;
    cout<<s;
    }
    return 0;
}
