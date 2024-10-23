#include <fstream>
#include <queue>
#include <set>
#include <deque>
#define ull unsigned long long
using namespace std;
ifstream cin("zen.in");
ofstream cout("zen.out");
int n,k;
ull ans,mini,sol;
struct zen
{
    int idx;
    ull val;
};
deque<zen>DQ;
void update(ull val,int idx)
{
    zen it = {idx,val};
    while(!DQ.empty() && DQ.back().val >= it.val)
        DQ.pop_back();
    DQ.push_back(it);
}
ull query(int idx)
{
    if(idx>k)
        if(DQ.front().idx < idx - k)
            DQ.pop_front();
    return DQ.front().val;
}
int main()
{
    int x;
    cin>>n>>k;
    DQ.push_back({0,0});
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        sol = x + query(i);
        update(sol,i);
    }
    cout<<sol;
    return 0;
}
