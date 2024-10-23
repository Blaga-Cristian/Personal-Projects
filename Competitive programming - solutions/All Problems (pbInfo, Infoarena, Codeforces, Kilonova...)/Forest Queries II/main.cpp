#include <iostream>

using namespace std;
const int N = 1009;

int n, m, mat[N][N], aib[N][N], op, x, y, x1, y1, x2, y2;
char s[N];

void Update(int x, int y, int val)
{
    for(int i = x; i <= n; i += i&-i)
        for(int j = y; j <= n; j += j&-j)
            aib[i][j] += val;
}
int Query(int x, int y)
{
    int ret = 0;
    for(int i = x; i; i -= i&-i)
        for(int j = y; j; j -= j&-j)
            ret += aib[i][j];
    return ret;
}


int main()
{
    cin >> n >> m;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s, N);
        cin.get();
        for(int j = 1; j <= n; ++j)
            if(s[j - 1] == '*')
        {
            mat[i][j] = 1;
            Update(i, j, 1);
        }
    }


    while(m --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;
            Update(x, y, 1 - 2 * mat[x][y]);
            mat[x][y] = 1 - mat[x][y];
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << Query(x2, y2) - Query(x2, y1 - 1) - Query(x1 - 1, y2) + Query(x1 - 1, y1 - 1) << '\n';
        }
    }


    return 0;
}
