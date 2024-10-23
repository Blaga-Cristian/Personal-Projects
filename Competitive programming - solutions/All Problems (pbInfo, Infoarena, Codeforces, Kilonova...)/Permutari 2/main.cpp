#include <iostream>
#include <queue>
using namespace std;
vector<int>  v;
int a,b;
void functie(int x)
{
    for(int i=1;i<=x;i++)
    {
        cout<<i<<" ";
        //functie1(x-1,i);
        cout<<endl;
    }
}
void scrie()
{
    vector<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++)cout<<*itr+a-1<<" ";
    cout<<endl;
}
bool check(int a)
{
    vector<int>::iterator itr;
    for(itr=v.begin();itr!=v.end();itr++)if(*itr==a)return false;
    return true;
}
void functie1(int x)
{
    if(v.size()<x)
    {
        for(int i=1;i<=x;i++)
        {
            if(check(i))
            {
                v.push_back(i);
                if(v.size()==x)scrie();
                functie1(x);
                v.pop_back();
            }
        }
    }
}
int main()
{
    cin>>a>>b;
    functie1(b-a+1);
    return 0;
}
