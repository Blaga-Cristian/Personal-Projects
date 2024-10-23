#include <fstream>

using namespace std;
ifstream cin("moka.in");
ofstream cout("moka.out");
const int N=1999999973;
unsigned long long Putere(unsigned long long a,unsigned long long n)
{
    if(n == 0)
        return 1;
    else
    {
        unsigned long long x=Putere(a,n/2);
        if(n%2==0)return x*x%N;
        else return x*x%N*a%N;
    }
}
int main()
{
    unsigned long long a,b;
    cin>>a>>b;
    cout<<Putere(a,b)%N;
    return 0;
}
