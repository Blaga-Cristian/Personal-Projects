#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int>v;
    unordered_set<int>::iterator p;
    int n,x,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(!v.insert(x).second)v.erase(x);
    }
    for(p=v.begin();p!=v.end();p++)
    {
        s^=*p;
    }
    printf("%d",s);
    return 0;
}
