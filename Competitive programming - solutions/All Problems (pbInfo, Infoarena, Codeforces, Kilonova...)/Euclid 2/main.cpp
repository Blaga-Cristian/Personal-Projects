#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int Euclid(int a,int b)
{
    while(b)
    {
        int x = a%b;
        a = b;
        b = x;
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<Euclid(a,b)<<'\n';
    }
    return 0;
}
