#include <iostream>
#include <fstream>

using namespace std;
ifstream fin(" bac.in");
int main()
{
    int n,nr,cop,s=0,i;
    int sufix[100]={0}, prefix[100]={0};
    while(fin>>n);
    {
        cop=n;
        while(cop>99)
        {
            cop=cop/10;
        }
        prefix[cop]++;
        nr=n%100;
        sufix[nr]++;
    }
    for(i=10;i<=99;i++)
    {
        if(prefix[i]==sufix[i]&&sufix[i]!=0) s=s+1;
    }
    cout << s << endl;
    return 0;
}
