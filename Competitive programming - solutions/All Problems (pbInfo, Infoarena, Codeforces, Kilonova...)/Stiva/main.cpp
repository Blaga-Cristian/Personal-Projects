#include <fstream>
#include <stack>
using namespace std;
ifstream cin("intervale4.in");
ofstream cout("intervale4.out");
struct interval{
int x,y;
};
stack<interval>stiva;
bool seintersecteaza(interval a, interval b) {
    if (a.x <= b.x && a.y >= b.x)
        return 1;
    if (b.x <= a.x && b.y >= a.x)
        return 1;
    if (a.x >= b.x && a.y <= b.y)
        return 1;
    if (b.x >= a.x && b.y <= a.y)
        return 1;
    return 0;
}
interval intersectie(interval a,interval b)
{
    return {min(a.x,b.x),max(a.y,b.y)};
}
int main()
{
    interval a,b;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a.x>>a.y;
        while(!stiva.empty()&&seintersecteaza(a,stiva.top()))
        {
            b=stiva.top();
            stiva.pop();
            a=intersectie(a,b);
        }
        stiva.push(a);
    }
    cout<<stiva.size();
    return 0;
}
