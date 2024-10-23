#include <iostream>

using namespace std;
double nreal(int x,int y)
{
    double s=0;
    while(y!=0)
    {
        s=s/10+y%10;
        y=y/10;
    }
    s=s/10;
    s=s+x;
    return s;
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<nreal(x,y);
    return 0;
}
