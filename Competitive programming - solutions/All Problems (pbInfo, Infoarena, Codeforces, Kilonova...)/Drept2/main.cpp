#include <fstream>
#include <deque>

using namespace std;
ifstream cin("drept2.in");
ofstream cout("drept2.out");

int m,n,a,b,poz,rel;

template < class T, class Compare>
class dqueue
{
private:
    deque<pair<T,int>> dq;
    Compare cmp;
public:
    void push(T x,int ind)
    {
        while(!dq.empty() && !cmp(dq.back().first,x))
            dq.pop_back();
        dq.push_back({x,ind});
    }
    int query(int ind)
    {
        while(!dq.empty() && dq.front().second < ind)
            dq.pop_front();

        if(dq.size() == 0)
            return -1;
        return dq.front().first;
    }
};
int main()
{
    cin>>m>>n>>a>>b;

    dqueue<int,less<int>> mindq;
    dqueue<int,greater<int>> maxdq;

    int prv = 0,ans = 0;
    for(int i = 1; i < a; ++i)
    {
        cin>>poz>>rel;
        maxdq.push(poz,i);
        mindq.push(poz + prv + rel - 1,i);
        prv = prv + rel;
    }

    for(int i = a; i <= n; ++i)
    {
        cin>>poz>>rel;
        maxdq.push(poz,i);
        mindq.push(poz + prv + rel - 1,i);
        prv = prv + rel;

        int mn = mindq.query(i - a + 1);
        int mx = maxdq.query(i - a + 1);
        cout<<mx<<' '<<mn<<'\n';

        if(mx - mn + 1 - b >= 0)
            ans += 1 + mx - mn + 1 - b;
    }

    cout<<ans;
    return 0;
}
