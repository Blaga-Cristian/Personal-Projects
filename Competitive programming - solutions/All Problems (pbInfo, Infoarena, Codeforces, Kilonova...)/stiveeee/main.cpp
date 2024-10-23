#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int>a,b;
vector<pair<int,int> > v;
void afisare(int x)
{
    if(x==1)cout<<'A';
    else if(x==2)cout<<'B';
    else cout<<'C';
}
int main()
{
    int nr=1,n,x;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        a.push(x);
    }
    while(!a.empty()||!b.empty())
    {
        if(!b.empty()&&b.top()==nr)
            b.pop(),nr++,v.push_back({2,3});
        else
        {
            while(!a.empty()&&a.top()!=nr)
            {
                if(!b.empty()&&a.top()>=b.top())break;
                b.push(a.top());
                a.pop();
                v.push_back({1,2});
            }
            if(a.top()!=nr)break;
            else
            {
                a.pop();
                nr++;
                v.push_back({1,3});
            }
        }
    }
    if(!a.empty()||!b.empty())
    {
        cout<<0;
        return 0;
    }
    cout<<v.size()<<'\n';
    for(auto i:v)
    {
        afisare(i.first);
        cout<<' ';
        afisare(i.second);
        cout<<'\n';
    }
    return 0;
}
