#include <fstream>

using namespace std;
ifstream cin("sume1.in");
ofstream cout("sume1.out");
unsigned long long putere(unsigned long long n)
{
    if(n==0)return 1;
    else
    {
        unsigned long long x=putere(n/2);
        if(n%2==1)return x%1000000007*x%1000000007*2%1000000007;
        else return x%1000000007*x%1000000007;
    }
}
int main()
{
    unsigned long long n;
    cin>>n;
    cout<<putere(n+1)-1;
    return 0;
}
