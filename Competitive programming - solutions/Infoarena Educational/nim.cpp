#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");

int t,n,x;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin>>x;
            ans ^= x;
        }

        if(ans == 0)
            cout<<"NU\n";
        else
            cout<<"DA\n";
    }
    return 0;
}