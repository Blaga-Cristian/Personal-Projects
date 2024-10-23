#include <fstream>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("pikachu.in");
ofstream cout("pikachu.out");
const int N = 100009;
int n,k,aint[3*N];
vector<int> a;
set<int>st;
int main()
{
    cin>>n>>k;
    a = vector<int>(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];

    return 0;
}
