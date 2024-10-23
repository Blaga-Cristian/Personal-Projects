#include <iostream>

using namespace std;
const int N = 2 * 1e5 + 9;

int n, q, NEXT_FREE_INDEX;

struct node
{
    int data, t, l, r;

    node()
    {
        data = t = l = r = 0;
    }
};
node tree[10 * N];

void Build(int st, int dr)
{
    int id = ++NEXT_FREE_INDEX;

    if(st == dr)
    {
        cin >> tree[id].data;
        return id;
    }

    int mij = (st + dr) >> 1;
    tree[id].l = Build(st, mij);
    tree[id].r = Build(mij + 1, dr);
    tree[id].data = tree[tree[id].l].data + tree[tree[id].r] + data;

    return id;
}

void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {

    }
}


vector<int> roots;

int main()
{
    cin >> n >> q;
    roots.push_back(Build(1, n));

    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> k >> a >> x;
            Update(roots[k-1], 1, n, a, x);
        }
    }
    return 0;
}
