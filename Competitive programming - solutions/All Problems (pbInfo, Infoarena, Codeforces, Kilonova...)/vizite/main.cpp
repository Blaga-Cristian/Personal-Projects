#include <fstream>

using namespace std;
ifstream cin("vizita.in");
ofstream cout("vizita.out");


long long x,v[2000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
    {
        cin>>x;
        if(j==1)
            v[j] = v[j] + x;
        else
        {
            if(j==i) v[j] = v[j-1] + x;
            else v[j] = min(v[j],v[j-1]) + x;
        }
    }

    v[1] = v[n];

    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
    {
        cin>>x;
        if(j==1) v[j] = v[j] + x;
        else
        {
            if(j==i) v[j] = v[j-1] + x;
            else v[j] = min(v[j],v[j-1]) + x;
        }
    }
    cout<<v[n];
    return 0;
}
