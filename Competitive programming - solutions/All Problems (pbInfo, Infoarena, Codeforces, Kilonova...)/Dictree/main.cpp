#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("dictree.in");
ofstream cout("dictree.out");
const int N = 25009;
int n,ans;
vector<string> v;
int cod(char c)
{
    if(c >= 'A' && c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}



int main()
{
    cin>>n;
    v = vector<string>(n);
    for(int i = 0; i < n;++i)
        cin>>v[i];

    sort(v.begin(),v.end());

    ans = v[0].size();
    for(int i = 1; i < n; ++i)
    {
        int j;
        for(j = 0; j < v[i].size() && j < v[i-1].size();++j)
            if(v[i][j] != v[i-1][j])
                break;
        ans += (v[i].size() - j);
    }

    cout<<ans+1;
    return 0;
}
