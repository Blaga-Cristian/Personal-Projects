#include <iostream>

using namespace std;
void cmmd(int a,int b,int& r)
{
    if(a==b)r=a;
    else
    {
        if(a>b)a=a-b;
        else b=b-a;
        cmmd(a,b,r);
    }
}
int main()
{
    int a,b,r;
    cin>>a>>b;
    cmmd(a,b,r);
    cout<<r;
    return 0;
}
