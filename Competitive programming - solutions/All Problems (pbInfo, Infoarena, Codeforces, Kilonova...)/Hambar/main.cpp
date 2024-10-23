#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("hambar.in");
ofstream cout("hambar.out");
const int N = 1009;
using PI = pair<int,int>;
int n,m,mat[N][N];
pair<int,int> dp[N][N];
vector<pair<int,int> >v;
inline int cb(PI a)
{
    int st = 0,dr = v.size()-1,poz = -1;
    while(st<=dr)
    {
        int mij = (st+dr)>>1;
        if(v[mij] >= a)
        {
            poz = mij;
            dr = mij-1;
        }
        else
            st = mij+1;
    }
    return poz;
}
int diveimp(int x1,int y1,int x2,int y2)
{
    if(!(x1<=x2&&y1<=y2))return -1;
    int poz = cb({x1,y1});
    if(poz==-1)return (x2-x1+1)*(y2-y1+1);
    PI a = v[poz];
    if(a.first <= x2 && a.second <= y2)
    {
        int val1,val2,val3,val4;
        //val1 = diveimp(x1,y1,x2,a.second-1);
        cout<<x1<<' '<<y1<<' '<<x1<<' '<<a.second-1<<'\n';
        //val2 = diveimp(x1,y1,a.first -1,y2);
        cout<<x1<<' '<<y1<<' '<<a.first-1<<' '<<y2<<'\n';
        //val3 = diveimp(x1,a.second+1,x2,y2);
        cout<<x1<<' '<<a.second+1<<' '<<x2<<' '<<y2<<'\n';
        //val4 = diveimp(a.first+1,y1,x2,y2);
        cout<<a.first+1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
        //return max({val1,val2,val3,val4});
    }
}
int main()
{
    int a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        mat[a][b] = 1;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    diveimp(1,1,n,n);
    return 0;
}
