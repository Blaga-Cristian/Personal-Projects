#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 500 + 9;
const ll Inf = LLONG_MAX >> 1;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;

ll mat[N][N];
int n, m, q, a, b, c;


int main()
{


    cin >> n >> m >> q;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            mat[i][j] = Inf;


    while(m --)
    {
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], 1LL * c);
        mat[b][a] = min(mat[b][a], 1LL * c);
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(i != j && mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j] = mat[i][k] + mat[k][j];

    while(q --)
    {
        cin >> a >> b;

        if(a == b)
            cout << "0\n";
        else if(mat[a][b] == Inf)
            cout << "-1\n";
        else
            cout << mat[a][b] << '\n';
    }
    return 0;
}
