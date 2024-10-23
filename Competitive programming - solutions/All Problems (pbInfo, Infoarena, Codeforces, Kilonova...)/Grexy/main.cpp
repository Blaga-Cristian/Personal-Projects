#include <fstream>
#include <cstdlib>
using namespace std;
FILE* in = fopen("grexy.in","rb");
FILE* out = fopen("grexy.out","wb");
const int mod = 666013,X = 100009;
int Cuv[X],Pa[X];
int n,x;
inline void Dynamic()
{
    Cuv[1] = 26;
    Pa[1] = 26;
    for(int i=2;i<=X;++i)
    {
        Cuv[i] = Cuv[i-1]*26;
        if(Cuv[i]>mod)
            Cuv[i]-=mod;
        if(i%2==1)
        {Pa[i] = 26*Cuv[i/2];
            if(Pa[i]>mod)
                Pa[i]-=mod;}
        else
            Pa[i] = Cuv[i/2];
    }
}
int main()
{
    Dynamic();
    fscanf(in,"%d",&n);
    for(int i=1;i<=n;++i)
    {
        fscanf(in,"%d",&x);
        fprintf(out,"%d\n",(Cuv[x] - Pa[x] + mod) % mod);
    }
    return 0;
}
