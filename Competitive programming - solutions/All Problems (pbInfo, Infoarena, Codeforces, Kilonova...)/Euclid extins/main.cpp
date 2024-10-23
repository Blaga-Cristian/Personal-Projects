#include <fstream>

using namespace std;
ifstream cin("euclid3.in");
ofstream cout("euclid3.out");
int t,a,b,d;
void euclid(int a, int b, int *d, int *x, int *y)
{
    if (b == 0) {
        *d = a;
        *x = 1;
        *y = 0;
    } else {
        int x0, y0;
        euclid(b, a % b, d, &x0, &y0);
        *x = y0;
        *y = x0 - (a / b) * y0;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>d;
        int x,y;
        euclid(a,b,&d,&x,&y);
        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}
