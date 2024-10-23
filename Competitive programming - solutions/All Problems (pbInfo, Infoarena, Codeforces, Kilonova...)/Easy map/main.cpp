#include <iostream>
#include <unordered_map>
using namespace std;
string s;
int n;
int maxi;
string ans;
unordered_map<string,int>mymap;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>s;
        mymap[s]++;
    }
    for(auto i : mymap)
    {
        if(i.second > maxi)
        {
            maxi = i.second;
            ans = i.first;
        }
        else if(i.second == maxi && i.first < ans)
        {
            ans = i.first;
        }
    }
    cout<<ans<<' '<<maxi;
    return 0;
}
