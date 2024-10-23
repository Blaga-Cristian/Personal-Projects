#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+9;
int n,a,b,x,y;
vector<int> v,aux;
int main()
{
    cin>>n;
    v = aux = vector<int>(n);
    for(int i=0;i<n;++i)
        cin>>v[i],aux[i] = v[i];

    sort(aux.begin(),aux.end());
    aux.erase(unique(aux.begin(),aux.end()),aux.end());
    return 0;
}
