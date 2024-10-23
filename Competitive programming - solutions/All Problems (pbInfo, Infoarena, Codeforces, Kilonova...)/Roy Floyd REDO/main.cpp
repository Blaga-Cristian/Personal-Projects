#include <bits/stdc++.h>
#define F first
#define S second
#define PI pair<int, int>
#define VI vector<int>
#define VVI vector<VI>
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;
const int N = 109, Inf = 0x3f3f3f3f;

int n, mat[N][N];

int main()
{
    freopen("royfloyd.in", "r", stdin);
    freopen("royfloyd.out", "w", stdout);

    cin >> n;

    REP(i, 1, n)
        REP(j, 1, n)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 0 && i != j)mat[i][j] = Inf;
        }

    REP(k, 1, n)
        if(k % 2 == 1)
        REP(i, 1, n)
            REP(j, 1, n)
                if(i != j)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    REP(k, 1, n)
        if(k % 2 == 0)
        REP(i, 1, n)
            REP(j, 1, n)
                if(i != j)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    REP(i, 1, n)
        REP(j, 1, n)
            if(mat[i][j] != Inf)
                cout << mat[i][j] << " \n"[j == n];
            else cout << "0 \n"[1 + (j == n)];
    return 0;
}
