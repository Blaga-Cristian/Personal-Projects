#include <fstream>
#include <cstring>
#define N 2000005
using namespace std;
ifstream cin("strmatch.in");
ofstream cout("strmatch.out");
char s1[N],s2[N],dp[N][N];

int main()
{
    cin.get(s1,N);
    cin.get();
    cin.get(s2,N);
    cin.get();
    for(int i=0;i<strlen(s1);++i)
        for(int j=0;j<strlen(s2);++j)
            if(s1[i]==s2[j])

    return 0;
}
