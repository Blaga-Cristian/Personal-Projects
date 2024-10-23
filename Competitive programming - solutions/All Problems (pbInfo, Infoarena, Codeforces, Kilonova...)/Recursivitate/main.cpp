#include <iostream>

using namespace std;
int DivImpRec(int n)
{
    if(n%2==1)return n;
    else return DivImpRec(n/2);
}
int main()
{
    int n;
    cin>>n;
    cout<<DivImpRec(n);
    return 0;
}
