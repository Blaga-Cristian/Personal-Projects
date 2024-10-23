#include <fstream>
#include <vector>
#define ull unsigned long long
using namespace std;
ifstream cin("superperfecte.in");
ofstream cout("superperfecte.out");
const int MOD = 555557,N=3;
int n;
ull a,b;
struct mat2x2 {
   int a, b, c, d;
};

mat2x2 inmultire(mat2x2 x, mat2x2 y)
{
   return {
      (1ll*x.a*y.a + 1ll*x.b*y.c) % MOD,
      (1ll*x.a*y.b + 1ll*x.b*y.d) % MOD,
      (1ll*x.c*y.a + 1ll*x.d*y.c) % MOD,
      (1ll*x.c*y.b + 1ll*x.d*y.d) % MOD
   };
}
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<4;
        return 0;
    }
    mat2x2 mat = {0,3,1,1},ans = {1,0,0,1};
    int exp = n-1;
      for (; exp; exp >>= 1)
      {
         if (exp & 1)
            ans = inmultire(ans, mat);
         mat = inmultire(mat, mat);
      }

    cout<<(3*ans.a + 3*ans.c)%MOD;
    return 0;
}
