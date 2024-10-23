#include <bits/stdc++.h>
#include <bits/extc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
#define fast_in_out ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define REP(i,a,b) for(int i = a; i <= b; ++i)
template <typename T>
using indexed_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using namespace std;


const int N = 2 * 1e5 + 9;
int v[N], poz[N];
int n,m,a,b;

int main()
{
    cin >> n >> m;
    REP(i,1,n)
    {
        cin >> v[i];
        poz[v[i]] = i;
    }

    int cnt = 1, prv = 0;
    REP(i,1,n)
    {
        if(poz[i] < prv)
            cnt ++;
        prv = poz[i];
    }

    while(m--)
    {
        cin >> a >> b;

        int aux = cnt;

        if(a > b)
            swap(a,b);

        swap(poz[v[a]], poz[v[b]]);

        if(a < n && a < poz[v[a] + 1] && poz[v[a] + 1] < b)
        {
            aux ++;
            cout<<"cond 1\n";
        }
        if(a > 1 && a < poz[v[a] - 1] && poz[v[a] - 1] < b)
        {
            aux --;
            cout<<"cond 2\n";
        }
        if(b < n && b > poz[v[b] + 1] && poz[v[b] + 1] > a)
        {
            aux --;
            cout<<"cond 3\n";
        }
        if(b > 1 && b > poz[v[b] - 1] && poz[v[b] - 1] > a)
        {
            aux ++;
            cout<<"cond 4\n";
        }

        swap(poz[v[a]], poz[v[b]]);

        cout << aux << '\n';
    }
    return 0;
}
