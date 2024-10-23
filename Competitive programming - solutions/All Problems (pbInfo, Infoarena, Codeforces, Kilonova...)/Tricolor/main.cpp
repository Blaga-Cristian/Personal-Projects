#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

constexpr int maxn = 5e3 + 100, tmp_poz = maxn-1;

ifstream f("tricolor.in");
ofstream g("tricolor.out");
vector<int> vec[maxn] = {};
int n, best[maxn][maxn] = {}, nr[maxn] = {};

// best[i][j] = # max de inchise pentru subarb i si j deschise

void join_states(int t, int s){
    for(int i = 0; i <= nr[s] + nr[t]; ++i)
        best[tmp_poz][i] = -1e9;

    for(int i = 0; i <= nr[t]; ++i)
        for(int j = 0; j <= nr[s]; ++j)
            best[tmp_poz][i+j] = max(best[tmp_poz][i+j], best[t][i] + best[s][j] + i * j);

    nr[t] += nr[s];
    for(int i = 0; i <= nr[t]; ++i){
        best[t][i] = best[tmp_poz][i];
        best[tmp_poz][i] = 0; }
}


void dfs(int cur, int prev = -1){
    nr[cur] = 0;
    int for_1 = 0;

    for(auto next : vec[cur])
        if(next != prev){
            dfs(next, cur);

            int here = 0;
            for(int i = 1; i <= nr[next]; ++i)
                here = max(here, best[next][i] + i);
            for_1 += here;
            join_states(cur, next); }
    best[cur][1] = max(best[cur][1], for_1);
    if(nr[cur] == 0){
        nr[cur] = 1;
        best[cur][1] = 0; } }

void do_test(){
    f >> n;
    assert(1 <= n && n <= 5000);

    for(int i = 0, x, y; i < n-1; ++i){
        f >> x >> y;
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        vec[x].push_back(y);
        vec[y].push_back(x); }

    dfs(1, -1);

    int best_val = 0;
    for(int i = 1; i <= nr[1]; ++i)
        if(best[1][i] > best_val)
            best_val =  best[1][i];
    for(int i = 1; i <= n; ++i)
        vec[i].clear();
    g << best_val << endl; }

int main(){
    int t;
    f >> t;
    assert(1 <= t && t <= 10);
    while(t--) do_test();
    return 0;
}
