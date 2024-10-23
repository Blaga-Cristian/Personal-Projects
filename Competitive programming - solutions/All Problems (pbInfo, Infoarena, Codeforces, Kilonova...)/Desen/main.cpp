#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream cin("desen.in");
ofstream cout("desen.out");
const int N = 1009,Inf = 0x3f3f3f3f;
int n;
struct punct
{
    int x,y;
};
punct point[N];

double getdist(punct a,punct b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    double cost = 0;
    cin>>n;
    cout<<fixed << setprecision(6);
    cin>>point[1].x>>point[1].y;
    cout<<cost<<'\n';
    for(int i = 2; i <= n; ++i)
    {
        cin>>point[i].x>>point[i].y;
        double mn = Inf;
        for(int j = 1; j < i; ++j)
            mn = min(mn,getdist(point[j],point[i]));
        cost += mn;
        cout<<cost<<'\n';
    }
    return 0;
}
