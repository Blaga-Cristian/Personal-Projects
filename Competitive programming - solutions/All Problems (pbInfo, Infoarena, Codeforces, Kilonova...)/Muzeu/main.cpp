#include <bits/stdc++.h>

using namespace std;

int fact[10];
void Precalc()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 10; ++i)
        fact[i] = fact[i - 1] * i;
}
int suma_cifre(int n)
{
    int ret = 0;
    for(; n; n /= 10)
        ret += fact[n%10];
    return ret;
}
bool baza(int n, int b)
{
    for(; n; n /= 10)
        if(n % 10 >= b)
            return false;
    return true;
}
bool palindrom(int n)
{
    int ogl = 0;
    for(int x = n; x; x /= 10)
        ogl = ogl * 10 + x % 10;

    for(; n; n /= 10, ogl /= 10)
        if(n % 10 != ogl % 10)
            return false;
    return true;
}
void dpalindrom(int a, int b)
{
    for(int i = a; i <= b; ++i)
    {
        int nr_cif = 0;
        for(; pow(10, nr_cif) <= i; nr_cif ++);
        if(palindrom((i % (int)pow(10, nr_cif - 2)) / 100))
            cout << i << '\n';
    }
}
bool check(int x)
{
    int sum = 0, lst = 0;
    for(int i = x; i != 0 ; i /= 10)
    {
        sum += i % 10;
        lst = i % 10;
    }
    if(sum == 2 * lst)return true;
    return false;
}
void numere(int n, const int* v, int& suma)
{
    suma = 0;

    for(int i = 0; i < n; ++i)
        if(check(v[i]))
            suma += v[i];
}
struct Point{double x, y;};
double distanta(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    Precalc();
    int suma = 0;
    int v[] = {125, 624, 44, 2110, 23};
    numere(5, v, suma);
    cout << suma;
    return 0;
}
