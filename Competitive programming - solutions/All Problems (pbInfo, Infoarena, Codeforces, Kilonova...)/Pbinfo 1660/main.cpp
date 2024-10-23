#include <iostream>

using namespace std;
int a=0,b=0;
int scor(int a,int b)
{
    if(a==0||b==0)return 1;
    else return scor(a-1,b)+scor(a,b-1);
}
int main()
{
    cin>>a>>b;
    cout<<scor(a,b);
    return 0;
}
