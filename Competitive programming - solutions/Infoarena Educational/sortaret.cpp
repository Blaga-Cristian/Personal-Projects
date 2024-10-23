#include <fstream>
#include <vector>
using namespace std;
ifstream fi("sortaret.in");
ofstream fo("sortaret.out");
int n, m, s[50001], predecesori[50001], a, b, i, l;
vector<int> succesori[50001];
int main()
{
    fi >> n >> m;
    while (m--)
    {
        fi >> a >> b;
        succesori[a].push_back(b);
        predecesori[b]++;
    }
        for (i = 1; i <= n; i++)
            if (predecesori[i] == 0)
                s[++l] = i;
        for (i = 1; l < n; i++)
            for (auto es : succesori[s[i]])
            {
                predecesori[es]--;
                if (predecesori[es] == 0)
                    s[++l] = es;
            }
        for (i = 1; i <= n; i++)
            fo << s[i] << ' ';
        return 0;
}