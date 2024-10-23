#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
ifstream cin("scmax.in");
ofstream cout("scmax.out");
const int N = 1e5 + 9;
int n,v[N],c[N],len,poz;
int p[N];
vector<int> anz;

int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    for(int i = 1; i <= n; ++i)
    {
        poz = lower_bound(c,c+len,v[i]) - c;
        len += (poz == len);
        c[poz] = v[i];
        p[i] = poz;
    }

    int ans = -1;
    for(int i = 1; i <= n; ++i)
        ans = max(ans,p[i]);
    cout<<ans+1<<'\n';
    int poz = ans,val = INT_MAX;
    for(int i = n; i >= 1; --i)
        if(p[i] == poz && v[i] < val)
    {
        anz.push_back(v[i]);
        poz --;
        val = v[i];
    }
    for(int i = anz.size() - 1; i >= 0; --i)
        cout<<anz[i]<<' ';
    return 0;
}
