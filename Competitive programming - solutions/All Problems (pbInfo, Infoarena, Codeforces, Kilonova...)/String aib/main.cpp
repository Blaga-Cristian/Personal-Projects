#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("stringaib.in");
ofstream cout("stringaib.out");
const int N = 1e5+9;
int n;
string v[N],aux[N];
int vec[N];
int aib[N];
void update(int pos,int val)
{
    for(;pos <= n; pos += pos&-pos)
        aib[pos] += val;
}
int query(int pos)
{
    int ret = 0;
    for(;pos;pos -= pos&-pos)
        ret += aib[pos];
    return ret;
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>v[i],aux[i] = v[i];

    sort(aux+1,aux+n+1);
    int sf = unique(aux+1,aux+n+1) - (aux + 1);
    for(int i = 1; i <= n; ++i)
        vec[i] = lower_bound(aux+1,aux+sf+1,v[i]) - aux;
    for(int i = 1; i <= n; ++i)
        vec[i] = sf - vec[i] + 1;

    for(int i = 1; i <= n; ++i)
    {
        cout<<query(vec[i]-1)<<' ';
        update(vec[i],1);
    }
    return 0;
}
