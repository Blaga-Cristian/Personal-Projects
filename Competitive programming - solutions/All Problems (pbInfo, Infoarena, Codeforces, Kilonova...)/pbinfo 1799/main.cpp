#include <iostream>

using namespace std;
long long dinti1(int n)
{
    if(n==0)return 0;
    return n+2*(dinti1(n-1));
}
int main()
{
    int n;
    cin>>n;
    cout<<dinti1(n);
    return 0;
}
