#include <bits/stdc++.h>
using namespace std;
int a[1001] , cnt = 0;
void vraja(int st , int dr)
{
    cnt++;
    int min = 10000000;
    for(int i = st ; i <= dr ; ++i)
        if(a[i] < min)
            min = a[i];
    for(int i = st ; i <= dr ; ++i)
        a[i]-=min;
    for(int i = st ; i <= dr ; ++i)
        if(a[i]>0)
        {
            int j = i;
            while(j < dr && a[j+1]>0)
                j++;
            vraja(i , j);
            i=j+1;
        }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    vraja(1 , n);
    cout << cnt;
    return 0;
}
