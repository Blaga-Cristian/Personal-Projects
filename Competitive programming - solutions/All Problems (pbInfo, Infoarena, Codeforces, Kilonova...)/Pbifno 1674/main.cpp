#include <iostream>
#include <cstring>
using namespace std;
int nr_vocale(char s[])
{
    int sum=0;
    if(s[0]!=0)
    {
        sum=sum+nr_vocale(s+1);
        if(strchr("AEIOUaeiou",s[0])!=0)sum++;
    }
    return sum;
}
int main()
{
    char s[101];
    cin.get(s,255);
    cout<<nr_vocale(s);
    return 0;
}
