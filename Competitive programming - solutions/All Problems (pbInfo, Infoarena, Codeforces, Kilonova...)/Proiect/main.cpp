#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("document1");
ofstream cout("document2");
char s[255];
int main()
{
    int i;
    char a[255];
    while(cin)
    {
        cin.get(a,255);
        cin.get();
        strcat(s," ");
        strcat(s,a);
    }
    cout<<s;
    return 0;
}
