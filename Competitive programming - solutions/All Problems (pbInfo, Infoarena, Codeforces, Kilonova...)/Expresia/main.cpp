#include <bits/stdc++.h>
#define pi pair<int,int>
#define F first
#define S second
using namespace std;

const int Nmax = 1009;
const int Kmax = 109;
const int Pmax = 20;

int n,k;
char str[Nmax];
int dp[Nmax][2 * Kmax][Pmax];
int prod[Nmax][Nmax];

/// dp[n][k][p] = valoarea maxima a unei expresii cu elementele din 1...n
/// care folosaste k operatii de schimbare si foloseste p operatori '*'

void Get_Prod()
{
    prod[0][0] = 1;
    for(int i = 2; i < strlen(str); i += 2)
        for(int len = 1; i - len + 1 >= 0; len += 2)
        {
            if(len == 1)prod[i][len] = str[i] - '0';
            else prod[i][len] = prod[i - 2][len - 2] * (str[i] - '0');
        }
    prod[0][0] = 0;
}

int main()
{
    freopen("expresia.in", "r", stdin);
    freopen("expresia.out", "w", stdout);

    cin >> n >> k >> str;


    int cntP = 0;
    for(int i = 0; i < strlen(str); ++i)
        if(str[i] == '*')
            ++cntP;

    Get_Prod();

    dp[0][0][0] = str[0] - '0';
    for(int i = 1; i < strlen(str); ++i)
    {
        if(str[i - 1] != '*' || str[i - 1] != '+')continue;


        for(int j = 0; j <= k; ++j)
            for(int p = 0; p <= cntP; ++p)
        {
            int w = 0, prod = str[i] - '0';
            for(int len = 1; i - len + 1 > 0; len += 2)
            {
                w += (str[i - len + 2] != '*');
                prod *= (str[i - len + 1] - '0');
                dp[i][j][p] = max(dp[i][j][p], dp[i - len])
            }
        }
    }
    return 0;
}
