#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9;

class Beats
{
    const ll Inf = 1e18;
    int n;
    vector<ll> sum,
    mx, cmx, smx,
    mn, cmn, smn,
    ladd,
    len;

    void update(int k)
    {
        sum[k] = sum[k << 1] + sum[k << 1 | 1];

        if(mx[k << 1] < mx[k << 1 | 1])
        {
            mx[k] = mx[k << 1 | 1];
            cmx[k] = cmx[k << 1 | 1];
            smx[k] = max(mx[k << 1], smx[k << 1 | 1]);
        }
        else if(mx[k << 1] > mx[k << 1 | 1])
        {
            mx[k] = mx[k << 1];
            cmx[k] = cmx[k << 1];
            smx[k] = max(smx[k << 1], mx[k << 1 | 1]);
        }
        else
        {
            mx[k] = mx[k << 1];
            cmx[k] = cmx[k << 1] + cmx[k << 1 | 1];
            smx[k] = max(smx[k << 1], smx[k << 1 | 1]);
        }

        if(mn[k << 1] < mn[k << 1 | 1])
        {
            mn[k] = mn[k << 1];
            cmn[k] = cmn[k << 1];
            smn[k] = min(smn[k << 1], mn[k << 1 | 1]);
        }
        else if(mn[k << 1] > mn[k << 1 | 1])
        {
            mn[k] = mn[k << 1 | 1];
            cmn[k] = cmn[k << 1 | 1];
            smn[k] = min(mn[k << 1], smn[k << 1 | 1]);
        }
        else
        {
            mn[k] = mn[k << 1];
            cmn[k] = cmn[k << 1] + cmn[k << 1 | 1];
            smn[k] = min(smn[k << 1], smn[k << 1 | 1]);
        }
    }

    void update_node_max(int k, int b)
    {
        sum[k] += (b - mx[k]) * cmx[k];

        if(mx[k] == mn[k])mn[k] = mx[k] = b;
        else if(mx[k] == smn[k])mx[k] = smn[k] = b;
        else mx[k] = b;
    }

    void update_node_min(int k, int b)
    {
        sum[k] += (b - mn[k]) * cmn[k];

        if(mn[k] == mx[k])mn[k] = mx[k] = b;
        else if(mn[k] == smx[k])mn[k] = smx[k] = b;
        else mn[k] = b;
    }

    void update_node_add(int k, int b)
    {
        sum[k] += b * len[k];

        mx[k] += b;
        if(smx[k] != -Inf)smx[k] += b;
        mn[k] += b;
        if(smn[k] != Inf)smn[k] += b;

        ladd[k] += b;
    }

    void push(int k)
    {
        if(len[k] == 1)return;

        if(ladd[k] != 0)
        {
            update_node_add(k << 1, ladd[k]);
            update_node_add(k << 1 | 1, ladd[k]);
            ladd[k] = 0;
        }

        if(mx[k << 1] > mx[k])update_node_max(k << 1, mx[k]);
        if(mx[k << 1 | 1] > mx[k])update_node_max(k << 1 | 1, mx[k]);

        if(mn[k << 1] < mn[k])update_node_min(k << 1, mn[k]);
        if(mn[k << 1 | 1] < mn[k])update_node_min(k << 1 | 1, mn[k]);
    }

    void Build(int* arr, int nod, int st, int dr)
    {
        len[nod] = dr - st + 1;
        ladd[nod] = 0;
        if(st == dr)
        {
            sum[nod] =
            mn[nod] = mx[nod] = arr[st];
            cmn[nod] = cmx[nod] = 1;
            smn[nod] = Inf, smx[nod] = -Inf;
            return;
        }
        int m = (st + dr) >> 1;
        Build(arr, nod << 1, st, m);
        Build(arr, nod << 1 | 1, m + 1, dr);
        update(nod);
    }


public:

    Beats(int n, int* arr) : n(n)
    {
        sum =
        mx = cmx = smx =
        mn = cmn = smn =
        ladd =
        len =
        vector<ll>(4 * n);

        Build(arr, 1, 1, n);
    }

    void update_min(int l, int r, int b, int nod, int st, int dr)
    {
        if(r < st || dr < l || b >= mx[nod])return;
        if(l <= st && dr <= r && b > smx[nod])
        {
            update_node_max(nod, b);
            return;
        }
        push(nod);
        int m = (st + dr) >> 1;
        update_min(l, r, b, nod << 1, st, m);
        update_min(l, r, b, nod << 1 | 1, m + 1, dr);
        update(nod);
    }
    void update_min(int l, int r, int b)
    {
        update_min(l, r, b, 1, 1, n);
    }


    void update_max(int l, int r, int b, int nod, int st, int dr)
    {
        if(r < st || dr < l || b <= mn[nod])return;
        if(l <= st && dr <= r && b < smn[nod])
        {
            update_node_min(nod, b);
            return;
        }
        push(nod);
        int m = (st + dr) >> 1;
        update_max(l, r, b, nod << 1, st, m);
        update_max(l, r, b, nod << 1 | 1, m + 1, dr);
        update(nod);
    }
    void update_max(int l, int r, int b)
    {
        update_max(l, r, b, 1, 1, n);
    }


    void update_add(int l, int r, int b, int nod, int st, int dr)
    {
        if(l <= st && dr <= r)
        {
            update_node_add(nod, b);
            return;
        }
        push(nod);
        int m = (st + dr) >> 1;
        if(l <= m)update_add(l, r, b, nod << 1, st, m);
        if(r > m)update_add(l, r, b, nod << 1 | 1, m + 1, dr);
        update(nod);
    }
    void update_add(int l, int r, int b)
    {
        update_add(l, r, b, 1, 1, n);
    }

    ll query(int l, int r, int nod, int st, int dr)
    {
        if(l <= st && dr <= r)return sum[nod];
        push(nod);
        int m = (st + dr) >> 1;
        if(r <= m)return query(l, r, nod << 1, st, m);
        else if(l > m)return query(l, r, nod << 1 | 1, m + 1, dr);
        return query(l, r, nod << 1, st, m) + query(l, r, nod << 1 | 1, m + 1, dr);
    }
    ll query(int l, int r)
    {
        return query(l, r, 1, 1, n);
    }
};

int n, q, a[N];




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    Beats t(n, a);

    int op, l, r, b;
    for(int i = 1; i <= q; ++i)
    {
        cin >> op;

        if(op == 0)
        {
            cin >> l >> r >> b;
            ++ l;
            t.update_min(l, r, b);
        }
        else if(op == 1)
        {
            cin >> l >> r >> b;
            ++ l;
            t.update_max(l, r, b);
        }
        else if(op == 2)
        {
            cin >> l >> r >> b;
            ++ l;
            t.update_add(l, r, b);
        }
        else if(op == 3)
        {
            cin >> l >> r;
            ++ l;
            cout << t.query(l, r) << '\n';
        }
    }
    return 0;
}
