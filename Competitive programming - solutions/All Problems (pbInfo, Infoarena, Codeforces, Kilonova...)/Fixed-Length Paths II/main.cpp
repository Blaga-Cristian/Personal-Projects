#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
const int N = 2e5 + 9, LG = 20;

int n, m, a, b, subtree[N], sz, t[N], cnt[N]{1}, dep[N], kmin, kmax, mx_depth;
ll ans;
bool processed[N];
VVI G;
int aib[N];
void Update(int poz, int val = 1)
{
    for(; poz <= n; poz += poz & -poz)
        aib[poz] += val;
}
int Query(int poz)
{
    int ret = 0;
    for(; poz; poz -= poz & -poz)
        ret += aib[poz];
    return ret;
}
int Query(int a, int b)
{
    if(a <= 0)return Query(b);
    return Query(b) - Query(a - 1);
}


int get_subtree_sizes(int node, int parent = 0) {
	subtree[node] = 1;
	for (int i : G[node])
		if (!processed[i] && i != parent)
			subtree[node] += get_subtree_sizes(i, node);
	return subtree[node];
}

int get_centroid(int desired, int node, int parent = 0) {
	for (int i : G[node])
		if (!processed[i] && i != parent && subtree[i] >= desired)
			return get_centroid(desired, i, node);
	return node;
}

void get_cnt(int node, int parent, bool filling, int depth = 1) {
	if (depth > kmax) return;
	mx_depth = max(mx_depth, depth);
	if (filling) Update(depth);
	else ans += Query(kmin - depth, kmax - depth);
	for (int i : G[node])
		if (!processed[i] && i != parent) get_cnt(i, node, filling, depth + 1);
}

void centroid_decomp(int node = 1) {
    Update(0);
	int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
	processed[centroid] = true;
	mx_depth = 0;
//	for (int i : G[centroid])
//		if (!processed[i]) {
//			get_cnt(i, centroid, false);
//			get_cnt(i, centroid, true);
//		}
//	fill(aib, aib + mx_depth + 1, 0);
//	for (int i : G[centroid])
//		if (!processed[i]) centroid_decomp(i);
}


int main()
{
    //cin.tie(0)->sync_with_stdio(false);

    cin >> n >> kmin >> kmax;
    G = VVI(n + 1);
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }


    centroid_decomp();

    cout << ans;
    return 0;
}
