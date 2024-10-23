#include <bits/stdc++.h>

using namespace std;

void b2(int x)
{
    if(x == 0)return;
    b2(x >> 1);
    cout << (x & 1);
}

int main()
{
    int a[100];
    fill_n(a, sizeof(a) / sizeof(int), (1LL << 31) - 1);


    for(int i = 1; i <= 99; ++i, cout << '\n')cout << a[i];
    return 0;
}
