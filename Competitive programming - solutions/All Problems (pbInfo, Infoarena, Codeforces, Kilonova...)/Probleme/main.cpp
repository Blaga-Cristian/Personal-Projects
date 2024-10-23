#include <iostream>

using namespace std;
int nrmaxim(int n)
{
    if(n==0)return 0;
    else return n%10+sumcif(n/10);
}
int main()
{
    cin>>n;
    cout<<nrmaxim(n);
    return 0;
}
