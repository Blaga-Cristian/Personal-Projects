#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define eb emplace_back

using namespace std;
using pi = pair<int,int>;
const int N = 1e5 + 9;
int block;
int n,m,i,j,k,v[N];

struct queri{int i,j,k;
queri(int a,int b,int c) : i(a),j(b),k(c){}
};
vector<queri> queries;
inline bool cmp(queri a, queri b)
{return (a.j / block == b.j / block) ? (a.j / block % 2 == 0) ? a.i > b.i : a.i < b.i : a.j / block > b.j / block;}



set<pi> tree;

int main()
{
    cin>>n>>m;
    block = sqrt(n);

    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    while(m--)
    {
        cin>>i>>j>>k;
        queries.eb(i,j,k);
    }

    sort(queries.begin(),queries.end(),cmp);

    int st = 1, dr = 0;
    for(auto aux : queries)
    {
        int i = aux.i,
        j = aux.j,
        k = aux.j;

        while(dr < j)tree.insert({v[++dr],dr});
        while(st > i)tree.insert({v[--st],st});
        while(dr > i)tree.erase({v[dr],dr--});
        while(st < i)tree.erase({v[st],st++});


        for(auto it : tree)
            cout<<it.first<<' ';
        cout<<'\n';
    }
    return 0;
}
