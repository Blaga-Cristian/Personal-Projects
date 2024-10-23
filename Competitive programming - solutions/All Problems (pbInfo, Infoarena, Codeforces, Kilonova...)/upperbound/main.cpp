#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,v[100];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    cout<< upper_bound(v+1,v+n+1,13) - v;
    return 0;
}
