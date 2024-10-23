#include <bits/stdc++.h>

using namespace std;
const int N = 5 * 1e5 + 9;
int n, a, b;
mt19937 mt;


struct Treap
{
    int data, priority, size;
    vector<Treap*> kids;


    Treap(int data);
};

void recalc(Treap *t)
{
    if(!t)return;
    t->size = 1;
    for(Treap* it : t->kids)if(it)t->size += it->size;
}

Treap::Treap(int data)
{
    kids = {0, 0};
    this->data = data;
    priority = mt();
    recalc(this);
}

int size(Treap* t)
{
    return t == NULL ? 0 : t->size;
}

vector<Treap*> split(Treap *t, int nrleft)
{
    if(!t)return {0, 0};
    if(size(t->kids[0]) >= nrleft)
    {
        vector<Treap*> res = split(t->kids[0], nrleft);
        t->kids[0] = res[1];
        recalc(t);
        return {res[0], t};
    }
    else
    {
        vector<Treap*> res = split(t->kids[1], nrleft - size(t->kids[0]) - 1);
        t->kids[1] = res[0];
        recalc(t);
        return {t, res[1]};
    }
    return {0, 0};
}

Treap* merge(Treap* l, Treap* r)
{
    if(!l)return r;
    if(!r)return l;

    if(l->priority < r->priority)
    {
        l->kids[1] = merge(l->kids[1], r);
        recalc(l);
        return l;
    }
    else
    {
        r->kids[0] = merge(l, r->kids[0]);
        recalc(r);
        return r;
    }
}

Treap* root;

void add(Treap *&t, Treap* it)
{
    if(!t)t = it;
    else if(t->data < it->data)
        add(t->kids[1], it);
    else
        add(t->kids[0], it);

    recalc(t);
}

Treap *v[N];

void inOrder(Treap* root)
{
    if(!root)return;
    inOrder(root->kids[0]);
    cout << root->data << ' ';
    inOrder(root->kids[1]);
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
        v[i] = new Treap(i);

    sort(v + 1, v + n + 1, [](Treap* a, Treap* b){return a->priority < b->priority;});

    for(int i = 1; i <= n; ++i)add(root, v[i]);

    for(int i = 1; i <= n; ++i)
    {
        cin >> a >> b;

        if(a >= b)continue;

        int len = min(b - a, n - b + 1);

        Treap *segl, *sega, *segm, *segb, *segr;
        auto aux1 = split(root, a - 1);
        segl = aux1[0];
        auto aux2 = split(aux1[1], len);
        sega = aux2[0];
        auto aux3 = split(aux2[1], b - a - len);
        segm = aux3[0];
        auto aux4 = split(aux3[1], len);
        segb = aux4[0];
        segr = aux4[1];

        swap(sega, segb);

        root = merge(segl, merge(sega, merge(segm, merge(segb, segr))));
    }

    inOrder(root);
    return 0;
}
