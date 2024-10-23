#include <iostream>
#include <cstring>
using namespace std;
int v[8];
int main()
{
    char s[100001];
    int i,k=4,l,nr=0,ok=0,vocala,consoana,oricare,j;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='a'||s[i]=='A')v[1]++;
        else if(s[i]=='d'||s[i]=='D')v[2]++;
        else if(s[i]=='o'||s[i]=='O')v[3]++;
        else if(s[i]=='b'||s[i]=='B')v[4]++;
        else if(s[i]=='e'||s[i]=='E')v[5]++;
        else if(s[i]=='+')v[6]++;
        else if(s[i]=='-')v[7]++;
        else if(s[i]=='*')v[8]++;
        if(i>=5)
        {
        if(s[i-5]=='a'||s[i-5]=='A')v[1]--;
        else if(s[i-5]=='d'||s[i-5]=='D')v[2]--;
        else if(s[i-5]=='o'||s[i-5]=='O')v[3]--;
        else if(s[i-5]=='b'||s[i-5]=='B')v[4]--;
        else if(s[i-5]=='e'||s[i-5]=='E')v[5]--;
        else if(s[i-5]=='+')v[6]--;
        else if(s[i-5]=='-')v[7]--;
        else if(s[i-5]=='*')v[8]--;
        }
        if(i>=4)
        {
            ok=1;
            vocala=0;
            consoana=0;
            oricare=0;
            if(v[1]==0&&v[7]!=0&&v[7]>=vocala)vocala++;
            else if(v[1]==0&&v[8]!=0&&v[8]>=oricare)oricare++;
            else ok=0;
            if(v[2]==0&&v[6]!=0&&v[6]>=consoana)consoana++;
            else if(v[2]==0&&v[8]!=0&&v[8]>=oricare)oricare++;
            else ok=0;
            if(v[3]==0&&v[7]!=0&&v[7]>=vocala)vocala++;
            else if(v[3]==0&&v[8]!=0&&v[8]>=oricare)oricare++;
            else ok=0;
            if(v[4]==0&&v[6]!=0&&v[6]>=consoana)consoana++;
            else if(v[4]==0&&v[8]!=0&&v[8]>=oricare)oricare++;
            else ok=0;
            if(v[5]==0&&v[7]!=0&&v[7]>=vocala)vocala++;
            else if(v[5]==0&&v[8]!=0&&v[8]>=oricare)oricare++;
            else ok=0;
            nr=nr+ok;
        }
    }
    cout<<nr+1;
    return 0;
}
