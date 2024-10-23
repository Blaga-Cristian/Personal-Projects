#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define ALL(v) (v.begin(), v.end())
#define pb push_back
#define ll long long
#define ull unsigned ll

using namespace std;
ifstream fin("meeting.in");
ofstream fout("meeting.out");
const int N = 150009;

int n, q, spx[N], spy[N];
int pointsX[N], pointsY[N];

struct info
{
    vector<int> elements;
    vector<ll> sp;

    info operator + (info const& a)
    {
        info aux;

        merge(begin(elements), end(elements),
              begin(a.elements), end(a.elements),
              back_inserter(aux.elements));

        aux.sp = vector<ll>(aux.elements.size());
        for(int i = 0; i < aux.elements.size(); ++i)
        {
            aux.sp[i] = aux.elements[i];
            if(i > 0)aux.sp[i] += aux.sp[i - 1];
        }

//        for(auto i : aux.elements)
//            cout << i << ' ';
//        cout << '\n';
//        for(auto i : aux.sp)
//            cout << i << ' ';
//        cout << '\n';

        return aux;
    }
};

class Segment_Tree
{
private:
    info tree[4 * N];
public:
    void Build(int* arr, int nod = 1, int st = 1, int dr = n)
    {
        if(st == dr)
        {
            tree[nod].elements.pb(arr[st]);
            tree[nod].sp.pb(arr[st]);
            return;
        }
        int mij = (st + dr) >> 1;
        Build(arr, nod << 1, st, mij);
        Build(arr, nod << 1 | 1, mij + 1, dr);

        tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
    }

    pair<int, ll> Query_less(int l, int r, int val, int nod = 1, int st = 1, int dr = n)
    {
        if(l <= st && dr <= r)
        {
            auto ptr = lower_bound(tree[nod].elements.begin(), tree[nod].elements.end(), val) - 1;
            int cnt = (ptr - tree[nod].elements.begin() + 1);
            ull sum = 0;
            if(cnt != 0)sum = tree[nod].sp[cnt - 1];

//            cout << cnt << ' ' << sum << '\n';
//            for(auto i : tree[nod].elements)cout << i << ' ';
//            cout << '\n';

            return {cnt, sum};
        }
        int mij = (st + dr) >> 1;
        if(r <= mij)return Query_less(l, r, val, nod << 1, st, mij);
        else if(l > mij)return Query_less(l, r, val, nod << 1 | 1, mij + 1, dr);
        auto a = Query_less(l, r, val, nod << 1, st, mij), b = Query_less(l, r, val, nod << 1 | 1, mij + 1, dr);
        return {a.F + b.F, a.S + b.S};
    }

    pair<int, ull> Query_greater(int l, int r, int val, int nod = 1, int st = 1, int dr = n)
    {
        if(l <= st && dr <= r)
        {
            auto ptr = upper_bound(tree[nod].elements.begin(), tree[nod].elements.end(), val);
            int cnt = tree[nod].elements.end() - ptr;
            ull sum = 0;
            if(cnt != 0)sum = tree[nod].sp.back();
            if(cnt != 0 && cnt != tree[nod].sp.size())sum -= tree[nod].sp[tree[nod].elements.size() - cnt - 1];

//            cout << "The interval " << st << ' ' << dr << " has elements: ";
//            for(auto i : tree[nod].elements)cout << i << ' ';
//            cout << '\n';
//            cout << st << ' ' << dr << ' ' << sum << '\n';
            //if(ptr == tree[nod].end())

            return {cnt, sum};
        }
        int mij = (st + dr) >> 1;
        if(r <= mij)return Query_greater(l, r, val, nod << 1, st, mij);
        else if(l > mij)return Query_greater(l, r, val, nod << 1 | 1, mij + 1, dr);
        auto a = Query_greater(l, r, val, nod << 1, st, mij), b = Query_greater(l, r, val, nod << 1 | 1, mij + 1, dr);
        return {a.F + b.F, a.S + b.S};
    }
};
Segment_Tree treeX, treeY;

int main()
{
    fin >> n;

    ll x, y;
    REP(i, 1, n)
    {
        fin >> x >> y;
        pointsX[i] = x;
        pointsY[i] = y;
        spx[i] = spx[i - 1] + x;
        spy[i] = spy[i - 1] + y;
    }


    treeX.Build(pointsX);
    treeY.Build(pointsY);


    fin >> q;

    int l, r;
    while(q --)
    {
        fin >> l >> r;

        x = (spx[r] - spx[l - 1]) / (r - l + 1);
        if(((spx[r] - spx[l - 1]) % (r - l + 1)) * 2 > r - l + 1)x ++;
        y = (spy[r] - spy[l - 1]) / (r - l + 1);
        if(((spy[r] - spy[l - 1]) % (r - l + 1)) * 2 > r - l + 1)y ++;

        ull ans = 0;
        pair<int, ull> res1 = treeX.Query_less(l, r, x), res2 = treeX.Query_greater(l, r, x);
        ans += x * res1.F - res1.S + res2.S - x * res2.F;

        res1 = treeY.Query_less(l, r, y), res2 = treeY.Query_greater(l, r, y);
        ans += y * res1.F - res1.S + res2.S - y * res2.F;

        fout << ans << '\n';
    }
    return 0;
}
