#include <iostream>
#include <map>
using namespace std;
int n,x;
map<int,int> mp;
map<int,int>::iterator it;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        mp[x]++;
    }
    for(it = mp.begin(); it != mp.end(); ++it)
        if((*it).second == 1)
    {
        cout<<(*it).first<<'\n';
        return 0;
    }
    return 0;
}
