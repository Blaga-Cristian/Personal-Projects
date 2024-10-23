#include <fstream>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("sea2.in");
ofstream cout("sea2.out");
///arbor de intervale 2d cu deque
const int N = 200009;
int n,m,x,y;
set<pair<int,int>>puncte;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>x>>y;
        puncte.insert({x,y});
        auto it = puncte.find({x,y});
        auto it2 = it;
        it ++;
        if(it != puncte.end() && it->second > y)
        {
            puncte.erase({x,y});
            cout<<"-1\n";
        }
        else
        {
            it = it2;
            it --;
            while(it != puncte.begin() && it->second < y)
                it --;
            if(it->second > y)
                it ++;
            puncte.erase(it,it2);
            cout<<puncte.size()<<'\n';
        }
    }
    return 0;
}
