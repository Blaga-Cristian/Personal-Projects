#include <fstream>
#include <vector>
using namespace std;
ifstream cin("tabela.in");
ofstream cout("tabela.out");
vector<vector<int> > v;
int main()
{
    int n,m,k,i,j;
    cin>>n>>m;
    int c=(n-1)^(m-1);
    cout<<c;
    return 0;
}
