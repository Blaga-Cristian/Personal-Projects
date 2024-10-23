#include <bits/stdc++.h>
#define PI pair<int, int>
#define X first
#define Y second
using namespace std;
const int N = 159;

int n, m, t, q, op, l, k;
PI tree[N], stree[N];

struct hash_pair
{
    template<class T1, class T2>
    size_t operator () (pair<T1, T2> const& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if(hash1 != hash2)
            return hash1 ^ hash2;

        return hash1;
    }
};
unordered_map<PI, bool, hash_pair> cut;

int solve(int lat)
{
    cut.clear();

    int x, y, erased = 0, robots = 0;
    while(erased < t)
    {
        x = y = 1;
        for(int i = 0; i < t; ++i)
        {
            if(cut[stree[i]])continue;

            if(x == 1)x = stree[i].X;

            if(stree[i].X - x + 1 <= lat || stree[i].Y >= y)
            {
                cut[stree[i]] = true;
                cout << stree[i].X << ' ' << stree[i].Y << '\n';
                erased ++;
                y = max(y, stree[i].Y - lat + 1);
            }
        }

        cout << "\n\n\n";
        ++ robots;
    }

    return robots;
}

int main()
{
    freopen("roboti1.in", "r", stdin);
    freopen("roboti1.out", "w", stdout);

    cin >> op;
    cin >> n >> m >> t;

    for(int i = 0; i < t; ++i)
    {
        cin >> tree[i].X >> tree[i].Y;
        stree[i] = tree[i];
    }
    sort(stree, stree + t, [](PI const& a, PI const& b){return a.X < b.X;});


    if(op == 1)
    {
        cin >> l;
        cout << solve(l);
    }
    else
    {
        cin >> q;
        while(q --)
        {
            cin >> k;
            int st = 1, dr = min(n, m), poz = 1;
            while(st <= dr)
            {
                int mij = (st + dr) >> 1;
                if(solve(mij) <= k)
                {
                    poz = mij;
                    dr = mij - 1;
                }
                else
                    st = mij + 1;
            }

            cout << poz << '\n';
        }
    }
    return 0;
}
