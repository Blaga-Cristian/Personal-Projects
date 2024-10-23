#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int n, *p;
    cin >> n;
    p = new int[n];
    for(int i = 0 ; i < n ; i ++)
        cout << p[i]<<" ";
    return 0;
}
