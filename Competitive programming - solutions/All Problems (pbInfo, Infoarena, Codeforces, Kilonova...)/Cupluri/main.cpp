#include <iostream>

using namespace std;
#define modulo 1.000.000.007

bool mat[30][30];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>mat[i][j];
    return 0;
}
