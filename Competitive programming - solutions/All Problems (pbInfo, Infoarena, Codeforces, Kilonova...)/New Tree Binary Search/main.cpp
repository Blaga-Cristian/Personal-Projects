#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
using namespace std;
const string TASK("impiedicat");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 2e5 + 9, LG = 21;

int n, q, d[N];

int tree[4 * N];bool is_leaf[4 * N];
void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        is_leaf[nod] = true;
        tree[nod] = d[st];
        return;
    }
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
    tree[nod] = max(tree[nod << 1], tree[nod << 1 | 1]);
}

int Get_Node(int p, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)return nod;
    int m = (st + dr) >> 1;
    if(p <= m)return Get_Node(p, nod << 1, st, m);
    return Get_Node(p, nod << 1 | 1, m + 1, dr);
}

int Search(int v, int nod)
{
    if(is_leaf[nod])return tree[nod];
    if(tree[nod << 1] >= v)return Search(v, nod << 1);
    return Search(v, nod << 1 | 1);
}

int Query_Cb(int l, int r, int v)
{
    int nod = Get_Node(l);
    if(tree[nod] >= v)return nod;
    while(nod)
    {
        if(!(nod & 1) && tree[nod | 1] >= v)return Search(v, nod | 1);
        nod >>= 1;
    }
    return -1;
}


int main()
{
    cin >> n;
    FOR(i, 1, n)cin >> d[i];
    Build();

    ///intre l...r primul element mai mare sau egal cu unul dat
    int l, r, v;
    while(true)
    {
        cin >> l >> r >> v;
        cout << Query_Cb(l, r, v) << '\n';
    }
    return 0;
}
