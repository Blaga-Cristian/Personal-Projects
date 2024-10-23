#include <fstream>

using namespace std;
ifstream cin("transform.in");
ofstream cout("transform.out");
const int N = 256009;
long long n,x,y,s,v[N],t[N],w[N],val[N],lider[N];
int op(int ind,int val)
{
    return 1 + ((x*ind + y*val)%n);
}
int rad(int x)
{
    int rad = x, y;
    while(t[rad] != 0) rad = t[rad];


    return rad;
}
void unire(int x,int y)
{
    if(x==0 || y ==0)
        return;
    x = rad(x);
    y = rad(y);
    if(x == y)
        return;
    if(w[x] <= w[y])
        swap(x,y);

    w[x] += w[y];
    t[y] = x;
}
int main()
{
    int ans = 0;
    cin>>n>>x>>y;
    for(int i=1;i<=n;++i)
        cin>>v[i],w[i] = 1,s+=v[i];

    for(int i = n;i>=1;--i)
    {
        if(!lider[v[i]])
        {
            lider[v[i]] = i;
            val[i] = v[i];
        }
        else
            unire(i,lider[v[i]]);
    }

    long long maxi = 0;

    for(int i=1;i<=n;++i)
    {
        int r = rad(i);
        int nw = 1 + (1LL*x*i + 1LL*y*val[r])%n;

        s += 1LL * w[r] * (nw - val[r]);
        maxi = max(maxi,s);

        unire(r,lider[nw]);

        lider[val[r]] = 0;
        val[lider[nw]] = nw;
        w[lider[nw]]--;
    }
    cout<<maxi;
    return 0;
}
