#include <fstream>
#include <vector>
using namespace std;
ifstream cin("statisticiordine.in");
ofstream cout("statisticiordine.out");
vector<int> v;
int main()
{
    int n,x,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(i=0;i<n;i++)cout<<v[i]<<" ";
    return 0;
}
