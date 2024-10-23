#include <bits/stdc++.h>

using namespace std;
ifstream fin("no_pals.in");
ofstream fout("no_pals.out");
const int N = 1e5 + 9, MOD = 666013;

int n, nr, pal;

int main()
{
    fin >> n;

    fout << "0\n81\n";

    nr = 90;
    pal = 9;

    for(int i = 3; i <= n; ++i)
    {
        if(i & 1)pal = (pal * 10) % MOD;
        nr = (nr * 10) % MOD;

        fout << (nr - pal + MOD) % MOD << '\n';
    }
    return 0;
}
