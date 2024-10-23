#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 9;

int q;

struct node
{
    int nr_el, nr_pop, val, ld;
    node *s, *l;

    node()
    {
        nr_el = val = ld = 0;
        s = l = 0;
    }
};

node *r[N];

node* Add(node* p, bool push = true, int x = -1)
{
    node* t = new node();
    t -> nr_el = p -> nr_el;
    t -> nr_pop = p -> nr_pop;
    if(push)t -> nr_el = p -> nr_el + 1;
    else t -> nr_pop = p -> nr_pop + 1;
    t -> val = x;

    t -> s = p;
    if(p -> ld == p -> l -> ld)
    {
        t -> ld = 2 * p -> ld + 1;
        t -> l = p -> l -> l;
    }
    else
    {
        t -> ld = 1;
        t -> l = p;
    }

    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;

    r[0] = new node();
    r[0] -> s = r[0] -> l = r[0];

    int op, t, x;
    for(int i = 1; i <= q; ++i)
    {
        cin >> op;

        if(op == 0)///add
        {
            cin >> t >> x;
            ++ t;

            r[i] = Add(r[t], true, x);
        }
        else///pop + show
        {
            cin >> t;
            ++ t;

            r[i] = Add(r[t], false);

            auto x = r[i];
            int el = r[i] -> nr_pop;
            for(; x -> s -> nr_el >= el;)
                if(x -> l -> nr_el >= el)
                    x = x -> l;
                else x = x -> s;

            cout << x -> val << '\n';
        }
    }
    return 0;
}
