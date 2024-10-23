#include <fstream>
#include <cstring>
using namespace std;
const int N = 100009,Mod = 30011;
ifstream cin("nuz.in");
ofstream cout("nuz.out");

int c[N],sp[N];
int Count(int n,int k);

int main()
{
    int n,k;
    cin>>n>>k;

    cout<< ((Count(n,k) - Count(n,k-1) + Mod) % Mod);
    return 0;
}

int Count(int n,int k)
{
    memset(c,0,sizeof(c));
    c[0] = 1;
    sp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(i > k)
            c[i] += (25 * (sp[i-1] - sp[i-k-1] + Mod) % Mod);
        else
            c[i] += 25 * sp[i-1];

        c[i] %= Mod;
        sp[i] = (sp[i-1] + c[i]) % Mod;
    }

    return sp[n];
}
