#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("vocmax.in");
ofstream cout("vocmax.out");

int main()
{
    char s[101][251],t[251]="";
    int n,i,j=0,nr=0,max=-99,indice;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin.getline(s[i],255);
        j=0;
        while(s[i][j]!='\0')
        {
            if(strchr("aeiou" , s[i][j]))
                nr++;
            j++;
        }
        if(nr>max)
        {
            max=nr;
            indice=i;
        }
        nr=0;
    }
    j=0;
     while(s[indice][j]!='\0')
    {
        cout << s[indice][j];
        j++;
    }
    return 0;
}
