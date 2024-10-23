#include <fstream>

using namespace std;
ifstream cin("skyline.in");
ofstream cout("skyline.out");
struct bloc
{
    int h,l;
}s[101];

int main()
{
    int n,i,j,max=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s[i].h>>s[i].l;
    }
    for(i=1;i<=n;i++)
    {
        int lungime=s[i].l;
        j=i-1;
        while(j>=1)
        {
            if(s[j].h>=s[i].h)lungime=lungime+s[j].l;
            else break;
            j--;
        }
        j=i+1;
        while(j<=n)
        {
            if(s[j].h>=s[i].h)lungime=lungime+s[j].l;
            else break;
            j++;
        }
        if(lungime*s[i].h>max)
        {
            max=lungime*s[i].h;
        }
    }
    cout<<max;
    return 0;
}
