#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define pb push_back
#define EPS 0.0000001

using namespace std;
const string TASK("gauss");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 309;

int n, m;
long double a[N][N], x[N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m + 1; ++j)
            cin >> a[i][j];

    for(int i = 1, j = 1, k; i <= n && j <= m;)
    {

        for(k = i; k <= n; ++k)
            if(a[k][j] < -EPS || a[k][j] > EPS)
                break;

        if(k == n + 1)
        {
            ++ j;
            continue;
        }

        if(k != i)
            for(int l = 1; l <= m + 1; ++l)
                swap(a[i][l], a[k][l]);


        for(int l = j + 1; l <= m + 1; ++l)
            a[i][l] /= a[i][j];
        a[i][j] = 1;

        for(int u = i + 1; u <= n; ++ u)
        {
            for(int l = j + 1; l <= m + 1; ++l)
                a[u][l] -= a[u][j] * a[i][l];
            a[u][j] = 0;
        }

        ++ i; ++ j;
    }

    for(int i = n; i >= 1; --i)
        for(int j = 1; j <= m + 1; ++j)
            if(a[i][j] < -EPS || a[i][j] > EPS)
            {
                if(j == m + 1)
                {
                    cout << "Imposibil\n";
                    return 0;
                }

                x[j] = a[i][m + 1];
                for(int k = j + 1; k <= m; ++k)
                    x[j] -= x[k] * a[i][k];

                break;
            }

    cout << fixed << setprecision(12);

    for(int i = 1; i <= m; ++i)cout << x[i] << '\n';
    cout << '\n';
    return 0;
}