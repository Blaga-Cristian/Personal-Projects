#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;
int n, m;
struct muchie{int a, b, c;}muchii[2 * N];
int t[N];

int Find(int x){return t[x] == 0 ? x : t[x] = Find(t[x]);}
void Merge(int a, int b){t[Find(a)] = Find(b);}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
        cin >> muchii[i].a >> muchii[i].b >> muchii[i].c;

    sort(muchii + 1, muchii + m + 1, [](muchie a, muchie b){return a.c < b.c;});

    ll ans = 0;
    int trees = n;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        a = muchii[i].a;
        b = muchii[i].b;
        c = muchii[i].c;

        if(Find(a) == Find(b))continue;

        Merge(a, b);
        ans += c;
        trees --;
    }

    if(trees == 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
    return 0;
}
