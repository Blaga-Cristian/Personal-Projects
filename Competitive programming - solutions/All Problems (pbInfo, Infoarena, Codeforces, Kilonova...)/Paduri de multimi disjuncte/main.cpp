#include <iostream>

using namespace std;

int t[10000],rang[10000];
int Radacina(int x)
{
    int rad = x,y;
    while(t[rad] != 0)rad = t[rad];
    while(y!=rad)
    {
        y = t[x];
        t[x] = rad;
        x = y;
    }
    return rad;
}
void Unire(int rx,int ry) // radacina lui x, respectiv y
{
    if(rx!=ry)
    {
        if(rang[rx] > rang[ry])
            t[ry] = rx;
        else
        {
            t[rx] = ry;
            if(rang[rx]==rang[ry])rang[ry]++;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
