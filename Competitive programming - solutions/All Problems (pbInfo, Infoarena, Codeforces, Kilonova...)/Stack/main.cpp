#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;
stack<int> stiva;
queue<int> q;
int main()
{
    int n;
    char  str[266];
    cin>>n;
    cin.get();
    for(int  i=0 ;i<n;++i)
    {
        cin.get(str,255);
        cin.get();
        if(str[0]=='p')
        {
            if(str[1]=='o')stiva.pop();
            else stiva.push(atoi(str+4));
        }
        else q.push(stiva.top());
    }
    while(!q.empty())cout<<q.front()<<'\n',q.pop();
    return 0;
}
