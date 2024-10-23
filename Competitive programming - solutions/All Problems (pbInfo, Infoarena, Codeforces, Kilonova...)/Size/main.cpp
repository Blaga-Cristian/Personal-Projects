#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<v.size();
    return 0;
}
