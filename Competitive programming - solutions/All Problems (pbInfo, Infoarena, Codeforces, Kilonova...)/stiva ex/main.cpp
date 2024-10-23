#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
int n;
vector<int>v;
deque<int> stiva;
int main()
{
    int nr;
    int x;
    cin>>n;
    v=vector<int>(n+1,0);
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        stiva.push_back(x);
        v[x]=n-i+1;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(v[x]>stiva.size())cout<<0<<' ';
        else
        {
            int val = stiva.size()-v[x]+1;
            cout<<val<<' ';
            for(int j=0;j<val;++j)stiva.pop_front();
        }
    }
    return 0;
}
