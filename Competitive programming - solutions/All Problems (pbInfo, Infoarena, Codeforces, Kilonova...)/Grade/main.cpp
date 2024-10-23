#include <fstream>
#include <vector>
using namespace std;
ifstream cin("grade.in");
ofstream cout("grade.out");
using VI = vector<int>;
using VVB = vector<vector<bool> >;
VVB v;
int main()
{
    int n;
    cin>>n;
    v = VVB(n+1,vector<bool>(n+1,0));
    while(cin)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    for(auto i:v)
    {
        int cnt=0;
        for(auto j:i)
        {
            cnt+=j;
        }
        if(i!=v[0])cout<<cnt<<' ';
    }
    return 0;
}
