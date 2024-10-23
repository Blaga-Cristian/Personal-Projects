#include <iostream>
#include <stack>
#include <deque>
using namespace std;
deque<pair<int,int> > stiva;
int main()
{
    int n;
    pair<int,int>x;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        x.first=i;
        cin>>x.second;
        if(stiva.empty())stiva.push_back(x);
        else if(stiva.back().second>=x.second)stiva.push_back(x);
        else
        {
            while(!stiva.empty()&&stiva.().second<x.second)stiva.pop();
            stiva.push_back(x);
        }
    }
    cout<<stiva.size()<<'\n';
    while(!stiva.empty())cout<<stiva.front().first<<' ',stiva.pop_front();
    return 0;
}
