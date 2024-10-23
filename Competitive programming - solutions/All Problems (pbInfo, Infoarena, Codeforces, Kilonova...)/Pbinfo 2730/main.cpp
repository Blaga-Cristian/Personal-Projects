#include <iostream>
#include <cstring>
using namespace std;
int SC(char s[])
{
    int sum=0;
    if(s[0]!=0)
    {
        sum=sum+SC(s+1);
        if(s[0]<='9'&&s[0]>='0')sum=sum+s[0]-'0';
    }
    return sum;
}
int main()
{
    cout<<SC("Ana are 15 mere si 185 de pere.");
    return 0;
}
