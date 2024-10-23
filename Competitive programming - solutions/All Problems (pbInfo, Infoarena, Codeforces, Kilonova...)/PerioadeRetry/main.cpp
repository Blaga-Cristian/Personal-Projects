#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin("perioade.in");
ofstream fout("perioade.out");

const int N = 250009, Alf = 26;

int n, k, q, sp[Alf][N], op;
ll a, b, poz;

long long vec[560000];size_t sz;
char chratvec[560000];

char s[N], chr;


class AIB
{
private:
    vector<int> aib;
    int sz;
public:
    AIB()
    {}

    AIB(int sz) : aib(vector<int>(sz + 1)), sz(sz)
    {}

    void update(int poz, int val)
    {
        for(; poz <= sz; poz += poz & -poz)
            aib[poz] += val;
    }
    int query(int poz)
    {
        int ret = 0;
        for(; poz; poz -= poz & -poz)
            ret += aib[poz];
        return ret;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
AIB *bit[Alf];



ll val;
void GenVec(int bit, int max_poz)
{
    for(int i = 0; i <= max_poz; ++i)
    {
        val ^= (1LL << i);
        vec[++sz] = val;
        chratvec[sz] = s[(val - 1) % n + 1];
        if(bit < k)GenVec(bit + 1, i - 1);
        val ^= (1LL << i);
    }
}
void Precalc()
{
    for(int i = 1; i <= n; ++i)
        for(int k = 0; k < Alf; ++k)
            sp[i][k] = sp[i - 1][k] + (s[i] - 'a' == k);

    GenVec(1, 60);

    for(int i = 0; i < Alf; ++i)
        bit[i] = new AIB(sz);
}
ll get_sum(ll poz, int tip)
{
    return 1LL * (poz / n) * sp[n][tip] + sp[poz % n][tip];
}
ll get_sum(ll l, ll r, int tip)
{
    return get_sum(r, tip) - get_sum(l - 1, tip);
}

int main()
{
    fin >> n >> k;
    fin.get();
    fin.get(s + 1, N);

    Precalc();

    fin >> q;
    while(q --)
    {
        fin >> op;
        if(op == 1)
        {
            fin >> poz >> chr;
            int idx = lower_bound(vec + 1, vec + sz + 1, poz) - vec;
            //cout << idx << '\n';
            bit[chratvec[idx] - 'a']->update(idx, -1);
            chratvec[idx] = chr;
            bit[chratvec[idx] - 'a']->update(idx, +1);
        }
        else
        {
            fin >> a >> b >> chr;
            int idxa = lower_bound(vec + 1, vec + sz + 1, a) - vec;
            int idxb = lower_bound(vec + 1, vec + sz + 1, b) - vec;
            fout << get_sum(a, b, chr - 'a') + bit[chr - 'a']->query(idxa, idxb) << '\n';
        }
    }
    return 0;
}
