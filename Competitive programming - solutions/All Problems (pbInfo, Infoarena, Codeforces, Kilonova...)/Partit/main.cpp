#include <fstream>
#include <vector>
#define ull unsigned long long
using namespace std;
ifstream cin("partit.in");
ofstream cout("partit.out");
const unsigned long long  Inf = 2 * 9223372036854775807LL;
int n,c,a;
unsigned long long k,p[70];

inline void init()
{
    p[0] = 1;
    p[1] = 1;
    for(int i=2;i<=68;++i)
        p[i] = min(p[i-1]<<1,Inf);

}

vector<int> partitie(int n,ull ord)
{
    vector<int> ans;
    while(n>0)
    {
        int act = 1;
        while(ord > p[n-act])
            ord-=p[n-act],act++;

        ans.push_back(act);
        n-=act;
    }

    return ans;
}

ull order(int n,vector<int> partition)
{
    ull ans=1;
    int act = 1;
    for(auto i : partition)
    {
        for(int j=1;j<i;++j)
            ans += p[n-j];
        n-=i;
    }
    return ans;
}


int main()
{
    init();
    cin>>c>>n;
    if(c==1)
    {
        while(n>64)
        {
            cout<<1<<' ';
            n--;
        }
        cin>>k;
        auto ans = partitie(n,k);
        for(auto i : ans)
            cout<<i<<' ';
    }
    else
    {
        int sum = 0;
        vector<int> v;
        while(sum<n)
            cin>>a,v.push_back(a),sum+=a;
        cout<<order(n,v);
    }
    return 0;
}
