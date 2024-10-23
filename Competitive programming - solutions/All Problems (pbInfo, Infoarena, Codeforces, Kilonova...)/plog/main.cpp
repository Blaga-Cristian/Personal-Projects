#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans = 1;
    while(b)
    {
        if(b%2==1)
            ans = ans*a;
        a = a*a;
        b = b/2;
    }
    cout<<ans;
    return 0;
}
