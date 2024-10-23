#include <iostream>
#include <vector>
using namespace std;
const int mod = 123457;
int knapsack[10007];
int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i==n/i)v.push_back(i);
            else v.push_back(i),v.push_back(n/i);
        }
    }
    knapsack[0] = 1;
    for(auto i : v)
    {
        for(int j = 0;j+i<=n;++j)
        {
            if(knapsack[j]!=0||j==0)
            {
                knapsack[j+i]+=knapsack[j];
            }
        }
    }

    cout<<knapsack[n];
    return 0;
}
